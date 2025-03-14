# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 00:08:06 by mcastrat          #+#    #+#              #
#    Updated: 2025/03/15 00:08:06 by mcastrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes/ -I libft/includes/ -I mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz


SRC = srcs/main.c srcs/check.c srcs/seemap.c srcs/check2.c srcs/check3.c \
	srcs/path.c srcs/img.c srcs/initgame.c \
	srcs/draw.c srcs/keyboard.c

OBJ_DIR = objects/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))


LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = mlx/
MLX = $(MLX_DIR)libmlx.a

all: $(OBJ_DIR) $(LIBFT) $(MLX) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)

$(OBJ_DIR)%.o: srcs/%.c includes/so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(MLX)
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
