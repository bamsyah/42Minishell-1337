# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 11:37:46 by bamsyah           #+#    #+#              #
#    Updated: 2023/12/06 11:41:24 by bamsyah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 

OBJ = 

all: $(Name)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all