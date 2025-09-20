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

int main()
{
    char **map = read_map("map.ber");
    if(!is_ber("map.ber"))
        error(map);
    else if(!is_retangular(map))
        error(map);
    else if(!walls_sorrounded(map))
        error(map);
    else if(!check_map_elements(map))
        error(map);
    else if(!flood_fill(map))
        error(map);
    else
        printf("all okk");
    free_split(map);
}