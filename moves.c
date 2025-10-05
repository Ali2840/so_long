/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:19:52 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 17:11:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos.x + dx;
	new_y = game->player.pos.y + dy;
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.grid[new_y][new_x] = '0';
		game->player.collected++;
	}
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->map.collectibles == game->player.collected)
			winning(game);
		else
			return ;
	}
	game->map.grid[game->player.pos.y][game->player.pos.x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->player.pos.x = new_x;
	game->player.pos.y = new_y;
	printf("moves: %d\n", ++game->player.moves);
	draw_map(game);
}

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119)
		move_player(game, 0, -1);
	if (keycode == 97)
	{
		game->player.current_sprite = game->player.l_sprite;
		move_player(game, -1, 0);
	}
	if (keycode == 115)
		move_player(game, 0, 1);
	if (keycode == 100)
	{
		game->player.current_sprite = game->player.sprite;
		move_player(game, 1, 0);
	}
	return (0);
}

void	winning(t_game *game)
{
	ft_putendl_fd("Congratulations you Win", 1);
	free_game(*game);
	exit(0);
}

void	free_game(t_game game)
{
	if (game.floor.img_ptr)
		mlx_destroy_image(game.mlx, game.floor.img_ptr);
	if (game.walls.img_ptr)
		mlx_destroy_image(game.mlx, game.walls.img_ptr);
	if (game.exit.img_ptr)
		mlx_destroy_image(game.mlx, game.exit.img_ptr);
	if (game.exit_win.img_ptr)
		mlx_destroy_image(game.mlx, game.exit_win.img_ptr);
	if (game.collectible.img_ptr)
		mlx_destroy_image(game.mlx, game.collectible.img_ptr);
	if (game.player.sprite.img_ptr)
		mlx_destroy_image(game.mlx, game.player.sprite.img_ptr);
	if (game.player.l_sprite.img_ptr)
		mlx_destroy_image(game.mlx, game.player.l_sprite.img_ptr);
	if (game.win)
		mlx_destroy_window(game.mlx, game.win);
	if (game.map.grid)
		free_split(game.map.grid);
	if (game.collects)
		free(game.collects);
	if (game.mlx)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}

int	count_collects(t_map mapa)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (mapa.grid[i])
	{
		j = 0;
		while (mapa.grid[i][j])
		{
			if (mapa.grid[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
