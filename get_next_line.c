/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:57:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/09 21:27:39 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	check_NL(t_str *gnl, char *buffer, char **line)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	(*line) = ft_strsub(buffer, 0, i);
	printf("%d\n", i);
	if (gnl->n == 1)
	{
		gnl->string = ft_strjoin(gnl->mod, buffer + (i + 1));
		ft_strdel(&(gnl->mod));
	}
	else
		gnl->string = ft_strsub(buffer, i + 1, ft_strlen(buffer + (i + 1)));
	gnl->mod = ft_strdup(gnl->string);
	ft_strdel(&(gnl->string));
}

int		get_next_line(const int fd, char **line)
{
	static t_str	*gnl;
	int				k;
	int 			i;

	k = 0;
	i = 0;
	printf("%d", k);
	gnl = malloc(sizeof(t_str));
	if (fd)
	{
		k = read(fd, buffer, BUFF_SIZE);
		check_NL(gnl, buffer, line);
		if (!k)
			return (0);	
		return (1);
	}		
	return (-1);
}
