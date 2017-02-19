#ifndef LS_H
# define LS_H

# include "../srcs/printf/includes/ft_printf.h"
# include "../srcs/libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>

typedef struct		s_flags
{
	unsigned char	R;
	unsigned char	r;
	unsigned char	l;
	unsigned char	a;
	unsigned char	t;
}					t_flags;
typedef	struct		s_props
{
	long long		size;
	long long		nblocks;
	long			blksize;
	time_t			mtime;
	long			gid;
	long			uid;
	int				nlink;
	char			*perm;
}					t_props;
typedef	struct		s_path
{
	unsigned char	next_dir;
	char			*dir;
	size_t			offs;
	t_props			props;
	struct s_path	*next;
}					t_path;
typedef struct		s_ls
{
	t_flags			*flags;
	t_path			*path;
}					t_ls;
/*
**	get_info.c
*/
void	get_stat(char *dir, t_path **pth, t_flags **flags);
char	*get_time(time_t *tm);
char	*get_pwuid(uid_t uid);
char	*get_grgid(gid_t gid);
void	get_listxattr(char *dir);
void	get_perm(t_path **pth, struct stat *stat);
/*
**	main.c
*/
void	check_flags(char **av, int ac, t_flags *flags);
void	print_error(char *error);
void	print_usage();
void	init_flags(t_flags *flags);
void	del_path(t_path **pths);
//void	add_path(t_path **paths, char *dir, struct dirent *dent, t_flags *f);

void	alpha_sort(t_path **head, t_path **new);
void	time_sort(t_path **head, t_path **new);

#endif