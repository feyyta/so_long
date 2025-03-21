/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:07:58 by mcastrat          #+#    #+#             */
/*   Updated: 2025/03/20 16:56:31 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define TILE_SIZE 64

typedef struct s_map
{
	char	**tab;
	int		rows;
	int		cols;
	int		collectibles;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	int		player_count;
	int		exit_count;
}	t_map;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
	int		cols;
	int		rows;
}	t_img;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_img		*text;
	int			remaining;
	int			collectibles;
	int			collected;
	int			moves;
}	t_game;

int		initgame(t_game *game, t_window *window, t_map *map, t_img *text);
void	set_hooks(t_window *window, t_game *game);
int		checkelements(t_map *map, t_game *game);
int		checkerror(char *ext, t_map *map, t_game *game);
void	errormap(t_map *map, char *msg);
void	visitmap(t_map *map, int x, int y, char **visited);
int		checkpath(t_map *map);
int		checkvalidpath(t_map *map, char **visited);
int		countcols(char *line);
int		countrows(int fd);
int		readmap(char *ext, t_map *map);
int		alloctab(t_map *map);
int		cpymap(char *ext, t_map *map);
int		checkwalls(t_map *map);
int		checkext(char *filename);
void	initmapvalues(t_map *map);
int		checkplayer(t_map *map);
int		checkcols(char *line, int cols);
int		checkrectang(char *ext, t_map *map);
int		checkchars(t_map *map);
void	freemap(t_map *map);
int		keyboard(int keysym, t_game *game);
int		move(t_game *game, int dx, int dy);
void	destroytext(t_game *game, t_img *text);
int		initimg(t_game *game, t_img *text);
void	drawcep(t_game *game);
void	drawback(t_game *game);
void	domap(t_game *game);
int		closewindow(void *gameu);

#endif