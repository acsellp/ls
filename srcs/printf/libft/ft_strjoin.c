
#include "libft.h"

char			*ft_strjoin(char const *f, char const *s)
{
	char	*ret;
	size_t	fsz;
	size_t	ssz;

	fsz = ft_strlen(f);
	ssz = ft_strlen(s);
	ret = malloc(sizeof(char) * (fsz + 1 + ssz));
	if (!ret)
		return (NULL);
	ft_strncpy(ret, f, fsz);
	ft_strcpy(ret + fsz, s);
	return (ret);
}