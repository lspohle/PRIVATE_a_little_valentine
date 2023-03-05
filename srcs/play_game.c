#include "a_little_valentine.h"

/////////////////////////////////////////////// The heart of the program /////////////////////////////////////////////////

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		t_data		game;

		ft_memset(&game, 0, sizeof(t_data));	
		if (read_map(&game, argv[1]) == 0)
			return (error(ENOENT, ""));
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.map_width * 80, game.map_height * 80, GAME);
		if (select_characters(&game, argv[2], argv[3]) == 0)
			return (error(EINVAL, "The amount of arguments is invalid!\n"));
		if (create_map(&game) == 0)
			return (0);
		welcome_user(&game);
		mlx_key_hook(game.win, play_game, &game);
		mlx_hook(game.win, 17, 1L << 0, close_window, &game);
		mlx_loop(game.mlx);
	}
	else
		return (error(EINVAL, "The amount of arguments is invalid!\n"));
	return (1);
}