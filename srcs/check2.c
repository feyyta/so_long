/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:06:42 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:06:42 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	checkplayer(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->tab[i][j] == 'P')
			{
				map->start_x = j;
				map->start_y = i;
				return (1);
			}
		}
	}
	return (0);
}

int	checkwalls(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->cols)
		if (map->tab[0][i] != '1' || map->tab[map->rows - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < map->rows)
		if (map->tab[i][0] != '1' || map->tab[i][map->cols - 1] != '1')
			return (0);
	return (1);
}

int	checkext(char *ext)
{
	int	len;

	len = ft_strlen(ext);
	if (len < 5)
		return (0);
	return (ft_strncmp(ext + len - 4, ".ber", 4) == 0);
}

void	initmapvalues(t_map *map)
{
	map->tab = NULL;
	map->cols = 0;
	map->rows = 0;
	map->collectibles = 0;
	map->start_x = -1;
	map->start_y = -1;
	map->exit_x = -1;
	map->exit_y = -1;
	map->player_count = 0;
	map->exit_count = 0;
}
