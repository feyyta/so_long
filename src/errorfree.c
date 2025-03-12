/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:08:23 by parallels         #+#    #+#             */
/*   Updated: 2025/03/12 23:01:47 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	freemap(char **map, int rows)
{
	int	y;

	if (!map)
		return ;
	y = -1;
	while (++y < rows)
		free(map[y]);
	free(map);
}

void    freetab(void **tab, int height)
{
    int i;
    if(!tab)
        return ;
    i = -1;
    while(++i < height)
        free(tab[i]);
    free(tab);
}

int	exitgame(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->rows && game->map[i])
		free(game->map[i]);
	free(game->map);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->skin)
		mlx_destroy_image(game->mlx, game->skin);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}