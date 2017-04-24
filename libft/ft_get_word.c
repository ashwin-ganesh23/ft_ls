/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:29:39 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/10 13:29:40 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_word(char const *s, char c, int *i)
{
	int		j;
	int		start;
	int		end;
	char	*str;

	j = *i;
	while (s[j] == c)
		j++;
	start = j;
	while (s[j] != c && s[j] != '\0')
		j++;
	end = j;
	*i = j;
	str = ft_strnew(end - start);
	j = 0;
	while (start < end)
	{
		str[j] = s[start];
		start++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
