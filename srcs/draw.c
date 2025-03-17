/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:06:51 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:06:51 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

	/*movetxt = ft_strlen("u move ") + ft_strlen((move) + 1 );
	txt = malloc(movetxt);
	if(!txt)
	{
		free(move);
		return ;
	}*/
/*ft_strlcpy(txt, "u move ", movetxt);
	ft_strlcat(txt, move, movetxt);
	mlx_string_put(game->window->mlx,
		game->window->win,40, 20, 0xFFFFFF,txt);
	free(txt);
	free(move);*/
void	domap(t_game *game)
{
	char	*move;

	mlx_clear_window(game->window->mlx, game->window->win);
	drawback(game);
	drawcep(game);
	move = ft_itoa(game->moves);
	ft_printf("u move : %s time\n", move);
	free(move);
}

void	drawback(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (game->map->tab[y][x] != '1')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->text->floor, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map->tab[y][x] == '1')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->text->wall, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	drawcep(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (game->map->tab[y][x] == 'C')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->text->collect, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->tab[y][x] == 'E')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->text->exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->tab[y][x] == 'P')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->text->player, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
