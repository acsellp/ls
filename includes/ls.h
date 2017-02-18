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
	long			block_sz;
	time_t			mod;
	long			gid;
	long			uid;
	long			ino;
	int				nlink;
}					t_props;
typedef	struct		s_paths
{
	unsigned char	back;
	char			*p;
	t_flags			flags;
	t_props			props;
	struct s_paths	*next;
}					t_paths;


/*
**	get_info.c
*/
void	get_stat(char *dir);
void	get_time();
void	get_pwuid(uid_t uid);
void	get_grgid(gid_t gid);
void	get_listxattr(char *dir);
/*
**	main.c
*/

void	check_flags(char **av, int ac, t_flags *flags);
void	print_error(char *error);
void	print_usage();
void	init_flags(t_flags *flags);
void	del_path(t_paths **pths);
void	add_path(t_paths **paths, char *dir, char *p);

#endif