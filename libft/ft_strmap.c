/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:02:05 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/29 16:02:06 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fstr;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((fstr = ft_strnew(ft_strlen(s))) == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fstr[i] = (*f)(s[i]);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
