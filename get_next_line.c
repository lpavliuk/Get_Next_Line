/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:57:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/05 17:57:35 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strnlen(char *buf, int i, char c)
{
	int n;

	n = 0;
	while (buf[i] != c)
	{
		i++;
		n++;
	}
	return (n);
}

int		get_next_line(const int fd, char **line)
{
	int			n;
	int			j;
	int 		k;
	static int	i;
	static char buf[BUFF_SIZE];
	
	n = 0;
	j = i;
			printf("Buffer: %s\n", buf);
	ft_bzero(&buf[i], BUFF_SIZE - i);
			printf("Buffer after bzero: %s\n", buf);
	if (fd && line)
	{
		while ((k = read(fd, &buf[i], 1)))
		{
			if (buf[i] == '\n')
				break ;
			i++;
		}
		if (!k)
			return (0);
				printf("%d\n", k);
		n = ft_strnlen(buf, j, '\n');
		(*line) = ft_strsub(buf, j, n);
				printf("line: %s\n", (*line));
		ft_putstr((*line));
				ft_putchar('\n');
		ft_strdel(line);
				printf("line after free: %s\n", (*line));
		i++;
		return (1);
	}		
	return (-1);
}
