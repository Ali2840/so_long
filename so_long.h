#ifndef SO_LONG_H
# define SO_LONG_H

#include "Libft/libft.h"
#include "gnl/get_next_line.h"
#include "strings.h"

char	*strjoin_free(char *s1, char *s2);
int	check_map_elements(char **map);
int	is_ber(char *file);
int walls_sorrounded(char **map);
int invalid_chr(char **map);
char	**read_map(char *file);
int is_retangular(char **map);

#endif