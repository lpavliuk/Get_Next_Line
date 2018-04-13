/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:54:49 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/13 21:00:05 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_GET_NEXT_LINE
# define NEW_GET_NEXT_LINE

# include "libft/libft"

# define BUFF_SIZE 10

int	get_next_line(const int fd, char **line);

#endif
