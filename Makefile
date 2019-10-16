# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    new                                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 13:39:54 by abenton           #+#    #+#              #
#    Updated: 2019/10/16 14:42:47 by abenton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/main.c srcs/list_work.c srcs/algoritm_func.c srcs/add_func.c \
	   srcs/validation.c srcs/map_func.c

OBJ = $(SRC:.c=.o)

HDR = fillit.h

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)

$(NAME): lib $(OBJ)
		gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

lib:
		make -C $(LIBFT)
clean:
		rm -f $(OBJ)
		make -C $(LIBFT) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT) fclean

re: fclean all
