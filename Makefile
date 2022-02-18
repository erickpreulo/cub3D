# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 19:18:55 by acanterg          #+#    #+#              #
#    Updated: 2022/02/18 10:22:47 by aneuwald         ###   ########.fr        #
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
LIBS	=	-L./$(LIBFT) -lft
MLX		=	-L mlx -lmlx -framework OpenGL -framework AppKit -O3
MLX_LNX	=	-L minilibx-linux -lmlx -lm -lX11 -lXext -O3

test	:	re
			./$(NAME) config.cub

all : 		$(NAME)

$(NAME) :	lib
			echo -n ">>> cub3d... "
			$(GCC) $(CFLAGS) $(FSANIT) -o $(NAME) $(SRC) $(INCLUD) $(MLX_LNX) $(LIBS)
			rm -rf *.dSYM
			echo "[DONE]"
			
lib		:	
			echo -n ">>> libft... "
			make re -C $(LIBFT)
			make clean -C $(LIBFT)
			echo "[DONE]"

clean :
			rm -rf $(NAME)
			make clean -C $(LIBFT)

bonus :		all

fclean :	clean
			make fclean -C $(LIBFT)

re :		fclean all

.PHONY: 	all clean fclean re test