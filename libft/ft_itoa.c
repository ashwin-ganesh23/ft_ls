/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:09:00 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/01 14:09:02 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(long n)
{
	int s;

	s = 0;
	while (n != 0)
	{
		n = n / 10;
		s++;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		size;
	long	l;

	neg = 0;
	l = (long)n;
	if (n <= 0)
		neg = 1;
	if (neg)
		l *= -1;
	size = getsize(n) + neg;
	if (!(ret = ft_strnew(size)))
		return (NULL);
	size--;
	if (l == 0)
		ret[0] = '0';
	while (l != 0)
	{
		ret[size--] = (l % 10) + '0';
		l /= 10;
	}
	if (neg && ret[0] != '0')
		ret[0] = '-';
	return (ret);
}
