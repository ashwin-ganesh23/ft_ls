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

int 	checkflag(char c)
{
	int i;

	i = 0;
	while (flags[i] != NULL)
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void 	readflags(int argc, char **argcv)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 1;
	while (argc > i)
	{
		j = 1;
		while (argv[i][j] != NULL && argv[i][0] == '-')
		{
			if (!checkflag(argv[i][j]))
			 	flags[k++] = argv[i][j];
			j++;
		}
		i++;
	}
}

void 	opendirectory()
{
	DIR *dir;
	struct dirent *sd;

	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error! Unable to open directory.\n");
		exit(1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		//insert new node
		printf(">> %s\n", sd->d_name);
	}
	closedir(dir);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	readflags(argc, argv);
	opendirectory();


	// char *curr_dir;
	// DIR *dp;
	// struct dirent *dptr;
	// unsigned int count = 0;
	// struct stat sb;
	//
	// curr_dir = getenv("PWD");
	// if (lstat(curr_dir, &sb) == -1)
	// {
	// 	perror("lstat");
	// 	exit(EXIT_FAILURE);
	// }
	// if (NULL == curr_dir)
	// {
	// 	printf("Error\n");
	// }
	// if ((dp = opendir((const char*)curr_dir)) == NULL)
	// 	printf("Error\n");
	// while ((dptr = readdir(dp)) != NULL)
	// {
	// 	if (dptr->d_name[0] != '.')
	// 		printf("%s  ", dptr->d_name);
	// }
	return (0);
}
