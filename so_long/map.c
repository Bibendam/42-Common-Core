/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:32:31 by marvin            #+#    #+#             */
/*   Updated: 2024/05/30 01:32:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map(t_game game) {
    int i = 0;
    int j;

    while (i < game.plot.height) {
        j = 0;
        while (j < game.plot.weight) {
            printf("%c", game.plot.map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

char *ft_file_get_contents(int fd) {
    char buffer[4096];
    char *file_contents = NULL;
    ssize_t read_size;

    while ((read_size = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[read_size] = '\0';
        if (file_contents == NULL) {
            file_contents = ft_strdup(buffer);
        } else {
            char *temp = ft_strjoin(file_contents, buffer);
            free(file_contents);
            file_contents = temp;
        }
    }

    if (read_size == -1) {
        free(file_contents);
        return NULL;
    }

    return file_contents;
}

void init_map(t_game *game, char *path) {
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        ft_putstr_fd("Could not open file ", 2);
        ft_putendl_fd(path, 2);
        return;
    }

    // Read the entire file into a string
    char *file_content = ft_file_get_contents(fd);
    close(fd);
    if (file_content == NULL) {
        ft_putendl_fd("Could not read file", 2);
        return;
    }

    // Split the string into lines to get the height of the map
    char **lines = ft_split(file_content, '\n');
    int height = 0;
    while (lines[height] != NULL) {
        height++;
    }

    // The width of the map is the length of the first line
    int width = ft_strlen(lines[0]);

    // Allocate memory for the map
    game->plot.map = malloc(height * sizeof(char *));
    int i = 0;
    while (i < height) {
        game->plot.map[i] = ft_strdup(lines[i]);
        i++;
    }

    // Free the lines array and the file content string
    i = 0;
    while (i < height) {
        free(lines[i]);
        i++;
    }
    free(lines);
    free(file_content);

    game->plot.height = height;
    game->plot.weight = width;
}