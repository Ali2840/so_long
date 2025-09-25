#include "so_long.h"

int is_retangular(char **map)
{
	size_t len = ft_strlen(map[0]);
	int i = 1;
	while(map[i])
	{
		if(ft_strlen(map[i]) != len)
			return(0);
		i++;
	}
	return(1);
}

int	is_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") == 0)
		return (1);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	error(char **split)
{
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        ft_putendl_fd("Usage: ./so_long map.ber", 2);
        return (1);
    }
    if (!is_ber(av[1]))
        error(NULL);
    game.map.grid = read_map(av[1]);
    if (!game.map.grid)
        error(NULL);

    game.map.height = 0;
    while (game.map.grid[game.map.height])
        game.map.height++;
    game.map.width = ft_strlen(game.map.grid[0]);

    if (!is_retangular(game.map.grid))
        error(game.map.grid);
    if (!walls_sorrounded(game.map.grid))
        error(game.map.grid);
    if (!check_map_elements(game.map.grid))
        error(game.map.grid);
    if (!flood_fill(game.map.grid))
    {
		printf("error flod");
		exit(1);
	}
    init_game(&game);
    draw_map(&game);
	mlx_key_hook(game.win, key_handler, &game);
    mlx_loop(game.mlx);
    free_split(game.map.grid);
    free(game.collects);
    return (0);
}
