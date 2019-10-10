# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 16:57:42 by abenton           #+#    #+#              #
#    Updated: 2019/10/10 16:23:39 by abenton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 

OBJ = $(SRC%.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Wextra -Werror 

clean: 
		rm -rf &(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
