#include "so_long.h"

// int	verify_tile(t_game *data, char tile, int x, int y)
// {
// 	if (tile == '1')
// 		return (1);
// 	if (tile == 'C')
// 	{
// 		data->player.collected++;
// 		data->map.grid[y][x] = '0';
// 	}
// 	if (tile == 'E')
// 	{
// 		if (data->player.collected == data->map.collectibles)
// 			printf("ganhou");
// 		else
// 			return (1);
// 	}
// 	return (0);
// }
void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player.pos.x + dx;
    int new_y = game->player.pos.y + dy;

    if (game->map.grid[new_y][new_x] == '1')
        return;
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
        }
        else
            return;
    }
	game->map.grid[game->player.pos.y][game->player.pos.x] = '0';
	game->map.grid[new_y][new_x] = 'P';
    game->player.pos.x = new_x;
    game->player.pos.y = new_y;
    game->player.moves++;

    printf("moves: %d\n", game->player.moves);

    draw_map(game);
}

// void	move_player(t_game *data, int dx, int dy)
// {
// 	int		new_x;
// 	int		new_y;
// 	char	next_tile;

// 	new_x = data->player.pos.x + dx;
// 	new_y = data->player.pos.y + dy;
// 	if (new_x < 0 || new_x >= data->map.width || new_y < 0 || new_y >= data->map.height)
// 		return ;
// 	next_tile = data->map.grid[new_y][new_x];
// 	if (verify_tile(data, next_tile, new_x, new_y))
// 		return ;
// 	data->map.grid[data->player.pos.y][data->player.pos.x] = '0';
// 	data->map.grid[new_y][new_x] = 'P';
// 	data->player.pos.x = new_x;
// 	data->player.pos.y = new_y;
// 	data->player.moves++;
// 	printf("Movimentos: %d\n", data->player.moves);
// 	draw_map(data);
// }

int key_handler(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	if(keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if(keycode == 119)
		move_player(game, 0, -1);
	if(keycode == 97)
		move_player(game, -1, 0);
	if(keycode == 115)
		move_player(game, 0, 1);
	if(keycode == 100)
		move_player(game, 1, 0);
	return(0);
}