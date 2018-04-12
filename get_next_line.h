/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:14:59 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/12 21:49:18 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct	s_lsts
{
	int				i;
	int				k;
	int				fd;
	char			*n;
	char			buffer[BUFF_SIZE + 1];
	struct s_lsts	*next;
}				t_lsts;

int				get_next_line(const int fd, char **line);

#endif
