/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:19:01 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/29 15:38:39 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>   //open, O_RDONLY
# include <stdbool.h> //bool
# include <stdio.h>   //printf
# include <stdlib.h>  //malloc
# include <unistd.h>  //read, close, write

void			render_map(t_game game);
void			init_map(t_gamegame, char path);

int				key_check(int keycode, t_gamegame);
void			print_moves(t_game game);

void			move_right(t_gameparameter);
void			move_left(t_game parameter);
void			move_up(t_gameparameter);
void			move_down(t_game *parameter);

void			player_init(t_game game);
int				len_map_validation(char **map, t_gamegame);

void			init_window(t_game *game);
void			init_images(t_game game);
t_img			new_sprite(voidmlx, char path);
void			destroy_image(t_gamegame);
void			free_map(t_game game);

int				red_cross(t_gamegame);
int				mini_maker(t_game game);
void			endgame(charmessage, t_game game, enum e_state i);

t_point			get_screen_size(t_gamegame);
bool			is_larger_than_window(t_game game);

bool			is_surrounded_by_trees(t_gamegame, int y, int x);
bool			is_rectangular(t_game game);
bool			is_valid_character(t_gamegame, int y, int x);
bool			is_double_line(char string_map, int i);
void			is_elements_number_valid(t_gamegame, t_counter cnt, chartemp);

int				open_file(char *path);
t_counter		new_counter(void);

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
	t_img		character_down;
	t_img		character_left;
	t_img		character_right;
	t_img		character_up;
	t_img		floor;
	t_img		wall;
	t_img		collectible;
	t_img		portal;
}				t_game;

#endif
