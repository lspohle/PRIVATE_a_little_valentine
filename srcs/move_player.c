#include "a_little_valentine.h"

///////////////////////////////////////// Enabling the user to take action ///////////////////////////////////////////////

// Check validity of requested move
static int	check_move_player(t_data *game, int row, int column)
{
	char dst;

	dst = game->map[row][column];
	if (dst == '1' || (game->row2 == row && game->column2 == column && game->collectibles != 0))
		return (0);
	put_image_to_window(game, EMPTY, game->row, game->column);
	ft_printf(CYAN"Counter: %i\n"ESCAPE, ++game->moves);
	if (dst == 'C' && game->collectibles-- > 0)
	{
		ft_printf(GREEN"\nCollected: %i 🥳\n\n"ESCAPE, (game->collectibles - game->max_collectibles) * (-1));
		game->map[row][column] = '0';
	}
	else if (dst == 'R')
		game_over(game);
	return(1);
}

// Check validity of requested move
static int	check_move_exit(t_data *game, int row, int column)
{
	char dst;

	dst = game->map[row][column];
	if (dst == '1' || (game->row == row && game->column == column && game->collectibles != 0))
		return (0);
	put_image_to_window(game, EMPTY, game->row2, game->column2);
	ft_printf(CYAN"Counter: %i\n"ESCAPE, ++game->moves);
	if (dst == 'C' && game->collectibles-- > 0)
	{
		ft_printf(GREEN"\nCollected: %i 🥳\n\n"ESCAPE, (game->collectibles - game->max_collectibles) * (-1));
		game->map[row][column] = '0';
	}
	else if (dst == 'R')
		game_over(game);
	return(1);
}

// Creates hooks so that the user can control the player
int	play_game(int keycode, t_data *game) 
{	
	if (keycode == 123 && game->won == false && check_move_player(game, game->row, game->column - 1) == 1)
		game->column--;
	else if (keycode == 124 && game->won == false && check_move_player(game, game->row, game->column + 1) == 1)
		game->column++;
	else if (keycode == 125 && game->won == false && check_move_player(game, game->row + 1, game->column) == 1)
		game->row++;
	else if (keycode == 126 && game->won == false && check_move_player(game, game->row - 1, game->column) == 1)
		game->row--;
	else if (keycode == 0 && game->won == false && check_move_exit(game, game->row2, game->column2 - 1) == 1)
		game->column2--;
	else if (keycode == 2 && game->won == false && check_move_exit(game, game->row2, game->column2 + 1) == 1)
		game->column2++;
	else if (keycode == 1 && game->won == false && check_move_exit(game, game->row2 + 1, game->column2) == 1)
		game->row2++;
	else if (keycode == 13 && game->won == false && check_move_exit(game, game->row2 - 1, game->column2) == 1)
		game->row2--;
	else if (keycode == 48)
        ft_printf(PURPLE"\nTo collect: %i 😉\n\n"ESCAPE, game->collectibles);
	else if (keycode == 53)
		close_window(game);
	put_image_to_window(game, game->player_path, game->row, game->column);
	put_image_to_window(game, game->exit_path, game->row2, game->column2);

	if (game->row == game->row2 && game->column == game->column2 && game->collectibles == 0)
		congratulate_user(game);
	return (1);
}

