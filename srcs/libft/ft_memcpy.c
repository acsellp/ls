/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:39:49 by dplesca           #+#    #+#             */
/*   Updated: 2016/10/17 16:35:54 by YourUser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;

	ssrc = (unsigned char *)src;
	sdest = (unsigned char *)dest;
	while (n)
	{
		*sdest = *ssrc;
		ssrc++;
		sdest++;
		n--;
	}
	return (dest);
}
