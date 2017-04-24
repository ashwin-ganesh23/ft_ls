/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 13:17:18 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/05 13:17:20 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list*)malloc(sizeof(*node))) == NULL)
		return (NULL);
	node->next = NULL;
	if (content != NULL && content_size != 0)
	{
		if ((node->content = malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	else
	{
		node->content = NULL;
		node->content_size = 0;
	}
	return (node);
}
