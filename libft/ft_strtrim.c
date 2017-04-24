/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 13:36:59 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/01 13:37:00 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		x;
	int		start;

	x = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	if (i - start < 0 || *s == '\0')
	{
		if ((str = (char *)malloc(sizeof(char))) == 0)
			return (NULL);
		return (str);
	}
	if ((str = (char *)malloc(sizeof(char) * (i - start + 2))) == 0)
		return (NULL);
	while (start <= i)
		str[x++] = (char)s[start++];
	str[x] = '\0';
	return (str);
}
