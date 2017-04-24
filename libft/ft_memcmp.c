/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:43:00 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/26 15:43:01 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char f1;
	unsigned char f2;

	while (n > 0)
	{
		f1 = *(unsigned char *)s1;
		f2 = *(unsigned char *)s2;
		if (f1 != f2)
			return (f1 - f2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
