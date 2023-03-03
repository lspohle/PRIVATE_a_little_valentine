#include "a_little_valentine.h"

/////////////////////////////////////////////// The heart of the program /////////////////////////////////////////////////

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_data		game;

		ft_memset(&game, 0, sizeof(t_data));	
		get_measurements(&game, argv[1]);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.mlx_width, game.mlx_height, GAME);

		if (read_map(&game, argv[1]) == 0)
		{
			perror(RED"Error"ESCAPE);
			return (0);
		}
		create_map(&game);
		welcome_user();

		mlx_key_hook(game.win, play_game, &game);
		mlx_hook(game.win, 17, 1L << 0, close_window, &game);
		mlx_loop(game.mlx);
	}
}