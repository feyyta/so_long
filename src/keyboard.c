/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:40:21 by parallels         #+#    #+#             */
/*   Updated: 2025/03/12 23:01:30 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int canmove(t_game *game, int y, int x)
{
    if(y < 0 || x < 0 || y >= game->rows || x >= game->cols)
        return (0);
    if(game->map[y][x] == '1')
        return (0);
    if(game->map[y][x] == 'E' && game->collect != game->collected)
        return (0);
    return(1);
}

void    move(t_game *game, int y, int x)
{
    int dy;
    int dx;

    dy = game->playery + y;
    dx = game->playerx + x;

    if(!canmove(game, dy, dx))
        return ;
    game->move++;
    ft_printf("moves %d\n", game->move);
    if(game->map[dy][dx] == 'C')
    {
        game->collected++;
        game->map[dy][dx] = '0';
    }
   game->map[game->playery][game->playerx] = '0';
   game->playery = dy;
   game->playerx = dx;
   if(game->map[game->playery][game->playerx] == 'E' 
        && game->collect == game->collected)
    {
        ft_printf("gg wp u moved : %d\n", game->move);
        exitgame(game);
    } 
    putmap(game);
}
int keygest(int key,t_game *game)
{
    ft_printf("press key %d\n", key);
    if(key == 65037)
        exitgame(game);
    else if(key == 119)//w
        move(game, -1, 0 );
    else if(key == 115)//s
        move(game, 1, 0);
    else if(key == 97)//a
        move(game, 0, -1);
    else if (key == 100)//d
        move(game, 0, 1);
    return (0);
}