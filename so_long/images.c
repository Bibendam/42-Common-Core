/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:47:17 by marvin            #+#    #+#             */
/*   Updated: 2024/05/30 01:47:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "img.h"

void	init_window(t_game *game)
{
    game->mlx_pointer = mlx_init();
    if (is_larger_than_window(game))
    {
        free_map(game);
        mlx_destroy_display(game->mlx_pointer);
        free(game->mlx_pointer);
        endgame("Map size larger than display resolution", game, error);
    }
    else
    {
        game->window_pointer = mlx_new_window(
        game->mlx_pointer,
        (game->plot.weight * SPRITE_SIZE),
        (game->plot.height * SPRITE_SIZE),
        WINDOW_NAME);
    }
}

void	init_images(t_game	*game)
{
	game->wall = new_sprite(game->mlx_pointer, WALL_PATH);
	game->floor = new_sprite(game->mlx_pointer, FLOOR_PATH);
	game->collectible = new_sprite(game->mlx_pointer, COLLECT_PATH);
	game->portal = new_sprite(game->mlx_pointer, PORTAL_PATH);
	game->character = new_sprite(game->mlx_pointer, CHAR_DOWN_PATH);
	game->character_left = new_sprite(game->mlx_pointer, CHAR_LEFT_PATH);
	game->character_right = new_sprite(game->mlx_pointer, CHAR_RIGHT_PATH);
	game->character_up = new_sprite(game->mlx_pointer, CHAR_UP_PATH);
	return ;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}