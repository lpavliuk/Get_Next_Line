# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 14:09:22 by opavliuk          #+#    #+#              #
#    Updated: 2018/04/12 13:17:34 by opavliuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang -Wall -Werror -Wextra

all: 
	$(CC) -I libft/includes -o get_next_line.o -c get_next_line.c
	$(CC) -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean: 
	rm -f main.o get_next_line.o
