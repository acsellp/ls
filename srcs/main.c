#include "ls.h"

void	print_usage()
{
	ft_printf("Usage : <...>\n");
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

void	file_type(mode_t mode)
{
	if (mode == S_IFREG)
		ft_printf("REGULAR FILE\n");
	if (mode == S_IFDIR)
		ft_printf("DIRECTORY\n");
	if (mode == S_IFCHR)
		ft_printf("CHARACTER DEVICE\n");
	if (mode == S_IFBLK)
		ft_printf("BLOCK DEVICE\n");
	if (mode == S_IFIFO)
		ft_printf("FIFO pipe\n");
	if (mode == S_IFLNK)
		ft_printf("LINK\n");
	if (mode == S_IFSOCK)
		ft_printf("SOCKET\n");
}


void	init_flags(t_flags *flags)
{
	flags->R = 0;
	flags->r = 0;
	flags->l = 0;
	flags->t = 0;
	flags->a = 0;
}

int	main(int ac, char **av)
{
	t_flags			flags;
	struct stat		*buff;
	struct passwd	*pwd;
	struct group	*grp;
	struct dirent	*dent;
	time_t			tm;
	char			*list;
	ssize_t			size;
	DIR				*dir;
	
	init_flags(&flags);
	check_flags(av, ac, &flags);
	
	if (!(dir = opendir(".")))
		perror("\n\nopendir");
	else
	{
		errno = 0;
		if (!(dent = readdir(dir)))
			perror("readdir");
		else
		{
			ft_printf("\n Node number : %u",dent->d_ino);
			ft_printf("\n Cuttent position : %u",dent->d_off);
			ft_printf("\n Length of the record : %u",dent->d_reclen);
			ft_printf("\n Type of file : %u",dent->d_type);
			ft_printf("\n file name : %s\n",dent->d_name);
		}
	}
	
	
	buff = (struct stat*)malloc(sizeof(struct stat));
	ft_printf("\nSTAT()\n");
	if (stat(".", buff) == -1)
		perror("stat");
	else
	{
		ft_printf("device %d\n",buff->st_dev);
		ft_printf("inode number %ld\n",(long)buff->st_ino);
		file_type(buff->st_mode & S_IFMT);
		ft_printf("number of links %d\n",buff->st_nlink);
		ft_printf("user ID %ld\n",(long)buff->st_uid);
		ft_printf("group ID %ld\n",(long)buff->st_gid);
		ft_printf("device ID %d\n",buff->st_rdev);
		ft_printf("total size %lld\n",(long long)buff->st_size);
		ft_printf("block size %ld\n",(long)buff->st_blksize);
		ft_printf("number of blocks %lld\n",(long long)buff->st_blocks);
		ft_printf("time of last acces %s",ctime(&buff->st_atime));
		ft_printf("time of last modification %s",ctime(&buff->st_mtime));
		ft_printf("time of last status charnge %s",ctime(&buff->st_ctime));
	}
	
	
	ft_printf("\nTIME()\n");
	time(&tm);
	ft_printf("\nCURRENT TIME %s\n",ctime(&tm));
	//perror("time");
	
	
	
	ft_printf("\nGETPWUID()\n");
	pwd = getpwuid(buff->st_uid);
	if (pwd)
	{
		ft_printf("\nName : %s", pwd->pw_name);
		ft_printf("\nPassword : %s", pwd->pw_passwd);
		ft_printf("\nUID : %d", pwd->pw_uid);
		ft_printf("\nGID : %d", pwd->pw_gid);
		ft_printf("\nUser information : %s",pwd->pw_gecos);
		ft_printf("\nHome directory : %s",pwd->pw_dir);
		ft_printf("\nShell program : %s\n\n", pwd->pw_shell);
	}
	else
		perror("getpwuid");
	
	
	ft_printf("\nGETGRGID\n");
	grp = getgrgid(buff->st_gid);
	if (grp)
	{
		ft_printf("\nName : %s", grp->gr_name);
		ft_printf("\nPassword : %s", grp->gr_passwd);
		ft_printf("\nGID : %", grp->gr_gid);
		ft_printf("\nGoup members : %s", grp->gr_mem[0]);
	}
	else
		ft_printf("\ngetgrgid error \n");
	
	
	ft_printf("\nLISTXATTR\n");
	if ((size = listxattr(av[1], NULL, 0)) == -1)
		perror("listxattr");
	else if (size == 0)
		ft_printf("\nno atributes\n\n");
	else
	{
		list = (char*)malloc(sizeof(char) * size);
		if (listxattr(av[1], list, size) == -1)
			perror("listxattr");
		else
			ft_printf("\nLIST ATTR: %s\n\n",list);
		free(list);
	}

	
	free(buff);
	(void)ac;
	(void)av;
	return (1);
}























