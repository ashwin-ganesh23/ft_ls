/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:53:09 by aganesh           #+#    #+#             */
/*   Updated: 2017/02/16 22:53:11 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int	main(int argc, char **argv)
{
	struct stat buf;
	char mtime[100];

	stat("file.txt", &buf);

	printf("st_mode = %o\n", buf.st_mode);

	strcpy(mtime, ctime(&buf.st_mtime));

	printf("st_mtime = %s\n", mtime);

	return (0);
}
