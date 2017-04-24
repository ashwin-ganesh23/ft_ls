/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:50:16 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/22 16:50:17 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		x;
	size_t		destsize;
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	x = size;
	while (x-- != 0 && *d != '\0')
		d++;
	destsize = d - dst;
	x = size - destsize;
	if (x == 0)
		return (destsize + ft_strlen(src));
	while (*s != '\0')
	{
		if (x != 1)
		{
			*d++ = *s;
			x--;
		}
		s++;
	}
	*d = '\0';
	return (destsize + (s - src));
}
