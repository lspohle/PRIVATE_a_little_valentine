#include "a_little_valentine.h"

////////////////////////////////////////// Providing the user with information ///////////////////////////////////////////

// Welcomes the user
void	welcome_user(void)
{
	ft_printf(PURPLE"\n╔══════════════════════════════════════════════════╗\n");
	ft_printf(PURPLE"║"ESCAPE"              Collect the hearts! 🥰              "PURPLE"║\n");
	ft_printf(PURPLE"║"CYAN"             Surprise your valentine!             "PURPLE"║\n");
	ft_printf(PURPLE"╚══════════════════════════════════════════════════╝\n\n");
}

// Congratulates the user
void	congratulate_user(t_data *game)
{
	put_image_to_window(game, REWARD, game->row, game->column);

	ft_printf(PURPLE"\n╔══════════════════════════════════════════════════╗\n");
	ft_printf(PURPLE"║"GREEN"             🎉🥳 Congratulations! 🥳🎉           "PURPLE"║\n");
	ft_printf(PURPLE"╚══════════════════════════════════════════════════╝\n");
}

// Inform the user that the game is over
void	game_over(t_data *game)
{
	ft_printf(RED"\n╔══════════════════════════════════════════════════╗\n");
	ft_printf(RED"║"ESCAPE"            Your heart is broken! 💔              "RED"║\n");
	ft_printf(RED"║"GREEN"     However, keep going! You're strong! 😇       "RED"║\n");
	ft_printf(RED"╚══════════════════════════════════════════════════╝\n\n");

	close_window(game);
}
