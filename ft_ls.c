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

int		main(int argc, char **argv)
{
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	unsigned int count = 0;

	curr_dir = getenv("PWD");
	if (NULL == curr_dir)
	{
		printf("Error\n");
	}
	if ((dp = opendir((const char*)curr_dir)) == NULL)
		printf("Error\n");
	while ((dptr = readdir(dp)) != NULL)
	{
		if (dptr->d_name[0] != '.')
			printf("%s  ", dptr->d_name);
	}
	return (0);
}