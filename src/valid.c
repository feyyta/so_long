/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2025/03/12 15:22:06 by parallels         #+#    #+#             */ /*   Updated: 2025/03/12 15:29:53 by parallels        ###   ########.fr       */ /*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h" 

int validchar(char c)
{
     return(c == 'C' || c == 'E' || c == '1' || c == '0' || c == 'P');
}
int validmapchar(t_game *game)
{
    int y;
    int x;

    y = -1;
    while (++y < game->rows)
    {
        x = -1;
        while(++x < game->cols)
            if(!validchar(game->map[y][x]))
                return 0;
    }
    return (1);
}

int maprectang(t_game *game)
{
    size_t len;
    int y;

    y = 0;
    if (game->rows == 0)
        return (0);
    len = ft_strlen(game->map[0]);
    while(++y < game->rows)
        if((size_t)(game->map[y]) != len)
            return (0);
    return (1);
}

void    countelems(t_game *game, char c, int *count)
{
    int x;
    int y;

    y = -1;
    *count = 0;
    while(++y < game->rows)
    {
        x = -1;
        while(++x < game->cols)
        {
            if(game->map[y][x] == 'P')
            {
                game->playerx = x;
                game->playery = y;
            }
            if (game->map[y][x] == c)
                (*count)++;
        }
    }
}
int walls(t_game *game)
{
    int x;
    int y;

    y = -1;
    while(++y < game->rows)
    {
        x = -1;
        while(++x < game->cols)
        {
            if((y == 0 || y == game->rows -1 
                || x == 0 || x == game->cols - 1 ) && game->map[y][x] != 1)
                return (0);
        }
    }
    return (1);
}

int validmap(t_game *game)
{
    int p;
    int e;
    int c;
    
    p = 0;
    e = 0;
    c = 0;
    if (!validmapchar(game))
        return(ft_printf("not valid char\n"), 0);
    if (!maprectang(game))
        return(ft_printf("need rectang map\n", 0));
    countelems(game, 'P', &p);
    countelems(game, 'E', &e);
    countelems(game, 'C', &c);
    if (!walls(game))
        return (ft_printf("need walls\n", 0));
    if ( p != 1 || e != 1 || c < 1)
        return (ft_printf("not good  p e c\n"), 0);
    if (!path(game))
        return(ft_printf("not good path\n", 0));
    return (1);
}