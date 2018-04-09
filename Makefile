# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 14:09:22 by opavliuk          #+#    #+#              #
#    Updated: 2018/04/09 14:13:17 by opavliuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang -Wall -Werror -Wextra

all: 
	$(CC) -I libft/ -o get_next_line.o -c get_next_line.c
	$(CC) -I libft/ -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/ -L libft/ -lft

clean: 
	rm -f main.o get_next_line.o
