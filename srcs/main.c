#include "ls.h"

void	print_usage()
{
	ft_printf("Usage : <...>\n");
	exit(1);
}

void	print_error(char *error)
{
	perror(error);
	exit(1);
}

void	check_flags(char **av, int ac, t_flags *flags)
{
	int		i;
	int		x;
	
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			x = 1;
			while (av[i][x])
			{
				(av[i][x] == 'R') ? flags->R = 1 : \
				(av[i][x] == 'r') ? flags->r = 1 : \
				(av[i][x] == 'l') ? flags->l = 1 : \
				(av[i][x] == 'a') ? flags->a = 1 : \
				(av[i][x] == 't') ? flags->t = 1 : \
					print_usage();
				x++;
			}
		}
		else
			print_usage();
	}
}

void	init_flags(t_flags *flags)
{
	flags->R = 0;
	flags->r = 0;
	flags->l = 0;
	flags->t = 0;
	flags->a = 0;
}

void	print_path(t_ls *ls)
{
	t_path *path;
	
	path = ls->path;
	while (path)
	{
		ft_printf("%s - %lld\n",path->dir + path->offs, (long long)path->props.mtime);
		path = path->next;
	}
}

void	del_path(t_path **pths)
{
	if (!*pths)
		return ;
	while (*pths && (*pths)->next)
		del_path(&(*pths)->next);
	free((*pths)->props.perm);
	free((*pths)->dir);
	free(*pths);
	*pths = NULL;
}

t_path *new_node(struct dirent *dent, char *dir, t_flags *f)
{
	t_path *pth;
    size_t  sz;
	
	pth = (t_path*)malloc(sizeof(t_path));
	pth->offs = ft_strlen(dir) + 1;
    sz = pth->offs + ft_strlen(dent->d_name) + 1;
	pth->dir = (char*)malloc(sizeof(char) * sz);
	ft_strcpy(pth->dir, dir);
	ft_strcat(pth->dir, "/");
	ft_strcat(pth->dir, dent->d_name);
	if (f->R && ft_strcmp(dent->d_name, "..") && dent->d_type == DT_DIR)
		pth->next_dir = 1;
	else
		pth->next_dir = 0;
	pth->props.size = 0;
	pth->props.nblocks = 0;
	pth->props.blksize = 0;
	pth->props.mtime = 0;
	pth->props.uid = 0;
	pth->props.gid = 0;
	pth->props.nlink = 0;
	pth->props.perm = NULL;
	pth->next = NULL;
	return (pth);
}

void	add_path(t_ls *ls, char *dir, struct dirent *dent)
{
	t_path *pth;
	t_path *new;

	if (!ls->flags->a && dent->d_name[0] == '.') // -a opt
		return ;
	if (!ls->path)
	{
		ls->path = new_node(dent, dir, ls->flags);
		get_stat(ls->path->dir, &ls->path, &ls->flags);
		return ;
	}
	// -t opt
	pth = ls->path;
	new = new_node(dent, dir, ls->flags);
	get_stat(new->dir, &new, &ls->flags);
	if (ls->flags->t) // time sorting
		time_sort(&ls->path, &new);
	else // alphabethical sorting
		alpha_sort(&ls->path, &new);
}

void list_dir(char *name, t_ls *ls)
{
    DIR				*dir;
    struct dirent	*dent;
	t_path			*tmp;

  	(!(dir = opendir(name))) ? print_error("opendir") : 0;
	ls->path = NULL;
	while (1)
	{
		if ((dent = readdir(dir)))
		{
			add_path(ls, name, dent);
			errno = 0;
		}
		else
		{
			(errno) ? print_error("readdir") : 0;
			break ;
		}
	}
	closedir(dir);

	// -r opt
	// output || reverse output
	
	ft_printf("%s:\n\n", name);
	print_path(ls);
	
	if (ls->flags->R)// -R opt
	{
		tmp = ls->path;
		
		while (tmp)
		{
			//ft_printf("%s\n",tmp->dir + tmp->offs);
			//get_stat(tmp->p, tmp);
			if (tmp->next_dir)
				list_dir(tmp->dir, ls);
			tmp = tmp->next;
		}
	}
	
	del_path(&ls->path);
    return ;
}

int	main(int ac, char **av)
{
	t_ls *ls;
	
	ls = (t_ls*)malloc(sizeof(t_ls));
	ls->flags = (t_flags*)malloc(sizeof(t_flags));
	init_flags(ls->flags);
	check_flags(av, ac, ls->flags);
	list_dir(".", ls);
	free(ls->flags);
	free(ls);
	return (1);
}
