#include <libft.h>

t_list	*ft_lstnew(void const *c, size_t c_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!c)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(c_size);
		if (!new->content)
			return (NULL);
		ft_memcpy(new->content, c, c_size);
		new->content_size = c_size;
	}
	new->next = NULL;
	return (new);
}
