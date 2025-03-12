/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:40:28 by parallels         #+#    #+#             */
/*   Updated: 2025/03/12 23:00:31 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int countline(t_game *game, char *file)
{
    int fd;
    char *line;
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    game->rows = 0;
    line = get_next_line(fd);
    while(line)
    {
        game->rows++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}

int  fillmap(t_game *game, char *file)
{
    int fd;
    size_t len;
    char *line;
    int y;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return 0;
    y = -1;
    line = get_next_line(fd);
    while (line)
    {
        len = ft_strlen(line);
        if(len > 0 && line[len -1] == '\n')
            line[len -1] = '\0';
        game->map[++y] = line;
        line = get_next_line(fd);
    }
    game->map[++y] = NULL;
    close(fd);
    return (1);
}

int seemap(t_game *game, char *file)
{
    if (!countline(game, file))
        return (0);
    game->map = malloc(sizeof(char *)*(game->rows +1));
    if(!game->map)
        return 0;
    if (!fillmap(game, file))
    {
        freemap(game->map, game->rows);
        return (0);
    }
    game->cols = ft_strlen(game->map[0]);
    if (!validmap(game))
    {
        freemap(game->map, game->rows);
        game->map = NULL;
        return 0;
    }
    return (1);
}