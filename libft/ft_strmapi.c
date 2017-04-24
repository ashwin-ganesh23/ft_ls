/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:27:50 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/29 18:27:51 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if ((fstr = ft_strnew(ft_strlen(s))) == 0)
		return (NULL);
	i = 0;
	while (*s)
	{
		fstr[i] = (*f)(i, *s++);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
