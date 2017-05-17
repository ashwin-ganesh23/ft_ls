/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:09:21 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/22 17:09:22 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	char	*str;
	// size_t	l;
	//
	// l = ft_strlen(s) - 1;
	str = (char *)0;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while ((a = *s) != 0)
	{
		if (c == a)
			str = (char *)s;
		s++;
	}
	return (str);
}
