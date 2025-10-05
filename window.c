/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:46:59 by gocaetan          #+#    #+#             */
/*   Updated: 2025/10/05 17:58:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->walls.img_ptr, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible.img_ptr,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.current_sprite.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
	{
		if (game->map.collectibles == game->player.collected)
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_win.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->exit.img_ptr, x
				* TILE_SIZE, y * TILE_SIZE);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->floor.img_ptr, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	mlx_clear_window(game->mlx, game->win);
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			tile = game->map.grid[y][x];
			draw_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
}

void	init_window(t_game *game)
{
	int	win_w;
	int	win_h;
	int	screen_w;
	int	screen_h;

	win_w = game->map.width * TILE_SIZE;
	win_h = game->map.height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putendl_fd("mlx_init failed", 2);
		close_game(game);
	}
	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
	if (win_w > screen_w || win_h > screen_h)
	{
		ft_putendl_fd("Error: Window to big for the screen", 2);
		close_game(game);
	}
	game->win = mlx_new_window(game->mlx, win_w, win_h, "SHREK");
	if (!game->win)
	{
		ft_putendl_fd("mlx_new_window failed", 2);
		close_game(game);
	}
}

void	init_map(t_game *game, char *path)
{
	game->map.grid = read_map(path);
	if (!game->map.grid)
		error(game->map.grid);
	game->map.height = 0;
	while (game->map.grid[game->map.height])
		game->map.height++;
	game->map.width = ft_strlen(game->map.grid[0]);
	if (!is_retangular(game->map.grid))
		error(game->map.grid);
	if (!walls_sorrounded(game->map.grid))
		error(game->map.grid);
	if (!check_map_elements(game->map.grid))
		error(game->map.grid);
	if (!invalid_chr(game->map.grid))
		error(game->map.grid);
	if (!flood_fill(game))
		error(game->map.grid);
}
