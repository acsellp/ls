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


#endif