/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 14:05:18 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/21 14:05:20 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			check_read(int const fd, char *buf, int *r)
{
	char			*c;

	if ((c = ft_strchr(buf, '\n')) == NULL)
		if ((*r = read(fd, buf, BUFF_SIZE)) > 0)
			return (1);
	return (0);
}

static int	get_next(int const fd, char *buf, char *stc[fd])
{
	char			*t;
	int				r;

	while (check_read(fd, buf, &r))
	{
		buf[r] = '\0';
		t = stc[fd];
		stc[fd] = ft_strjoin(t, buf);
		ft_strdel(&t);
	}
	ft_strdel(&buf);
	if (r == -1)
		return (-1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char		*stc[MAX_FD];
	char			*buf;
	char			*s;
	char			*t;
	int				r;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buf == NULL || BUFF_SIZE < 1)
		return (-1);
	if (stc[fd] == NULL)
		stc[fd] = ft_strnew(1);
	if ((r = get_next(fd, buf, stc)) == -1)
		return (-1);
	if ((s = ft_strchr(stc[fd], '\n')) != NULL)
	{
		*line = ft_strsub(stc[fd], 0, s - stc[fd]);
		t = stc[fd];
		stc[fd] = ft_strdup(s + 1);
		ft_strdel(&t);
		return (1);
	}
	*line = ft_strdup(stc[fd]);
	stc[fd] = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
