#include "a_little_valentine.h"

/////////////////////////////////////////////////// Check the map /////////////////////////////////////////////////////////

static int	check_edges(t_data *game)
{
	int	row;
	int	column;

	row = -1;
	while (++row < game->map_height)
	{
		if (game->map[row][0] != '1' || game->map[row][game->map_width - 1] != '1')
			return (0);
	}
	column = -1;
	while (++column < game->map_width)
	{
		if (game->map[0][column] != '1' || game->map[game->map_height - 1][column] != '1' )
			return (0);
	}
	return (1);
}

static void	check_components(t_data *game)
{
	int	row;
	int	column;

	row = -1;
	while (++row < game->map_height)
	{
		column = -1;
		while (++column < game->map_width)
		{
			if (game->map[row][column] == 'P')
				game->player++;
			else if (game->map[row][column] == 'E')
				game->exit++;
			else if (game->map[row][column] == 'C')
				game->collectibles++;
			if (game->map[row][column] == '1' || game->map[row][column] == '0' ||
				game->map[row][column] == 'C' || game->map[row][column] == 'E' ||
				game->map[row][column] == 'P' || game->map[row][column] == 'R')
				game->components++;
		}
	}
}

int	check_map(t_data *game)
{
	game->player = 0;
	game->exit = 0;
	game->collectibles = 0;
	game->components = 0;

	check_components(game);
	if (game->player != 1 || game->exit != 1)
		return (error(EINVAL, "The map contains more than one player/exit!\n"));
	else if (game->collectibles <= 0)
		return (error(EINVAL, "The map does not contain at least one collectible!\n"));
	else if (game->components != (game->map_width) * (game->map_height))
		return (error(EINVAL, "The map contains invalid characters!\n"));
	else if (check_edges(game) == 0)
		return (error(EINVAL, "The map is not a rectangle that is surrounded by walls!\n"));
	game->max_collectibles = game->collectibles;
	return (1);
}