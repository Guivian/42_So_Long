# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 18:46:26 by lbarbosa          #+#    #+#              #
#    Updated: 2022/08/01 19:23:12 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = So_Long

CC = gcc

CFLAGS = -g -fsanitize=address -o

HEADER = so_long.h

C_SRC = test.c

SRC_OBJ = $(C_SRC:.c=.o)

all: $(NAME)

$(NAME): $(C_OBJ)
	@cd ft_printf && make && cd ..
	@cd mlx_linux && make && cd ..
	@$(CC) $(CFLAGS) $(NAME) $(HEADER) $(C_SRC) ft_printf/libftprintf.a mlx_linux/libmlx.a -lXext -lX11 -lm -lz 

clean:
	@cd ft_printf && make clean && cd ..
	@cd mlx_linux && make clean && cd ..

fclean: clean
	@rm -rf $(NAME)
	@cd ft_printf && make fclean && cd ..

re: fclean all

.PHONY: all clean fclean re
