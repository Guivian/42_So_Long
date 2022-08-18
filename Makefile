# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 18:46:26 by lbarbosa          #+#    #+#              #
#    Updated: 2022/08/18 18:36:14 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -o

HEADERS = so_long.h GNL/get_next_line.h

C_SRC = test.c GNL/get_next_line.c GNL/get_next_line_utils.c validate_map.c utils.c

SRC_OBJ = $(C_SRC:.c=.o)

all: $(NAME)

$(NAME): $(C_OBJ)
	@cd mlx_linux && make && cd ..
	@$(CC) $(CFLAGS) $(NAME) $(HEADERS) $(C_SRC) mlx_linux/libmlx.a -lXext -lX11 -lm -lz 

clean:
	@cd mlx_linux && make clean && cd ..

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
