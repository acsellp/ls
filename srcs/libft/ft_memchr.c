/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:16:47 by dplesca           #+#    #+#             */
/*   Updated: 2016/10/17 16:35:24 by YourUser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sd;
	size_t			i;

	if (!s)
		return (NULL);
	sd = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sd[i] == (unsigned char)c)
			return ((void *)sd + i);
		i++;
	}
	return (NULL);
}
