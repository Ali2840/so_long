#include "Libft/libft.h"
#include "gnl/get_next_line.h"
#include "strings.h"

char	*strjoin_free(char *s1, char *s2)
{
	int		total_size;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc((sizeof(char)) * total_size);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, total_size);
	free(s1);
	ft_strlcat(ptr, s2, total_size);
	return (ptr);
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
int walls_sorrounded(char **map)
{
	int cols;
	int rows = 0;
	int i = 0;
	while(map[rows])
		rows++;
	cols = ft_strlen(map[0]);
	while(i < cols)
	{
		if(map[0][i] != '1' || map[rows - 1][i] != '1')
			return(0);
		i++;
	}
	int j = 0;
	while(j < rows)
	{
		if(map[j][0] != '1' || map[j][cols - 1] != '1')
			return(0);
		j++;
	}
	return(1);
}

int invalid_chr(char **map)
{
	int i = 0;
	int j = 0;

	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != 'C')
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}

char	**read_map(char *file)
{
	if(!is_ber(file))
		return(NULL);
	char **map;
	char *line;
	char *join;
	join = ft_strdup("");
	if(!join)
		return(NULL);
	int fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		join = ft_strjoin(join, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(join, '\n');
	free(join);
	return (map);
}

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

int main()
{
	char **map = read_map("map.ber");
	int i = 0;
	if(invalid_chr(map))
		printf("valid\n");
	else
		printf("invalid\n");
	while(map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map); //ainda tens alguns leaks
}
	
