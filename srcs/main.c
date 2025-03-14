/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:07:14 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:12:09 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	window;
	t_map		map;
	t_game		game;
	t_img	text;
	int		arg;
	
	arg = 0;
	if (argc != 2)
		errormap(NULL, "need 2 arg");
	if (!checkerror(argv[1], &map, &game))
		arg = 1;
	if (arg == 1)
		return(1);
	window.mlx = mlx_init();
	initgame(&game, &window, &map, &text);
	if (!initimg(&game, &text))
		return (1);
	set_hooks(&window, &game);
	mlx_loop(window.mlx);
	return (0);
}
