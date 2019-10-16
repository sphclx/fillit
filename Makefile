# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    new                                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 13:39:54 by abenton           #+#    #+#              #
#    Updated: 2019/10/16 13:49:03 by abenton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c list_work.c algoritm_func.c add_func.c validation.c map_func.c

OBJ = $(SRC:.c=.o)

HDR = fillit.h

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)

$(NAME):
		make -C $(libft)
		gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

clean:
		rm -f $(OBJ)
		make -C $(LIBFT) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT) fclean

re: fclean all
