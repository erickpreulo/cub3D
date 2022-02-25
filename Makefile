# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 19:18:55 by acanterg          #+#    #+#              #
#    Updated: 2022/02/25 10:15:36 by acanterg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

SRC		=	src/*.c src/*/*.c
GCC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
FSANIT  =	-fsanitize=address -g
INCLUD	=	-I includes
NAME	=	cub3d
LIBFT	= 	libft
LIBS	=	-L./$(LIBFT) -g -lft
MLX_MAC	=	-I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
MLX_42	=	-I /usr/X11/include -g -l mlx -framework OpenGL -framework AppKit
MLX_LNX	=	-L minilibx-linux -lmlx -lm -lX11 -lXext -O3

OS_NAME =	$(shell uname -s)

ifeq ($(OS_NAME),Linux)
	MLX_F = $(MLX_LNX)
endif
ifeq ($(OS_NAME),Darwin)
	MLX_F = $(MLX_MAC)
endif

all : 		$(NAME)

$(NAME) :	lib
			echo -n cub3d...
			$(GCC) $(CFLAGS) $(FSANIT) -o $(NAME) $(SRC) $(INCLUD) $(MLX_42) $(LIBS)
			rm -rf *.dSYM
			echo " [DONE]"
			
lib		:
			echo -n libft...
			make re -C $(LIBFT)
			make clean -C $(LIBFT)
			echo " [DONE]"

init	: 	re
			./$(NAME) maps/config.cub

clean :
			rm -rf $(NAME)
			make clean -C $(LIBFT)

bonus :		all

fclean :	clean
			make fclean -C $(LIBFT)

re :		fclean all

.PHONY: 	all clean fclean re test