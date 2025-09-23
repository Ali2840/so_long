#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "strings.h"

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_img
{
	char			*img_addr;
	int				width;
	int				heigth;
	int				bpp;
	int				l_len;
	int				endian;
	int				*img_ptr;
}	t_img;

typedef struct s_map
{
	char **grid;
	int widht;
	int height;
	int colletibles;
} t_map;

typedef struct s_player
{
	t_point point;
	t_img p_sprite;
	int moves;
	int collectibles;
} t_player;

typedef struct s_col
{
	int collected;
	int x;
	int y;
}	t_col;

typedef struct s_colls
{
	t_col *collectible;
	t_img sprite;
} t_colls;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_map map;
	t_img img;
	t_img base;
	t_player player;
	t_colls collectibles;
	t_img frame_buffer;
} t_game;

char	*strjoin_free(char *s1, char *s2);
int	check_map_elements(char **map);
int	is_ber(char *file);
int	walls_sorrounded(char **map);
int	invalid_chr(char **map);
char	**read_map(char *file);
int	is_retangular(char **map);
void	free_split(char **split);
int	check_reachable(char **map);
int	flood_fill(char **map);
void	fill(char **tab, t_point size, int row, int col);
char	**map_dup(char **map, int rows);
int	is_ber(char *file);
t_point set_begin(char **map); 	

#endif