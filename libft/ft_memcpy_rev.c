/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:14:46 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/10 13:14:47 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t len)
{
	char	*fdst;
	char	*fsrc;

	fdst = (char *)dst;
	fsrc = (char *)src;
	while (len--)
		fdst[len] = fsrc[len];
	return (dst);
}
