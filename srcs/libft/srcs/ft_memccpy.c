/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:37:40 by dplesca           #+#    #+#             */
/*   Updated: 2016/10/07 18:59:38 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*sdest;
	unsigned char	*ssrc;

	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	x = 0;
	while (x < n)
	{
		sdest[x] = ssrc[x];
		if (ssrc[x] == (unsigned char)c)
		{
			x++;
			return ((sdest + x));
		}
		x++;
	}
	return (NULL);
}
