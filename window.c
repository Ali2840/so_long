/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:46:59 by gocaetan          #+#    #+#             */
/*   Updated: 2025/10/02 13:11:00 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->walls.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectible.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player.current_sprite.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
			{
				if (game->map.collectibles == game->player.collected)
					mlx_put_image_to_window(game->mlx, game->win,
						game->exit_win.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
				else
					mlx_put_image_to_window(game->mlx, game->win,
						game->exit.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
			}
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->floor.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
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
		perror("mlx_init failed");
		free_game(*game);
	}
	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
	if (win_w > screen_w || win_h > screen_h)
	{
		ft_putendl_fd("Error: Window to big for the screen", 2);
		free_game(*game);
	}
	game->win = mlx_new_window(game->mlx, win_w, win_h, "SHREK");
	if (!game->win)
	{
		perror("mlx_new_window failed");
		free_game(*game);
	}
}

void	init_sprites(t_game *game)
{
	game->floor.img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/grass.xpm",
			&game->floor.width, &game->floor.height);
	game->walls.img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&game->walls.width, &game->walls.height);
	game->exit.img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/exit2.xpm",
			&game->exit.width, &game->exit.height);
	game->collectible.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"sprites/burro.xpm", &game->collectible.width,
			&game->collectible.height);
	game->exit_win.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit1.xpm", &game->exit_win.width, &game->exit_win.height);
	if (!game->floor.img_ptr || !game->walls.img_ptr || !game->exit.img_ptr
		|| !game->collectible.img_ptr)
	{
		ft_putendl_fd("Error loading sprites", 2);
		free_game(*game);
	}
}

void	init_player(t_game *game)
{
	game->player.moves = 0;
	game->player.collected = 0;
	game->player.pos = set_begin(game->map.grid);
	game->player.sprite.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"sprites/shrek.xpm", &game->player.sprite.width,
			&game->player.sprite.height);
	game->player.l_sprite.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"sprites/shrek_left.xpm", &game->player.l_sprite.width,
			&game->player.l_sprite.height);
	if (!game->player.sprite.img_ptr || !game->player.l_sprite.img_ptr)
	{
		ft_putendl_fd("Error loading player sprite", 1);
		free_game(*game);
	}
	game->player.current_sprite = game->player.sprite;
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

void	init_collectibles(t_game *game)
{
	int		i;
	int		j;
	int		idx;
	t_map	map;
	int		count;

	i = 0;
	idx = 0;
	map = game->map;
	count = count_collects(map);
	game->map.collectibles = count;
	if (count == 0)
	{
		game->collects = NULL;
		return ;
	}
	game->collects = malloc(sizeof(t_point) * count);
	if (!game->collects)
	{
		perror("malloc failed for collects");
		free_game(*game);
	}
	while (map.grid[i])
	{
		j = 0;
		while (map.grid[i][j])
		{
			if (map.grid[i][j] == 'C')
			{
				game->collects[idx].x = j;
				game->collects[idx].y = i;
				idx++;
			}
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game)
{
	init_window(game);
	init_sprites(game);
	init_player(game);
	init_collectibles(game);
}
