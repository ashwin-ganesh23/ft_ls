/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 13:19:06 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/26 13:19:07 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*fsrc;
	char	*fdst;
	size_t	l;

	fsrc = (char *)src;
	fdst = (char *)dst;
	l = 0;
	while (l < n)
	{
		fdst[l] = fsrc[l];
		l++;
	}
	return (dst);
}
