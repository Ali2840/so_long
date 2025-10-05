/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:37:02 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 15:37:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 128

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
}				t_map;

typedef struct s_player
{
	t_point		pos;
	t_img		sprite;
	t_img		l_sprite;
	t_img		current_sprite;
	int			moves;
	int			collected;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		floor;
	t_img		walls;
	t_img		exit_win;
	t_img		exit;
	t_img		collectible;
	t_player	player;
	t_point		*collects;
}				t_game;

char			*strjoin_free(char *s1, char *s2);
int				check_map_elements(char **map);
int				is_ber(char *file);
int				walls_sorrounded(char **map);
int				invalid_chr(char **map);
char			**read_map(char *file);
int				is_retangular(char **map);
void			free_split(char **split);
int				check_reachable(char **map);
int				flood_fill(t_game *game);
void			fill(char **tab, t_point size, t_point pos, bool *exit);
char			**map_dup(char **map, int rows);
t_point			set_begin(char **map);
int				key_handler(int keycode, void *param);
void			init_game(t_game *game);
void			init_window(t_game *game);
void			init_sprites(t_game *game);
void			init_player(t_game *game);
int				count_collects(t_map mapa);
void			init_collectibles(t_game *game);
void			draw_map(t_game *game);
void			move_player(t_game *game, int dx, int dy);
void			free_game(t_game game);
int				close_game(t_game *game);
void			init_map(t_game *game, char *path);
void			error(char **split);
int				count_collects(t_map mapa);
void			winning(t_game *game);

#endif
