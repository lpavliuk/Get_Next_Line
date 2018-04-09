/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:57:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/09 21:52:59 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	check_NL(t_str *gnl, char *buffer, char **line)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (gnl->buffer[i])
	{
		if (gnl->buffer[i] == '\n')
			break ;
		i++;
	}
	(*line) = ft_strsub(gnl->buffer, 0, i);
	printf("%d\n", i);
	i++;
	n = ft_strlen(gnl->buffer + (i + 1));
	ft_memmove(&(gnl->buffer[0]), &(gnl->buffer[i]), n);
	ft_memset(gnl->buffer, '\0', ft_strlen(gnl->buffer + n));
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
		k = read(fd, gnl->buffer, BUFF_SIZE);
		check_NL(gnl, gnl->buffer, line);
		if (!k)
			return (0);	
		return (1);
	}		
	return (-1);
}
