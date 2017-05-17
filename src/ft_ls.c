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

// int		check_date()
// {
//
// }

// void 	put_time(t_node *t)
// {
// 	char			mtime[100];
//
// 	ft_strcpy(mtime, ctime(&t->buf.st_mtime));
// 	printf("st_mtime = %s\n", mtime);
// 	//if (check_date())
// }

void 	opendirectory(char *path, t_list *master)
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		tbuf;
	char			*newpath;
	t_list 			*tmp;
	t_node			*t;
	char			mtime[100];

	if ((dir = opendir(path)) != NULL)
	{
		if ((sd = readdir(dir)) != 0)
		{
			master->tail = new_nodelst(sd);
			master->head = master->tail;
		}
		while ((sd = readdir(dir)) != NULL)
			insert_node(master->head, master, sd);
		//printf("%s\n", master->head->sd->d_name);
		master->head = merge_sort(master->head);
		t = master->head;
		while (t->next != NULL)
		{
			newpath = ft_strjoin(path, "/");
			newpath = ft_strjoin(newpath, master->head->sd->d_name);
			if (stat(newpath, &t->buf) == -1)
				exit(EXIT_FAILURE);
			tbuf = t->buf;
			printf("%s   ", t->sd->d_name);
			get_usergroup(t);
			// put_time(t);
			ft_strcpy(mtime, ctime(&tbuf.st_mtime));

			printf("st_mtime = %s\n", mtime);
			// printf("%s\n", t->pd->pw_name);
			// printf("%s\n", t->grp->gr_name);
			printf("st_mode = %lo\n", (unsigned long) tbuf.st_mode);
			//printf("Ownership:UID=%ld   GID=%ld\n", (long)t->buf.st_uid, (long) t->buf.st_gid);
			//printf("%ld\n", (long)t->buf.st_nlink);
			t = t->next;
		}
		printf("%s   ", t->sd->d_name);

		// while (master->head->next)
		// {
		// 	newpath = ft_strjoin(path, "/");
		// 	newpath = ft_strjoin(newpath, master->head->sd->d_name);
		// 	if (isdir(newpath) && !ft_strequ(sd->d_name, ".") && !ft_strequ(sd->d_name, ".."))
		// 	{
		// 		tmp = new_lst();
		// 		printf("\n%s:\n", newpath);
		// 		opendirectory(newpath, tmp);
		// 		free(newpath);
		// 	}
		// 	else
		// 		printf("%s\n", sd->d_name);
		// 	master->head = master->head->next;
		// }
		closedir(dir);
	}
}

int		main(int argc, char **argv)
{
	t_list master;

	if (argc < 2)
		return (0);
	readflags(argc, argv, &master);
	printf("%s\n", master.flags);
	opendirectory(".", &master);
	return (0);
}

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
