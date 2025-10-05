# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 12:40:29 by gocaetan          #+#    #+#              #
#    Updated: 2025/10/05 16:10:51 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLX_PATH =  minilibx-linux/
MLX = $(MLX_PATH)/libmlx.a
SRC_FILES =	check_map.c flood_fill.c parsing.c window.c gnl/get_next_line_utils.c gnl/get_next_line.c moves.c inits.c so_long.c
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