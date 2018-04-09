/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:55:20 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/09 21:17:57 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>

# define BUFF_SIZE 100

typedef struct	s_str
{
		int		n;
		int		i;
		char	*buffer[BUFF_SIZE + 1];
		char	*mod;
		char	*string;
}				t_str;

int		get_next_line(const int fd, char **line);

#endif
