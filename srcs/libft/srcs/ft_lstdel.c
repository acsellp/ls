#include <libft.h>

void	ft_lstdel(t_list **alt, void (*del)(void *, size_t))
{
	t_list *n;

	while ((*alt)->next)
	{
		n = (*alt);
		(*alt) = (*alt)->next;
		ft_lstdelone(&n, del);
	}
}
