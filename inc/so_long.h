/* ************************************************************************** */ /*                                                                            */ /*                                                        :::      ::::::::   */ /*   so_long.h                                          :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */ /*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:19:09 by parallels         #+#    #+#             */
/*   Updated: 2025/03/12 14:20:55 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "../mlx/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"

# define TILE_SIZE 64

typedef struct s_game
{
    char **map;
    int rows;
    int cols;
    int playerx;
    int playery;
    int collect;
    int move;
    int collected;
    void    *mlx;
    void    *win;
    void *wall;
    void *floor;
    void *skin;
    void *coin;
    void *exit;

}   t_game;

int keygest(int key,t_game *game);
int	exitgame(t_game *game);
void    freetab(void **tab, int height);
void	freemap(char **map, int rows);
int keygest(int key,t_game *game);
void    move(t_game *game, int y, int x);
int canmove(t_game *game, int y, int x);
int initgame(t_game *game);
void    putmap(t_game *game);
int loadimg(t_game *game);
int init_mlx_and_window(t_game *game);
int seemap(t_game *game, char *file);
int  fillmap(t_game *game, char *file);
int countline(t_game *game, char *file);
int path(t_game *game);
int checkreach(t_game *game, int **tab);
void    seein(t_game *game, int **tab, int y, int x);
int **visited(t_game *game);
int validmap(t_game *game);
int walls(t_game *game);
void    countelems(t_game *game, char c, int *count);
int maprectang(t_game *game);
int validmapchar(t_game *game);
int validchar(char c);
void *get_image_for_tile(t_game *game, int x, int y);
//ft


#endif