/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:07:05 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:07:05 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard(int keysym, t_game *game)
{
	int	moved;

	moved = 0;
	if (keysym == 65307)
		closewindow(game);
	else if (keysym == 119 || keysym == 65362)
		moved = move(game, 0, -1);
	else if (keysym == 115 || keysym == 65364)
		moved = move(game, 0, 1);
	else if (keysym == 97 || keysym == 65361)
		moved = move(game, -1, 0);
	else if (keysym == 100 || keysym == 65363)
		moved = move(game, 1, 0);
	if (moved)
		domap(game);
	return (0);
}

int	move(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->start_x + dx;
	new_y = game->map->start_y + dy;
	if (game->map->tab[new_y][new_x] == '1')
		return (0);
	if (game->map->tab[new_y][new_x] == 'E'
		&& game->collected != game->collectibles)
		return (0);
	if (game->map->tab[new_y][new_x] == 'E'
		&& game->collected == game->collectibles)
	{
		ft_printf("GG WP\n");
		closewindow(game);
	}
	if (game->map->tab[new_y][new_x] == 'C')
		game->collected++;
	game->map->tab[game->map->start_y][game->map->start_x] = '0';
	game->map->start_x = new_x;
	game->map->start_y = new_y;
	game->map->tab[new_y][new_x] = 'P';
	game->moves++;
	return (1);
}

int	closewindow(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->map && game->map->tab)
		freemap(game->map);
	destroytext(game, game->text);
	mlx_destroy_window(game->window->mlx, game->window->win);
	mlx_destroy_display(game->window->mlx);
	free(game->window->mlx);
	exit(0);
}
