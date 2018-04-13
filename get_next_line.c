/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:15:15 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/13 22:05:20 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lsts		*check_list(t_lsts *gnl, int fd)
{
	t_lsts *tmp;

	tmp = gnl;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!tmp)
		tmp = malloc(sizeof(t_lsts));
	tmp->k = 0;
	tmp->fd = fd;
	tmp->next = NULL;
	ft_strclr(tmp->buffer);
	while (gnl->next)
		gnl = gnl->next;
	gnl->next = tmp;
	return (tmp);
}

void		check_line(t_lsts *elem, char **line)
{
	char *mod;

	elem->n = ft_strchr(elem->buffer, '\n');
	if (elem->n != NULL)
		ft_memset(elem->n, '\0', 1);
	if ((*line) != NULL)
	{
		mod = ft_strdup((*line));
		free(*line);
		(*line) = ft_strjoin(mod, elem->buffer);
		free(mod);
		mod = NULL;
	}
	else
		(*line) = ft_strdup(elem->buffer);
	if (elem->n)
		ft_strncpy(elem->buffer, &elem->n[1], BUFF_SIZE + 1);
	else
		ft_strclr(elem->buffer);
}

int			write_list(t_lsts *elem, char **line)
{
	if ((elem->n = ft_strchr(elem->buffer, '\n')) != NULL)
	{
		check_line(elem, line);
		return (1);
	}
	(*line) = ft_strdup(elem->buffer);
	ft_strclr(elem->buffer);
	while ((elem->k = read(elem->fd, elem->buffer, BUFF_SIZE)) > 0)
	{
		check_line(elem, line);
		if (elem->n != NULL)
			break ;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_lsts	*gnl;
	t_lsts			*elem;

	if (fd >= 0 && line)
	{
		if (!gnl)
		{
			gnl = malloc(sizeof(t_lsts));
			gnl->fd = -1;
			gnl->next = NULL;
		}
		if (read(fd, gnl->buffer, 0) < 0)
			return (-1);
		*line = NULL;
		elem = check_list(gnl, fd);
		if (write_list(elem, line))
			return (1);
		if (elem->k == 0 && ft_strlen(*line) == 0)
			return (0);
		return ((elem->k == -1) ? -1 : 1);
	}
	return (-1);
}
