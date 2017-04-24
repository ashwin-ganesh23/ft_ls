/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:57:04 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/04 14:57:05 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**final;
	int		size;
	int		x;
	int		i;

	size = ft_get_size(s, c);
	i = 0;
	x = 0;
	if ((final = (char**)malloc(sizeof(char*) * (size + 1))) == 0)
		return (NULL);
	while (i < size)
	{
		final[i] = ft_get_word(s, c, &x);
		i++;
	}
	final[i] = 0;
	return (final);
}
