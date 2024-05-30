/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:01:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/29 23:01:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Check if the given position is surrounded by trees
bool is_surrounded_by_trees(t_game *game, int y, int x)
{
	bool isTopTree;
	bool isBottomTree;
	bool isLeftTree;
	bool isRightTree;
	bool isTree;

	isTopTree = game->plot.map[0][x] == '1';
	isBottomTree = game->plot.map[game->plot.height - 1][x] == '1';
	isLeftTree = game->plot.map[y][0] == '1';
	isRightTree = game->plot.map[y][game->plot.length - 1] == '1';
	isTree = isTopTree && isBottomTree && isLeftTree && isRightTree;
	return isTree;
}

// Check if the plot is rectangular
bool is_rectangular(t_game *game)
{
	return game->plot.height != game->plot.length;
}

// Check if the character at the given position is valid
bool is_valid_character(t_game *game, int y, int x)
{
	return ft_strchr("01CEP", game->plot.map[y][x]) != NULL;
}

// Check if the given position in the string map is a double line
bool is_double_line(char *string_map, int i)
{
	char current_char;
	char next_char;
	bool is_current_newline;
	bool is_next_newline_or_end;
	bool is_double_line;

	current_char = string_map[i];
	next_char = string_map[i + 1];
	is_current_newline = current_char == '\n';
	is_next_newline_or_end = ft_strchr("\n\0", next_char) != NULL;
	is_double_line = is_current_newline && is_next_newline_or_end;
	return is_double_line;
}

// Check if the number of elements is valid
void is_elements_number_valid(t_game *game, t_counter *count, char *temp)
{
	bool isValid;
	bool isValid2;

	isValid = count->collectible > 0 && count->exit == 1;
	isValid2 = count->start == 1 && count->empty > 0;
	if (!isValid && !isValid2)
	{
		free(temp);
		endgame("Invalid, file!", game, file_error);
	}
}