/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:19:12 by aganesh           #+#    #+#             */
/*   Updated: 2017/02/16 22:19:15 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void 	get_usergroup(t_node *t)
{
	// char	*buf;
	// size_t	bufsize;
	// int		s;
	//
	// bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
	// if (bufsize == -1)
	// 	bufsize = 16384;
	// if ((buf = malloc(bufsize)) == NULL)
	// {
	// 	perror("malloc");
	// 	exit(EXIT_FAILURE);
	// }
	t->pd = getpwuid(t->buf.st_uid);
	t->grp = getgrgid(t->buf.st_gid);
}

char	*put_permissions(t_node *t)
{
	int		tmp;

	tmp = t->buf.st_mode %
	t->buf.st_mode
}

void 	get_filemode(t_node *t)
{
	t->filemode = ft_strnew(10);
	if (S_ISREG(t->buf.st_mode))
		t->filemode[0] = '-';
	else if (S_ISDIR(t->buf.st_mode))
		t->filemode[0] = 'd';
	else if (S_ISCHR(t->buf.st_mode))
		t->filemode[0] = 'c';
	else if (S_ISBLK(t->buf.st_mode))
		t->filemode[0] = 'b';
	else if (S_ISFIFO(t->buf.st_mode))
		t->filemode[0] = 'p';
	else if (S_ISLNK(t->buf.st_mode))
		t->filemode[0] = 'l';
	else if (S_ISSOCK(t->buf.st_mode))
		t->filemode[0] = 's';

	ft_strncat(t->filemode, put_permissions(t));
}
