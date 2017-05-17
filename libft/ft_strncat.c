/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:45:59 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/22 16:46:01 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*adest;
	const char	*asrc;

	if (n != 0)
	{
		adest = s1;
		asrc = s2;
		while (*adest != 0)
			adest++;
		while (n > 0)
		{
			if ((*adest = *asrc++) == 0)
				break ;
			adest++;
			n--;
		}
		*adest = 0;
	}
	return (s1);
}
