#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 17:14:10 by dpetrysh          #+#    #+#              #
#    Updated: 2018/03/06 17:14:11 by dpetrysh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
LIB_DIR = ./libft/
MLX_DIR = ./minilibx/

_SRC = main.c \
		circling.c \
		exit_fdf.c \
		mover.c \
		print_line.c \
		reading.c \
		scoper.c \
		zsuver.c \
		check_free.c \
		turn_back.c \
		color_maker.c

SRC = $(_SRC:%.c=$(SRC_DIR)%.c)$
OBJ = $(_SRC:%.c=%.o)$

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft -g -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -I ./libft -c $< -o $@

clean: 
	make -C $(LIB_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all
	