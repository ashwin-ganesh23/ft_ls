/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:15:20 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/26 15:15:21 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*fdst;
	const unsigned char	*fsrc;
	unsigned char		fc;

	if (n)
	{
		fc = c;
		fdst = (unsigned char *)dst;
		fsrc = (const unsigned char *)src;
		while (n-- != 0)
		{
			if ((*fdst++ = *fsrc++) == fc)
				return (void *)(fdst);
		}
	}
	return (0);
}
