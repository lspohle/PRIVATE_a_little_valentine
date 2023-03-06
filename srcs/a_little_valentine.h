#ifndef A_LITTLE_VALENTINE_H
# define A_LITTLE_VALENTINE_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h> 
# include <string.h>
# include <errno.h>
# include <stdbool.h>

# define GAME "Your Little Valentine"
# define INDEX 80

# define CYAN "\e[38;5;51m"
# define GREEN "\e[38;5;47m"
# define PURPLE "\e[38;5;219m"
# define YELLOW "\e[38;5;227m"
# define RED "\e[38;5;196m"
# define ESCAPE "\033[0m"

# define EMPTY "../images/empty.xpm"
# define WALL "../images/wall.xpm"
# define COLLECTIBLE "../images/heart.xpm"
# define RIVAL "../images/broken_heart.xpm"

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
	int		player;
	char	*player_path;
	int		exit;
	char	*exit_path;
	char	*reward_path;
	int		components;
	
	int		column;
	int		row;
	int		column2;
	int		row2;
	int		moves;
	int		collectibles;
	int		max_collectibles;
	bool	won;
}				t_data;

int		check_map(t_data *game);
int		error(int errnum, char *description);
void	welcome_user(t_data *game);
int		read_map(t_data *game, char *map);
int 	select_characters(t_data *game, char *requested_player, char *requested_exit);
int		create_map(t_data *game);
int		play_game(int keycode, t_data *game);
void	put_image_to_window(t_data *game, char *relative_path, int row, int column);
int		close_window(t_data *game);
void	congratulate_user(t_data *game);
void	game_over(t_data *game);

#endif
