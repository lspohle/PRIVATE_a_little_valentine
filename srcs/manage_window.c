#include "a_little_valentine.h"

///////////////////////////////////////////// Providing necessities //////////////////////////////////////////////////////

// Puts a pixel on the screen
static void	my_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Puts a specific image to the window
void		put_image_to_window(t_data *game, char *relative_path, int row, int column)
{
	game->img = mlx_xpm_file_to_image(game->mlx, relative_path, &game->img_width, &game->img_height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	my_mlx_pixel_put(game, game->mlx_width, game->mlx_height, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win, game->img, column * INDEX, row * INDEX);
}

// Closes a window instance accordingly
int    close_window(t_data *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
	return (1);
}

// Get width and height of the window depending on the selected map
void	get_measurements(t_data *game, char *map)
{
	if (ft_strncmp(map, MAP_1, sizeof(MAP_1)) == 0)
	{
		game->mlx_width = 1200;
		game->mlx_height = 470;
	}
	else if (ft_strncmp(map, MAP_2, sizeof(MAP_2)) == 0)
	{
		game->mlx_width = 720;
		game->mlx_height = 480;
	}
	else if (ft_strncmp(map, MAP_3, sizeof(MAP_3)) == 0)
	{
		game->mlx_width = 1515;
		game->mlx_height = 900;
	}
}