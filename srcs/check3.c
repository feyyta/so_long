/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:06:47 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:06:47 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkcols(char *line, int cols)
{
	int	actualcols;

	actualcols = countcols(line);
	return (actualcols == cols);
}

int	checkrectang(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		colsneeded;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	colsneeded = map->cols;
	while (line)
	{
		if (!checkcols(line, colsneeded))
		{
			free(line);
			get_next_line(-42);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	checkchars(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (!ft_strchr("01CEP", map->tab[i][j]))
				return (0);
		}
	}
	return (1);
}

void	freemap(t_map *map)
{
	int	i;

	if (!map || !map->tab)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	map->tab = NULL;
}
