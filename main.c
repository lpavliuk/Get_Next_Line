/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:59:26 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/09 21:27:29 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char 	*line;

	i = 1;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY, 0);
		printf("%d\n", fd);
		while (i > 0)
		{
			i = get_next_line(fd, &line);
			ft_putendl(line);
			printf("%d\n", i);
			ft_strdel(&line);
		}
		if (i == 0)
			ft_putendl("Read is done!");
		else
			ft_putendl("Error reading file!");
		close(fd);
	}
	else
		ft_putendl("Error!");
	return (0);
}
