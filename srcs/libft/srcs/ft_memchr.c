/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:16:47 by dplesca           #+#    #+#             */
/*   Updated: 2016/10/07 18:59:25 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	char *sd;

	sd = (char *)s;
	while (n)
	{
		if (sd == '\0')
			return (NULL);
		if (*sd == c)
			return ((void *)sd);
		sd++;
		n--;
	}
	return ((void *)sd);
}
