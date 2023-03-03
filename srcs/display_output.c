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

	printf(PURPLE"\n╔══════════════════════════════════════════════════╗\n");
	printf(PURPLE"║"GREEN"             🎉🥳 Congratulations! 🥳🎉           "PURPLE"║\n");
	printf(PURPLE"╚══════════════════════════════════════════════════╝\n");
}