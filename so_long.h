#ifndef SO_LONG_H
# define SO_LONG_H

#include "Libft/libft.h"
#include "gnl/get_next_line.h"
#include "strings.h"

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

char	*strjoin_free(char *s1, char *s2);
int	check_map_elements(char **map);
int	is_ber(char *file);
int walls_sorrounded(char **map);
int invalid_chr(char **map);
char	**read_map(char *file);
int is_retangular(char **map);
void	free_split(char **split);
int	check_reachable(char **map);
int flood_fill(char **map);
void fill(char **tab, t_point size, int row, int col);
char **map_dup(char **map, int rows);
int	is_ber(char *file);

#endif