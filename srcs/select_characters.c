#include "a_little_valentine.h"

////////////////////////////////////////////// Selecting the images for player, exit and reward /////////////////////////////////////////////

static int select_exit(t_data *game, char *requested_exit)
{
	if (ft_strncmp(requested_exit, "W", sizeof("W")) == 0)
	{
		game->exit_path = "../images/woman.xpm";
		return (1);
	}
	else if (ft_strncmp(requested_exit, "M", sizeof("M")) == 0 ||
			 ft_strncmp(requested_exit, "O", sizeof("O")) == 0)
	{
		game->exit_path = "../images/man.xpm";
		return (2);
	}
	else
		return (0);
}

static int select_player(t_data *game, char *requested_player)
{
	if (ft_strncmp(requested_player, "W", sizeof("W")) == 0)
	{
		game->player_path = "../images/woman.xpm";
		return (1);
	}
	else if (ft_strncmp(requested_player, "M", sizeof("M")) == 0 ||
			 ft_strncmp(requested_player, "O", sizeof("O")) == 0)
	{
		game->player_path = "../images/man.xpm";
		return (2);
	}
	else
		return (0);
}

int select_characters(t_data *game, char *requested_player, char *requested_exit)
{
	if (select_exit(game, requested_exit) == 1 && select_player(game, requested_player) == 1)
		game->reward_path = "../images/coupleWW.xpm";
	else if ((select_exit(game, requested_exit) == 1 && select_player(game, requested_player) == 2) ||
			 (select_exit(game, requested_exit) == 2 && select_player(game, requested_player) == 1))
		game->reward_path = "../images/coupleWM.xpm";
	else if (select_exit(game, requested_exit) == 2 && select_player(game, requested_player) == 2)
		game->reward_path = "../images/coupleMM.xpm";
	else
		return (0);
	return (1);
}