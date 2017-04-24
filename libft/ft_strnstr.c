/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 16:41:00 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/24 16:41:01 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	int		j;
	size_t	l;

	j = 0;
	if (!*big)
		return (NULL);
	if ((l = ft_strlen(lil)) == 0)
		return (char *)(big);
	while (j <= (int)(len - l) && *big)
	{
		if ((*big == *lil) && !(ft_strncmp(big, lil, l)))
			return (char *)(big);
		big++;
		j++;
	}
	return (NULL);
}
