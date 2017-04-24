/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 22:13:30 by aganesh           #+#    #+#             */
/*   Updated: 2016/07/18 22:13:32 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *b;
	const char *l;

	if (!*little)
		return (char *)(big);
	while (*big)
	{
		b = big;
		l = little;
		while (*big && *l && *big == *l)
		{
			big++;
			l++;
		}
		if (!*l)
			return (char *)(b);
		big = b + 1;
	}
	return (NULL);
}
