#include "so_long.h"

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void flood_fill(char **tab, t_point size, int row, int col)
{
    if(row < 0 || col < 0 || col >= size.x || row >= size.y)
        return;
    if(tab[row][col] == 'F' || tab[row][col] == '1')
        return;
    
    tab[row][col] = 'F';
    flood_fill(tab, size, row + 1, col);
    flood_fill(tab, size, row - 1, col);
    flood_fill(tab, size, row, col + 1);
    flood_fill(tab, size, row, col - 1);
}

t_point set_begin(char **map)
{
	int	i;
	int	j;
    t_point begin;

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
                return(begin);
            }
			j++;
		}
		i++;
	}
	begin.x = -1;
    begin.y = -1;
    return (begin);
}

int main()
{
    char **map = read_map("map.ber");
    int cols = ft_strlen(map[0]);
    int rows = 0;
    while(map[rows])
        rows++;
    t_point size;
    size.x = cols;
    size.y = rows;
    t_point begin = set_begin(map);
    flood_fill(map, size, begin.y, begin.x);
    int i = 0;
    while(map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
    free(map);
}