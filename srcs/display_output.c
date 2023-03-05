#include "a_little_valentine.h"

////////////////////////////////////////// Providing the user with information ///////////////////////////////////////////

// Inform the user that the map is invalid
int	error(int errnum, char *description)
{
	char	*select_characters;
	char	*available_characters;
	char	*select_map;
	char	*available_maps;
	char	*rules_map;

	select_characters = "\nPlease select the player you favor the most and choose an image that represents your loved one.";
	available_characters = "   - W (woman)\n   - M (man)\n   - O (others)\n";
	select_map = "\nPlease select the map you would like to play on.";
	available_maps = "   - ../maps/map0.ber\n   - ../maps/map1.ber\n   - ../maps/map2.ber\n   - ../maps/map3.ber\n";
	rules_map = "   - It must be rectangular.\n   - It must be surrounded by walls.\n   - It must contain exactly one exit.\n   - It must contain exactly one starting position.\n   - It must contain at least one collectible.\n";
	ft_printf(RED"Error: "ESCAPE"%s\n", strerror(errnum));
	ft_printf(RED"%s"ESCAPE, description);
	ft_printf(GREEN"%s"ESCAPE"\nThose are the available characters:\n", select_characters);
	ft_printf(YELLOW"%s"ESCAPE, available_characters),
	ft_printf(GREEN"%s"ESCAPE"\nThose are the available maps:\n", select_map);
	ft_printf(YELLOW"%s"ESCAPE, available_maps),
	ft_printf("The map has to be valid:\n"YELLOW"%s"ESCAPE, rules_map);
	ft_printf("\nAn example is: "GREEN"./a_little_valentine ../maps/map2.ber M W\n\n"ESCAPE);
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
	put_image_to_window(game, game->reward_path, game->row, game->column);
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
