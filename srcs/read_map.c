#include "a_little_valentine.h"

////////////////////////////////////////////////// Reading the map //////////////////////////////////////////////////////

// Establishes the width of the map
static void	get_width_of_map(t_data *game)
{
	game->map_width = 0;
	while (game->map[0][game->map_width] != '\0')
		game->map_width++;
	if (game->map[0][game->map_width - 1] == '\n')
		game->map_width--;
}

// Adds the established line to the map
static int	add_line(t_data *game, char *line)
{
	char	**tmp;
	int		i;

	if (line == 0)
		return (0);
	i = 0;
	game->map_height++;
	tmp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	tmp[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

// Reads the map line by line 
int	read_map(t_data *game, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (add_line(game, line) == 0)
			break ;
	}
	close (fd);
	get_width_of_map(game);
	return (1);
}