#include "a_little_valentine.h"

////////////////////////////////////////// Providing the user with information ///////////////////////////////////////////

// Inform the user that the map is invalid
int	error(int errnum, char *description)
{
	char	*appeal;
	char	*instructions;
	char	*rules;

	appeal = "Please pass a map as an argument following the executable 'a_little_valentine'.\n";
	instructions = "The map has to be valid:\n";
	rules ="   - It must be rectangular.\n   - It must be surrounded by walls.\n   - It must contain exactly one exit.\n   - It must contain exactly one starting position.\n   - It must contain at least one collectible.\n";
	ft_printf(RED"Error: "ESCAPE"%s\n", strerror(errnum));
	ft_printf(RED"%s", description);
	ft_printf(GREEN"%s"ESCAPE, appeal);
	ft_printf("%s", instructions);
	ft_printf(YELLOW"%s"ESCAPE, rules);
	return (0);
}

// Welcomes the user
void	welcome_user(t_data *game)
{
	game->won = false;
	ft_printf(PURPLE"\n╔══════════════════════════════════════════════════╗\n");
	ft_printf(PURPLE"║"ESCAPE"              Collect the hearts! 🥰              "PURPLE"║\n");
	ft_printf(PURPLE"║"CYAN"             Surprise your valentine!             "PURPLE"║\n");
	ft_printf(PURPLE"╚══════════════════════════════════════════════════╝\n\n"ESCAPE);
}

// Congratulates the user
void	congratulate_user(t_data *game)
{
	put_image_to_window(game, REWARD, game->row, game->column);
	if (game->won == false)
	{
		ft_printf(PURPLE"\n╔══════════════════════════════════════════════════╗\n");
		ft_printf(PURPLE"║"GREEN"             🎉🥳 Congratulations! 🥳🎉           "PURPLE"║\n");
		ft_printf(PURPLE"╚══════════════════════════════════════════════════╝\n"ESCAPE);
		game->won = true;
	}
}

// Inform the user that the game is over
void	game_over(t_data *game)
{
	ft_printf(RED"\n╔══════════════════════════════════════════════════╗\n");
	ft_printf(RED"║"ESCAPE"            Your heart is broken! 💔              "RED"║\n");
	ft_printf(RED"║"GREEN"     However, keep going! You're strong! 😇       "RED"║\n");
	ft_printf(RED"╚══════════════════════════════════════════════════╝\n\n"ESCAPE);
	close_window(game);
}
