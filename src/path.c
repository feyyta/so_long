/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:51:34 by parallels         #+#    #+#             */
/*   Updated: 2025/03/12 23:00:03 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int **visited(t_game *game)
{
    int **tab;
    int y;
    int x;

    tab = malloc(sizeof(int *)*game->rows + 1);
    if(!tab)
        return (NULL);
    y = -1;
    while(++y < game->rows)
    {
        tab[y] = malloc(sizeof(int *)*game->cols + 1);
        if (!tab[y])
            return NULL;
        x = -1;
        while(++x < game->cols)
            tab[y][x] = 0;
    }
    return (tab);
}

void    seein(t_game *game, int **tab, int y, int x)
{
    if(y < 0 || x < 0 || y >=game->rows || x >= game->cols
        || tab[y][x] || game->map[y][x] == '1')
        return ;
    tab[y][x] = 1;
    seein(game, tab, y - 1, x);
    seein(game, tab, y + 1, x);
    seein(game, tab, y, x - 1);
    seein(game, tab, y, x + 1);
}

int checkreach(t_game *game, int **tab)
{
    int i;
    int j;
    int c;
    int e;

    i = -1;
    c = 0;
    e = 0;
    while(++i < game->rows)
    {
        j = -1;
        while(++j < game->rows)
        {
            if(tab[i][j])//si ca a ete visite
            {
                c += (game->map[i][j] == 'C');
                e |= (game->map[i][j] == 'E');
            }
        }
    }
    return (c == game->collect && e);
}
int path(t_game *game)
{
    int **tab;
    int res;
    
    tab = visited(game);
    if(!tab)
        return (0);
    seein(game, tab, game->playery, game->playery);
    res = checkreach(game, tab);
    freetab((void **)tab, game->rows);
    return (res);
}