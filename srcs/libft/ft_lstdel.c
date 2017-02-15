#include <libft.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alt, void (*del)(void *, size_t))
{
	t_list *n;

	n = *alt;
	*alt = (*alt)->next;
	while (*alt)
	{
		ft_lstdelone(&n, del);
		n = *alt;	
		(*alt) = (*alt)->next;
	}
}
