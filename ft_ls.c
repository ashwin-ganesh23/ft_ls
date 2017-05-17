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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	size_t			l;

	l = len;
	a = b;
	while (l > 0)
	{
		*a = (unsigned char)c;
		a++;
		l--;
	}
	return (b);
}

char	*ft_strnew(size_t size)
{
	char *a;

	if ((a = malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	ft_memset(a, '\0', size + 1);
	return (a);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int x;

	x = 0;
	while (src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		strsize;
	int		a;
	char	*final;

	a = 0;
	strsize = ft_strlen(s1) + 1;
	if (!(final = (char*)malloc(sizeof(char) * strsize)))
		return (NULL);
	while (a < strsize)
	{
		final[a] = s1[a];
		a++;
	}
	final[a] = '\0';
	return (final);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if ((s3 = ft_strnew(size)) == NULL)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcpy(s3 + ft_strlen(s1), s2);
	return (s3);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return ((ft_strcmp((char *)s1, (char *)s2) == 0) ? 1 : 0);
	else
		return (1);
}

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
