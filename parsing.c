#include "Libft/libft.h"
#include "gnl/get_next_line.h"
#include "strings.h"

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

char	**read_map(char *file)
{
	if(!is_ber(file))
		return(NULL);
	char **map;
	char *line;
	char *join;
	char *temp;
	join = ft_strdup("");
	if(!join)
		return(NULL);
	int fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(join, line);
		free(join);
		//LEAKS BELOW
		join = ft_strdup(temp);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(join, '\n');
	return (map);
}

int main()
{
	char **map = read_map("alo.ber");
	int i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

