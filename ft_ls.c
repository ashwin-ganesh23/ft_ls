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

//node	*newlst()

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

int 	insert_node(t_node *master, struct dirent *dir)
{
	t_node *temp;

	if ((temp = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (0);
  	temp->sd = dir;
  	temp->next = NULL;
	temp->prev = NULL;
  	if (!master)
	 	master = temp;
  	else
  	{
		temp->next = master;
		master->prev = temp;
		master->head = temp;
	}
	temp->next = master;
	master = temp;
}

t_node	*merge_sort(t_node *head)
{
	t_node	*second;

	if (!head || !head->next)
        return (head);
    second = split(head);
    head = merge_sort(head);
    second = merge_sort(second);
    return (merge(head,second));
}

t_node	*merge(t_node *first, t_node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->sd->d_name < second->sd->d_name)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

t_node	*split(t_node *head)
{
    t_node	*fast;
	t_node	*slow;
	t_node	*temp;

	fast = head;
	slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = NULL;
    return (temp);
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

void 	opendirectory(char *path, t_list *master)
{
	DIR				*dir;
	struct dirent	*sd;
	char			*newpath;
	t_list 			*tmp;

	if ((dir = opendir(path)) != NULL)
	{
		if (sd = readdir(dir) != NULL)
		{
			master->tail = new_nodelst(sd);
			master->head = master->tail;
		}
		while ((sd = readdir(dir)) != NULL)
			master->head = insert_node(&master.head, sd);
		master->head = merge_sort(master->head);
		while (master->head->next)
		{
			newpath = ft_strjoin(path, "/");
			newpath = ft_strjoin(newpath, master->head->sd->d_name);
			if (isdir(newpath) && !ft_strequ(sd->d_name, ".") && !ft_strequ(sd->d_name, ".."))
			{
				tmp = new_lst();
				printf("\n%s:\n", newpath);
				opendirectory(newpath, tmp);
				free(newpath);
			}
			else
				printf("%s\n", sd->d_name);
			master->head = master->head->next;
		}
		closedir(dir);
	}
}

int		main(int argc, char **argv)
{
	t_list master;

	if (argc < 2)
		return (0);
	readflags(argc, argv, &master);
	//printf("%s\n", test.flags);
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
