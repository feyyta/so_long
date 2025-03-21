/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:43:18 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/14 20:43:18 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*tag each accessible pos by 1 ine the map*/
void	visitmap(t_map *map, int x, int y, char **visited)
{
	if (x < 0 || x >= map->cols || y < 0 || y >= map->rows)
		return ;
	if (map->tab[y][x] == '1' || visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	visitmap(map, x, y + 1, visited);
	visitmap(map, x, y - 1, visited);
	visitmap(map, x + 1, y, visited);
	visitmap(map, x - 1, y, visited);
}
/*init by 0 the tab visited then call visitmap then check if we 
succed to visit exit and coins so the path is ok then free visited*/

int	checkpath(t_map *map)
{
	char	**visited;
	int		i;
	int		valid;

	i = -1;
	visited = malloc(sizeof(char *) * map->rows);
	if (!visited)
		return (0);
	while (++i < map->rows)
	{
		visited[i] = ft_calloc(map->cols, sizeof(char));
		if (!visited[i])
			return (0);
	}
	visitmap(map, map->start_x, map->start_y, visited);
	valid = checkvalidpath(map, visited);
	i = 0;
	while (i < map->rows)
		free(visited[i++]);
	free(visited);
	return (valid);
}

int	checkvalidpath(t_map *map, char **visited)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->tab[i][j] == 'C' && !visited[i][j])
				return (0);
			if (map->tab[i][j] == 'E' && !visited[i][j])
				return (0);
		}
	}
	return (1);
}
