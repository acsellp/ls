#include "ls.h"

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

int	main(int ac, char **av)
{
	struct stat *buff;
	time_t		tm;
	
	buff = (struct stat*)malloc(sizeof(struct stat));
	if (stat(av[1], buff) == -1)
		ft_printf("Error\n");
	else
	{
		ft_printf("device %d\n",buff->st_dev);
		ft_printf("inode number %d\n",buff->st_ino);
		file_type(buff->st_mode & S_IFMT);
		ft_printf("number of links %d\n",buff->st_nlink);
		ft_printf("user ID %d\n",buff->st_uid);
		ft_printf("group ID %d\n",buff->st_gid);
		ft_printf("device ID %d\n",buff->st_rdev);
		ft_printf("total size %d\n",buff->st_size);
		ft_printf("block size %d\n",buff->st_blksize);
		ft_printf("number of blocks %d\n",buff->st_blocks);
		ft_printf("time of last acces %s",ctime(&buff->st_atime));
		ft_printf("time of last modification %s",ctime(&buff->st_mtime));
		ft_printf("time of last status charnge %s",ctime(&buff->st_ctime));
	}
	time(&tm);
	ft_printf("\nCURRENT TIME %s\n",ctime(&tm));
	free(buff);
	(void)ac;
	(void)av;
	return (1);
}