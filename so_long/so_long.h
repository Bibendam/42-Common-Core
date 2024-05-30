/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:19:01 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/30 03:02:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>   //open, O_RDONLY
# include <stdbool.h> //bool
# include <stdio.h>   //printf
# include <stdlib.h>  //malloc
# include <unistd.h>  //read, close, write

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define WINDOW_NAME	"./so_long"
# define SPRITE_SIZE	32

# define KEY_RELEASE	3
# define DESTROY_NOTIFY	17
# define EXPOSE		12

# define KEY_RELEASE_MASK	2
# define NO_EVENT_MASK		0
# define EXPOSURE_MASK		32768

enum e_direction
{
	down,
	left,
	right,
	up,
};

enum e_state
{
	event_ending = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

typedef struct s_counter
{
	int			empty;
	int			collectible;
	int			exit;
	int			start;
	int			movements;
}				t_counter;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_img
{
	void		*ptr;
	int			*pixels;
	int			line_size;
	int			mem;
	int			x;
	int			y;
	int			movements;
}				t_img;

typedef struct s_draw
{
	char		**map;
	int			height;
	int			weight;
	char		*line;
}				t_draw;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	i;
	t_draw		plot;
	t_img		character;
	t_img		character_left;
	t_img		character_right;
	t_img		character_up;
	t_img		floor;
	t_img		wall;
	t_img		collectible;
	t_img		portal;
}				t_game;

void		render_map(t_game	*game);
void		init_map(t_game *game, char *path);

int			key_check(int keycode, t_game *game);
/*
void		print_moves(t_game *game);

void		move_right(t_game *parameter);
void		move_left(t_game *parameter);
void		move_up(t_game *parameter);
void		move_down(t_game *parameter);
*/
void		player_init(t_game	*game);
/*
int			len_map_validation(char **map, t_game *game);
*/
void		init_window(t_game *game);
void		init_images(t_game	*game);
t_img		new_sprite(void *mlx, char *path);
void		destroy_image(t_game *game);
void		free_map(t_game	*game);

int			red_cross(t_game *game);
int			mini_maker(t_game *game);
void		endgame(char *message, t_game *game, enum e_state i);
/*
t_point		get_screen_size(t_game *game);
*/
bool		is_larger_than_window(t_game *game);

bool		is_surrounded_by_trees(t_game *game, int y, int x);
bool		is_rectangular(t_game *game);
bool		is_valid_character(t_game *game, int y, int x);
bool		is_double_line(char *string_map, int i);
void		is_elements_number_valid(t_game *game, t_counter *cnt, char *temp);
/*
int			open_file(char *path);
t_counter	new_counter(void);
*/
#endif
