/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:34:37 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/26 15:34:38 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *fc;
	unsigned char b;

	b = c;
	fc = (unsigned char *)s;
	while (n > 0)
	{
		if (*fc == b)
			return ((void *)fc);
		fc++;
		n--;
	}
	return ((void *)(NULL));
}
