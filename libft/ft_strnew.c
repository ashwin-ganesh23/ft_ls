/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:54:26 by aganesh           #+#    #+#             */
/*   Updated: 2016/09/29 14:54:26 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *a;

	if ((a = malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	ft_memset(a, '\0', size + 1);
	return (a);
}
