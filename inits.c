/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:52:12 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 15:52:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		close_game(game);
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
		close_game(game);
	}
	game->player.current_sprite = game->player.sprite;
}

static void	fill_collectibles(t_game *game, t_map map)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
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

void	init_collectibles(t_game *game)
{
	t_map	map;
	int		count;

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
		ft_putendl_fd("malloc failed for collects", 2);
		close_game(game);
	}
	fill_collectibles(game, map);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_sprites(game);
	init_player(game);
	init_collectibles(game);
}
