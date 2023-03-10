#include "a_little_valentine.h"

////////////////////////////////////////////// Putting the map on the screen /////////////////////////////////////////////

// Puts the map on the screen image by image
static void put_map_to_window(t_data *game, int row, int column)
{
	if (game->map[row][column] == '1')
		put_image_to_window(game, WALL, row, column);
	else if (game->map[row][column] == '0')
		put_image_to_window(game, EMPTY, row, column);
	else if (game->map[row][column] == 'C')
		put_image_to_window(game, COLLECTIBLE, row, column);
	else if (game->map[row][column] == 'E')
	{
		put_image_to_window(game, game->exit_path, row, column);
		game->column2 = column;
		game->row2 = row;
	}
	else if (game->map[row][column] == 'R')
		put_image_to_window(game, RIVAL, row, column);
	else if (game->map[row][column] == 'P')
	{
		put_image_to_window(game, game->player_path, row, column);
		game->column = column;
		game->row = row;
	}
}

// Puts the map on the screen image by image
int create_map(t_data *game)
{
	int	row;
	int	column;

	game->moves = 0;
	if (check_map(game) == 0)
		return (0);
	row = -1;
	while (++row < game->map_height)
	{
		column = -1;
		while (++column < game->map_width)
			put_map_to_window(game, row, column);
	}
	return (1);
}
