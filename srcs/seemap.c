/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seemap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:07:21 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/15 00:07:21 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	countcols(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len);
}

int	countrows(int fd)
{
	char	*line;
	int		rows;

	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (rows);
}

int	readmap(char *ext, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(ext, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	map->cols = countcols(line);
	free(line);
	map->rows = countrows(fd) + 1;
	close(fd);
	return (1);
}

int	alloctab(t_map *map)
{
	int	i;

	map->tab = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->tab)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->tab[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!map->tab[i])
			return (0);
		i++;
	}
	map->tab[map->rows] = NULL;
	return (1);
}

int	cpymap(char *ext, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(ext, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (i < map->rows)
	{
		if (line)
		{
			ft_strlcpy(map->tab[i], line, map->cols + 1);
			free(line);
			i++;
			line = get_next_line(fd);
		}
	}
	close(fd);
	return (1);
}
