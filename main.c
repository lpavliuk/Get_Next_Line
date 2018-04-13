/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:59:26 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/12 17:22:37 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		n;
	int		fd[2];
	char	*line = NULL;

	i = 1;
	n = 1;
	argc = 2;
		//line[0] = NULL;
		fd[0] = open(argv[1], O_RDONLY);
	//	fd[1] = open(argv[2], O_RDONLY, 0);
		/* Read abc and new line */
	/*	i = get_next_line(fd[0], &line);
		printf("%s\n", line);
		i = get_next_line(fd[0], &line);
		printf("%s\n", line);
		i = get_next_line(fd[0], &line);
		printf("%s\n", line);*/
	/*	if (i == 1 && ft_strcmp(line, "abc") == 0)
			printf("OK!\n");
		else
			printf("KO!\n");*/

		/* Read new line */
	/*	i = get_next_line(fd, &line);
		printf("%d\n", i);
		if (i == 1 && *line == '\0')
			printf("OK!\n");
		else
			printf("KO!\n");*/
	
		/* Read again, but meet EOF */
/*		i = get_next_line(fd, &line);
		if (i == 0 && *line == '\0')
			printf("OK!\n");
		else
			printf("KO!\n");*/

		/* Let's do it once again */
	/*	i = get_next_line(fd, &line);
		if (i == 0 && *line == '\0')
			printf("OK!\n");
		elsei*/

	/* Not opened fd */
//	if (get_next_line(42, &line) != -1)
//		return (0);
//	printf("OK!\n");
		while ((i = get_next_line(fd[0], &line)) > 0)
		{
			printf("%s\n", (line));
		}
		//printf("%d\n", i);
	//	printf("%s\n", (line));
	//	i = get_next_line(fd[0], &line[0]);
	//	printf("i: %d - %s\n", i, line[0]);
		
	//	n = get_next_line(fd[1], &line[1]);
	//	printf("n: %d - %s\n", i, line[1]);

	//	i = get_next_line(fd[0], &line[0]);
	//	printf("i: %d - %s\n", i, line[0]);
		
	//	n = get_next_line(fd[1], &line[1]);
	//	printf("n: %d - %s\n", i, line[1]);
		
	//	i = get_next_line(fd[0], &line[0]);
	//	printf("i: %d - %s\n", i, line[0]);
		
	//	n = get_next_line(fd[1], &line[1]);
	//	printf("n: %d - %s\n", i, line[1]);
		
	//	printf("fd[0] = %d\n", fd[0]);
	//	printf("fd[1] = %d\n", fd[1]);
		if (i == 0)
			ft_putendl("Read is done!");
		else
			ft_putendl("Error reading file!");
		close(fd[0]);
	return (0);
}
