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
		{
			ft_putendl_fd("Parabens seu ogre", 1);
			free_game(*game);
		}
		else
			return ;
	}
	game->map.grid[game->player.pos.y][game->player.pos.x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->player.pos.x = new_x;
	game->player.pos.y = new_y;
	game->player.moves++;
	printf("moves: %d\n", game->player.moves);
	draw_map(game);
}

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65307)
		free_game(*game);
	if (keycode == 119)
		move_player(game, 0, -1);
	if (keycode == 97)
		move_player(game, -1, 0);
	if (keycode == 115)
		move_player(game, 0, 1);
	if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

int	close_game(t_game *game)
{
	free_game(*game);
	return (0);
}

void	free_game(t_game game)
{
	if(game.floor.img_ptr)
		mlx_destroy_image(game.mlx, game.floor.img_ptr);
	if(game.walls.img_ptr)
		mlx_destroy_image(game.mlx, game.walls.img_ptr);
	if(game.exit.img_ptr)
		mlx_destroy_image(game.mlx, game.exit.img_ptr);
	if(game.exit_win.img_ptr)
		mlx_destroy_image(game.mlx, game.exit_win.img_ptr);
	if(game.collectible.img_ptr)
		mlx_destroy_image(game.mlx, game.collectible.img_ptr);
	if(game.player.sprite.img_ptr)
		mlx_destroy_image(game.mlx, game.player.sprite.img_ptr);
	if(game.win)
		mlx_destroy_window(game.mlx, game.win);
	if(game.mlx)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
	if(game.map.grid)
		free_split(game.map.grid);
	if(game.collects)
		free(game.collects);
	exit(0);
}
