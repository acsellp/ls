#include "ls.h"

void	get_stat(char *dir, t_path **pth, t_flags **flags)
{
	struct stat *buff;

	buff = (struct stat*)malloc(sizeof(struct stat));
	if (stat(dir, buff) == -1)
		perror("stat");
	else
	{
		if ((*flags)->l) // -l opt
		{
			(*pth)->props.nlink = buff->st_nlink;
	//		get_pwuid(buff->st_uid, pth);
			(*pth)->props.uid = buff->st_uid;
	//		get_grgid(buff->st_gid, pth);
			(*pth)->props.gid = buff->st_gid;
			(*pth)->props.size = buff->st_size;
			(*pth)->props.blksize = buff->st_blksize;
			(*pth)->props.nblocks = buff->st_blocks;
			get_perm(pth, buff);
		}
		(*pth)->props.mtime = buff->st_mtime;
		ft_printf("\n  %s   %lld\n",dir,buff->st_mtime);
	}
	free(buff);
}

char	*get_time(time_t *tm)
{
	time(tm);
	return (ctime(tm));
}

char	*get_pwuid(uid_t uid)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd)
		return (pwd->pw_name);
	else
		perror("getpwuid");
	return (NULL);
}

char	*get_grgid(gid_t gid)
{
	struct group	*grp;

	grp = getgrgid(gid);
	if (grp)
		return (grp->gr_name);
	else
		perror("getgrgid");
	return (NULL);
}

void	get_listxattr(char *dir)
{
	char	*list;
	ssize_t	size;

	//ft_printf("\nLISTXATTR\n");
	if ((size = listxattr(dir, NULL, 0,XATTR_SHOWCOMPRESSION)) == -1)
		perror("listxattr");
	else if (size == 0)
	{}//ft_printf("\nno atributes\n\n");
	else
	{
		list = (char*)malloc(sizeof(char) * size);
		if (listxattr(dir, list, size, 0) == -1)
			perror("listxattr");
		else
		{}//ft_printf("\nLIST ATTR: %s\n\n",list);
		free(list);
	}
}

void	get_perm(t_path **pth, struct stat *stat)
{
	size_t	i;
	
	i = 0;
	(*pth)->props.perm = (char*)malloc(sizeof(char) * 11);
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IFDIR) ? 'd' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IRUSR) ? 'r' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IWUSR) ? 'w' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IXUSR) ? 'x' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IRGRP) ? 'r' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IWGRP) ? 'w' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IXGRP) ? 'x' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IROTH) ? 'r' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IWOTH) ? 'w' : '-');
	(*pth)->props.perm[i++] = ((stat->st_mode & S_IXOTH) ? 'x' : '-');
	(*pth)->props.perm[i] = '\0';
}

void	alpha_sort(t_path **head, t_path **new)
{
	t_path *pth;
	t_path *prev;
	
	pth = *head;
	prev = pth;
	while (pth && ft_strcmp(pth->dir + pth->offs, (*new)->dir + (*new)->offs) <= 0)
	{
		prev = pth;
		pth = pth->next;
	}
	if (pth == *head)
	{
		(*new)->next = *head;
		*head = *new;
	}
	else
	{
		(*new)->next = pth;
		prev->next = *new;
	}
}

void	time_sort(t_path **head, t_path **new)
{
	t_path *pth;
	t_path *prev;
	
	pth = *head;
	prev = pth;
	while (pth && pth->props.mtime > (*new)->props.mtime)
	{
		prev = pth;
		pth = pth->next;
	}
	if (pth == *head)
		alpha_sort(head, new);
	else
		alpha_sort(&prev->next, new);
}