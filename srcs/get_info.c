#include "ls.h"

void	get_stat(char *dir, t_path **pth, t_flags **flags)
{
	struct stat *buff;

	buff = (struct stat*)malloc(sizeof(struct stat));
	//ft_printf("\nSTAT()\n");
	if (stat(dir, buff) == -1)
		perror("stat");
	else
	{
		//ft_printf("		device %d\n",buff->st_dev);
		//ft_printf("		inode number %ld\n",(long)buff->st_ino);
		//file_type(buff->st_mode & S_IFMT);
		//ft_printf("		number of links %d\n",buff->st_nlink);
		(*pth)->props.nlink = buff->st_nlink;
		//ft_printf("		user ID %ld\n",(long)buff->st_uid);
//		get_pwuid(buff->st_uid, pth);
		(*pth)->props.uid = buff->st_uid;
		//ft_printf("		group ID %ld\n",(long)buff->st_gid);
//		get_grgid(buff->st_gid, pth);
		(*pth)->props.gid = buff->st_gid;
		//ft_printf("		device ID %d\n",buff->st_rdev);
		//ft_printf("		total size %lld\n",(long long)buff->st_size);
		(*pth)->props.size = buff->st_size;
		//ft_printf("		block size %ld\n",(long)buff->st_blksize);
		(*pth)->props.blksize = buff->st_blksize;
		//ft_printf("		number of blocks %lld\n",(long long)buff->st_blocks);
		(*pth)->props.nblocks = buff->st_blocks;
		//ft_printf("		time of last acces %lld - %s",(long long) buff->st_atime,ctime(&buff->st_atime));
		//ft_printf("		time of last modification %s",ctime(&buff->st_mtime));
		(*pth)->props.mtime = buff->st_mtime;
		//ft_printf("		time of last status charnge %s",ctime(&buff->st_ctime));
		get_perm(pth, buff);
	}
	free(buff);
}

void	get_time()
{
	time_t	tm;

	//ft_printf("\nTIME()\n");
	time(&tm);
	//ft_printf("\nCURRENT TIME %s\n",ctime(&tm));
}

void	get_pwuid(uid_t uid, t_path **pth)
{
	struct passwd	*pwd;

	//ft_printf("\nGETPWUID()\n");
	pwd = getpwuid(uid);
	if (pwd)
	{
		//ft_printf("\n			Name : %s", pwd->pw_name);
		
		//ft_printf("\n			Password : %s", pwd->pw_passwd);
		//ft_printf("\n			UID : %d", pwd->pw_uid);
		//ft_printf("\n			GID : %d", pwd->pw_gid);
		//ft_printf("\n			User information : %s",pwd->pw_gecos);
		//ft_printf("\n			Home directory : %s",pwd->pw_dir);
		//ft_printf("\n			Shell program : %s\n\n", pwd->pw_shell);
	}
	else
		perror("getpwuid");
	(void)pth;
}

void	get_grgid(gid_t gid, t_path **pth)
{
	struct group	*grp;

	//ft_printf("\nGETGRGID\n");
	grp = getgrgid(gid);
	if (grp)
	{
		//ft_printf("\n			Name : %s", grp->gr_name);
		
		//ft_printf("\n			Password : %s", grp->gr_passwd);
		//ft_printf("\n			GID : %", grp->gr_gid);
		//ft_printf("\n		Goup members : %s", grp->gr_mem[0]);
	}
	else
	{
		perror("getgrgid");
		ft_printf("\ngetgrgid error \n");
	}
	(void)pth;
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
	//ft_printf("\n		[%s]\n",(*pth)->props.perm);
}