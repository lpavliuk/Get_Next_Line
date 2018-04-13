/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:48:34 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/13 21:43:15 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_get_next_line.h"

void	check_list(t_list *gnl, int fd)
{
	t_list *tmp;

	if (gnl->content == NULL)
	{
		gnl->content = ft_strnew(BUFF_SIZE);
		gnl->content_size = -1;
	}
	tmp = gnl;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content = ft_strnew(BUFF_SIZE);
	tmp->content_size = fd;
	ft_lstadd(&gnl, tmp);
}

int		check_line(t_list *elem, char **line)
{
	char *n;

	if ((n = strchr(elem->content, '\n')) != NULL)
	{
		(*line) = ft_strsub(elem->content, 0, (BUFF_SIZE - ft_strlen(n + 1)));
		ft_strclr(elem->content);
		return (1);
	}
	(*line) = ft_strdup(elem->content);
	ft_strclr(elem->content);
	return (0);
}

void	check_content(t_list *elem, char **line)
{
	char *n;

	if ((n = ft_strchr(elem->content, '\n')) != NULL)
	{

		(*line) = ft_strsub(elem->content, 0, (BUFF_SIZE - ft_strlen(n + 1)));


int		get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	t_list			*elem;
	int				k;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	k = 0;
	if (!gnl)
	{
		gnl = ft_lstnew((*line), BUFF_SIZE);
		gnl->content = ft_strnew(BUFF_SIZE);
	}
	elem = check_list(gnl, fd);
	if (!check_line(elem, line))
	{
		while ((k = read(elem->content_size, elem->content, BUFF_SIZE)) > 0)
		{
			if (strchr(elem->content, '\n') != NULL)
				break;
			check_content(elem, line);
		}
		check_content(elem, line);
	}
	return ((k == -1) ? -1 : 1)
}
