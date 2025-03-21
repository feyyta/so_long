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

#include "../inc/so_long.h"

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

void	set_hooks(t_window *window, t_game *game)
{
	mlx_hook(window->win, 17, 0, closewindow, game);
	mlx_hook(window->win, 2, 1L << 0, keyboard, game);
	mlx_expose_hook(window->win, ((void *)domap), game);
}

int	main(int argc, char **argv)
{
	t_window	window;
	t_map		map;
	t_game		game;
	t_img		text;
	int			arg;

	arg = 0;
	if (argc == 2)
	{
		if (!checkerror(argv[1], &map, &game))
			arg = 1;
		if (arg == 1)
			return (1);
		window.mlx = mlx_init();
		initgame(&game, &window, &map, &text);
		if (!initimg(&game, &text))
			return (1);
		set_hooks(&window, &game);
		mlx_loop(window.mlx);
	}
	else
		errormap(NULL, "need 2 arg");
	return (0);
}
