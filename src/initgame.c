/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:25:37 by parallels         #+#    #+#             */
/*   Updated: 2025/03/12 23:02:13 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int init_mlx_and_window(t_game *game)
{
    int window_height;
    int window_width;

    game->mlx = mlx_init();
    if(!game->mlx)
        return (0);
    window_height = game->rows * TILE_SIZE;
    window_width = game->cols * TILE_SIZE;
    game->win = mlx_new_window(game->mlx, window_width,
         window_height, "gameu");
    if(!game->win)
        return (0);
    return (1);
}

int loadimg(t_game *game)
{
    int width;
    int height;
    
    game->wall = mlx_xpm_file_to_image(game->mlx, "../img/wall.xpm",
			&width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "../img/back.xpm",
			&width, &height);
	game->skin = mlx_xpm_file_to_image(game->mlx, "../img//ldown.xpm",
			&width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx,"../img/coin.xpm",
            &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "../img/exit.xpm",
			&width, &height);
	if (!game->wall || !game->floor|| !game->skin
		|| !game->coin|| !game->exit)
		return (0);
	return (1);
}

void *get_image_for_tile(t_game *game, int x, int y)
{
    char tile = game->map[y][x];
    
    if (tile == '1')
        return (game->wall);
    else if (tile == 'C')
        return (game->coin);
    else if (tile == 'E')
        return (game->exit);
    else
        return (game->floor);
}

void    putmap(t_game *game)
{
    int x;
    int y;
    void *img;
    char movestr[20];

    y = 0;
    while(y < game->rows)
    {
        x = 0;
        while(x < game->cols)
        {
            img = get_image_for_tile(game, y , x);
            mlx_put_image_to_window(game->mlx, game->win, img,
                x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->skin,
        game->playerx * TILE_SIZE, game->playery * TILE_SIZE);
    sprintf(movestr, "moved %d", game->move);
    mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, movestr);
}
int initgame(t_game *game)
{
    if(!init_mlx_and_window(game))
        return 0;
    if(!loadimg(game))
        return (0);
    game->move = 0;
    return (1);
}