/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:31:14 by aganesh           #+#    #+#             */
/*   Updated: 2017/02/06 17:03:59 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>

typedef struct	s_node
{
	struct dirent	*sd;
	struct stat		buf;
	struct group	grp;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_list	*child;
	int				isdir;
}				t_node;

typedef struct	s_list
{
	struct s_node	*head;
	struct s_node	*tail;
	char 			flags[5];
}				t_list;

#endif
