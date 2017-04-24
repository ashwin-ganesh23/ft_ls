/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked=_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:19:12 by aganesh           #+#    #+#             */
/*   Updated: 2017/02/16 22:19:15 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list 	*new_lst()
{
	t_list *list;

	if ((list = (t_list*)malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_node	*new_nodelst(struct dirent *dir)
{
	t_node *node;

	if ((node = (t_node*)malloc(sizeof(*node))) == NULL)
		return (NULL);
	node->next = NULL;
	if (dir != NULL)
	{
		if ((node->sd = (struct dirent*)malloc(sizeof(dir))) == NULL)
			return (NULL);
		node->sd = dir;
	}
	else
	{
		node->sd = NULL;
		//perror()
	}
	return (node);
}

int 	insert_node(t_node *m, t_list *master, struct dirent *dir)
{
	t_node *temp;

	if ((temp = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (0);
  	temp->sd = dir;
  	temp->next = NULL;
	temp->prev = NULL;
  	if (!m)
	 	m = temp;
  	else
  	{
		temp->next = m;
		m->prev = temp;
		master->head = temp;
	}
	temp->next = m;
	m = temp;
	return (1);
}
