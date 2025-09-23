# NAME = so_long
# CC = cc
# FLAGS = -Wall -Wextra -Werror -g
# MLX_PATH =  minilibx-linux/
# MLX = $(MLX_PATH)/libmlx.a
# 
# SRC = parsing.c flood_fill.c gnl/get_next_line_utils.c gnl/get_next_line.c check_map.c window.c
# OBJS = $(SRC_FILES:.c=.o)
# LIBFT = Libft/libft.a
# REPO = https://github.com/42paris/minilibx-linux.git
# 
# all: $(NAME) 
# 
# $(NAME):$(OBJS) $(LIBFT) $(MLX)
# 	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -g -o $(NAME)
# 
# %.o: %.c
# 	@$(CC) $(FLAGS) -c $< -o $@
# 	
# $(LIBFT):
# 	@$(MAKE) -C Libft
# 	
# $(MLX):
# 	@make -C $(MLX_PATH)
# 
# mlx:
# 	git clone $(REPO)
# 
# clean:
# 	@rm -f $(OBJS)
# 	@make clean -C Libft
# fclean:clean
# 	@rm -f $(NAME)
# 	@rm -rf -d $(MLX_PATH)
# 	@make fclean -C Libft
# 
# re: fclean all
# 
# ra: re clean
# 	@rm -f $(OBJS)
# 	@make clean -C Libft
# 
# e: all clean
# 
# .PHONY: all fclean clean re


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:26:27 by pfreire-          #+#    #+#              #
#    Updated: 2025/08/14 10:18:03 by pfreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLX_PATH =  minilibx-linux/
MLX = $(MLX_PATH)/libmlx.a
SRC_FILES =	check_map.c flood_fill.c parsing.c window.c gnl/get_next_line_utils.c gnl/get_next_line.c
OBJS = $(SRC_FILES:.c=.o)
LIBFT = libft/libft.a
REPO = https://github.com/42paris/minilibx-linux.git

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -g -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@$(MAKE) -C libft
	
$(MLX):
	@make -C $(MLX_PATH)

mlx:
	git clone $(REPO)

clean:
	@rm -f $(OBJS)
	@make clean -C libft
fclean:clean
	@rm -f $(NAME)
	@rm -rf -d $(MLX_PATH)
	@make fclean -C libft

re: fclean all

ra: re clean
	@rm -f $(OBJS)
	@make clean -C libft

e: all clean

.PHONY: all fclean clean re