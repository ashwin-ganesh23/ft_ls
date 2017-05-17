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

int 	checkflag(char c, t_list *test)
{
	int i;
	char *flags;

	flags = "lRart\0";
	i = 0;
	while (test->flags[i] != 0)
	{
		if (test->flags[i] == c)
			return (1);
		i++;
	}
	i = 0;
	while (flags[i] != 0)
	{
		if (flags[i++] == c)
			return (0);
	}
	return (1);
}

void 	readflags(int argc, char **argv, t_list *test)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 1;
	while (argc > i)
	{
		j = 1;
		while (argv[i][j] != 0 && argv[i][0] == '-')
		{
			if (!checkflag(argv[i][j], test))
			 	test->flags[k++] = argv[i][j];
			j++;
		}
		i++;
	}
}

int		isdir(char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	if (statbuf.st_mode & S_IFDIR)
		return (1);
	return (0);
}
