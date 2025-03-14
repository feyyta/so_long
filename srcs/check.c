/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:06:34 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:06:34 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkerror(char *ext, t_map *map, t_game *game)
{
	initmapvalues(map);
	if (!checkext(ext))
		errormap(map, "need .ber file");
	if (!readmap(ext, map))
		errormap(map, "can t read the map");
	if (!checkrectang(ext, map))
		errormap(map, "need rectangular map");
	if (!alloctab(map))
		errormap(map, "alloc error");
	if (!cpymap(ext, map))
		errormap(map, "map content error");
	if (!checkchars(map))
		errormap(map, "characters error");
	if (!checkelements(map, game))
		errormap(map,
			"need 1 'P' , 1 'E', 1 'C'");
	if (!checkplayer(map))
		errormap(map, "player pos error");
	if (!checkwalls(map))
		errormap(map, "need walls");
	if (!checkpath(map))
		errormap(map, "path error");
	return (1);
}

void	errormap(t_map *map, char *msg)
{
	if (map && map->tab)
		freemap(map);
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	checkelements(t_map *map, t_game *game)
{
	int	i;
	int	j;
	int	pc;
	int	ec;
	int	cc;

	pc = 0;
	ec = 0;
	cc = 0;
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->tab[i][j] == 'P')
				pc++;
			if (map->tab[i][j] == 'E')
				ec++;
			if (map->tab[i][j] == 'C')
				cc++;
		}
	}
	game->collectibles = cc;
	return (pc == 1 && ec == 1 && cc > 0);
}
