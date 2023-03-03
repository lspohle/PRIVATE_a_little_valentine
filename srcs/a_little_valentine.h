#ifndef A_LITTLE_VALENTINE_H
# define A_LITTLE_VALENTINE_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
// # include <unistd.h> // close (2) // write(2) // read(2)
// # include <stdlib.h> // malloc // free // exit
# include <fcntl.h> // open(2)
# include <stdio.h> // perror // strerror
# include <math.h> 
# define GAME "Your Little Valentine"
# define INDEX 80

# define CYAN "\e[38;5;51m"
# define GREEN "\e[38;5;47m"
# define PURPLE "\e[38;5;219m"
# define RED "\e[38;5;196m"
# define ESCAPE "\033[0m"

# define MAP_0 "../maps/map0.ber"
# define MAP_1 "../maps/map1.ber"
# define MAP_2 "../maps/map2.ber"
# define MAP_3 "../maps/map3.ber"

# define EMPTY "../images/empty.xpm"
# define WALL "../images/wall.xpm"
# define COLLECTIBLE "../images/heart.xpm"
# define RIVAL "../images/broken_heart.xpm"
# define EXIT "../images/man.xpm"
# define PLAYER "../images/woman.xpm"
# define REWARD "../images/couple.xpm"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	int		mlx_width;
	int		mlx_height;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;

	char	**map;
	int		map_width;
	int		map_height;
	int		column;
	int		row;
	
	int		player_column;
	int		player_row;
	int		moves;
	int		collectibles;
	int		max_collectibles;
}				t_data;

void	welcome_user(void);
void	get_measurements(t_data *game, char *map);
int		read_map(t_data *game, char *map);
void	create_map(t_data *game);
int		play_game(int keycode, t_data *game);
void	put_image_to_window(t_data *game, char *relative_path, int row, int column);
int		close_window(t_data *game);
void	congratulate_user(t_data *game);
void	game_over(t_data *game);

#endif