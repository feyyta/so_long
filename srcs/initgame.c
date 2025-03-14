/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:06:59 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:06:59 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initgame(t_game *game, t_window *window, t_map *map, t_img *text)
{
	game->window = window;
	game->map = map;
	game->text = text;
	game->collected = 0;
	game->moves = 0;
	window->win = mlx_new_window(window->mlx, map->cols * TILE_SIZE,
			map->rows * TILE_SIZE, "gameuuu");
	if (!window->win)
		return (0);
	return (1);
}

int	init_mlx(t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		return (0);
	window->win = mlx_new_window(window->mlx, 800, 600, "so_long");
	if (!window->win)
	{
		free(window->mlx);
		return (0);
	}
	return (1);
}

void	set_hooks(t_window *window, t_game *game)
{
	mlx_hook(window->win, 17, 0, closewindow, game);
	mlx_hook(window->win, 2, 1L << 0, keyboard, game);
	mlx_expose_hook(window->win, ((void *)domap), game);
}
