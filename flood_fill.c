/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 10:28:50 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 10:28:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point pos, bool *exit)
{
	if (pos.y < 0 || pos.x < 0 || pos.x >= size.x || pos.y >= size.y)
		return ;
	if (tab[pos.y][pos.x] == 'E')
		*exit = true;
	if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] == '1'
		|| tab[pos.y][pos.x] == 'E')
		return ;
	tab[pos.y][pos.x] = 'F';
	pos.x++;
	fill(tab, size, pos, exit);
	pos.x -= 2;
	fill(tab, size, pos, exit);
	pos.x++;
	pos.y++;
	fill(tab, size, pos, exit);
	pos.y -= 2;
	fill(tab, size, pos, exit);
}

t_point	set_begin(char **map)
{
	int		i;
	int		j;
	t_point	begin;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				begin.x = j;
				begin.y = i;
				return (begin);
			}
			j++;
		}
		i++;
	}
	begin.x = -1;
	begin.y = -1;
	return (begin);
}

char	**map_dup(char **map, int rows)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (rows + 1));
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			free_split(new_map);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	check_reachable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	flood_fill(t_game *game)
{
	char	**to_fill;
	t_point	size;
	t_point	begin;
	bool	exit;

	to_fill = map_dup(game->map.grid, game->map.height);
	size.x = game->map.width;
	size.y = game->map.height;
	begin = set_begin(to_fill);
	exit = false;
	fill(to_fill, size, begin, &exit);
	if (check_reachable(to_fill) && exit)
	{
		free_split(to_fill);
		return (1);
	}
	free_split(to_fill);
	return (0);
}
