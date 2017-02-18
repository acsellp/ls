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

void	del_path(t_paths **pths)
{
	if (!*pths)
		return ;
	while (*pths && (*pths)->next)
		del_path(&(*pths)->next);
	free((*pths)->p);
	free(*pths);
	*pths = NULL;
}

void	add_path(t_paths **paths, char *dir, char *p)
{
	t_paths *pth;
    t_paths *new;
    size_t  sz;
	
    sz = ft_strlen(dir) + ft_strlen(p) + 2;
	pth = *paths;
	if (!pth)
	{
		*paths = (t_paths*)malloc(sizeof(t_paths));
		(*paths)->p = (char*)malloc(sizeof(char) * sz);
		ft_strcpy((*paths)->p, dir);
		ft_strcat((*paths)->p, "/");
		ft_strcat((*paths)->p, p);
		if (ft_strcmp(p, "..") == 0)
			(*paths)->back = 1;
		else
			(*paths)->back = 0;
		// -l opt
		(*paths)->next = NULL;
		return ;
	}
	// -t opt
	//while (pth->next && pth->prop->mod > mod)
	//	pth = pth->next;
	while (pth->next)
		pth = pth->next;
	new = (t_paths*)malloc(sizeof(t_paths));
	new->p = (char*)malloc(sizeof(char) * sz);
	ft_strcpy(new->p, dir);
	ft_strcat(new->p, "/");
	ft_strcat(new->p, p);
	if (ft_strcmp(p, "..") == 0)
		new->back = 1;
	else
		new->back = 0;
	// -l opt
	pth->next = new;
    new->next = NULL;
}

void listdir(char *name)
{
    DIR				*dir;
    struct dirent	*dent;
	t_paths			*paths;
	t_paths			*tmp;

	paths = NULL;
  	(!(dir = opendir(name))) ? print_error("opendir") : 0;
	ft_printf("%s:\n", name);
	
	while (1)
	{
		if ((dent = readdir(dir)))
		{
			// -a opt
			if (dent->d_name[0] != '?' /*|| flags->a*/)
			  ft_printf("%s\n", dent->d_name);
			
			if (dent->d_type == DT_DIR)
				add_path(&paths, name, dent->d_name);
			errno = 0;
		}
		else
		{
			(errno) ? print_error("readdir") : 0;
			break ;
		}
	}
	ft_printf("\n");
	// -r opt
	// output || reverse output
	
	// -R opt
	
	tmp = paths;
    while (tmp)
    {
		ft_printf("\n%s",tmp->p);
		get_stat(tmp->p);
		get_listxattr(tmp->p);
		//if (tmp->back == 0)
			//listdir(tmp->p);
        tmp = tmp->next;
    }
	closedir(dir);
	del_path(&paths);
    return ;
}

int	main(int ac, char **av)
{
	t_flags			flags;
	init_flags(&flags);
	check_flags(av, ac, &flags);
	listdir(".");
	return (1);
}
