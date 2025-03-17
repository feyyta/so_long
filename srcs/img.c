/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:06:55 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:06:55 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initimg(t_game *game, t_img *text)
{
	text->floor = mlx_xpm_file_to_image(game->window->mlx,
			"img/floor/wooden.xpm", &text->cols, &text->rows);
	text->wall = mlx_xpm_file_to_image(game->window->mlx,
			"img/wall/wall.xpm", &text->cols, &text->rows);
	text->player = mlx_xpm_file_to_image(game->window->mlx,
			"img/player/player.xpm", &text->cols, &text->rows);
	text->collect = mlx_xpm_file_to_image(game->window->mlx,
			"img/collectible/collectible.xpm", &text->cols, &text->rows);
	text->exit = mlx_xpm_file_to_image(game->window->mlx,
			"img/exit/exit.xpm", &text->cols, &text->rows);
	if (!text->floor || !text->wall || !text->player
		|| !text->collect || !text->exit)
		return (0);
	return (1);
}

void	destroytext(t_game *game, t_img *text)
{
	if (text->player)
		mlx_destroy_image(game->window->mlx, text->player);
	if (text->floor)
		mlx_destroy_image(game->window->mlx, text->floor);
	if (text->wall)
		mlx_destroy_image(game->window->mlx, text->wall);
	if (text->collect)
		mlx_destroy_image(game->window->mlx, text->collect);
	if (text->exit)
		mlx_destroy_image(game->window->mlx, text->exit);
}
