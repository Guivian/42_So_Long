# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 18:46:26 by lbarbosa          #+#    #+#              #
#    Updated: 2022/08/22 19:21:03 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -o

HEADERS = so_long.h GNL/get_next_line.h

C_SRC = GNL/get_next_line.c GNL/get_next_line_utils.c so_long.c validate_map.c image_handlers.c window_and_background.c so_long_protections.c

SRC_OBJ = $(C_SRC:.c=.o)

all: $(NAME)

$(NAME): $(C_OBJ)
	@cd mlx_linux && make && cd ..
	@$(CC) $(CFLAGS) $(NAME) $(HEADERS) $(C_SRC) mlx_linux/libmlx.a -lXext -lX11 -lm -lz 

clean:
	@cd GNL && rm -rf *.o && cd ..
	@cd mlx_linux && make clean && cd ..

fclean: clean
	@rm -rf $(NAME)

re: fclean all

x: re clean
	@./so_long maps/mapa1.ber

.PHONY: all clean fclean re
