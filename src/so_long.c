/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:25:31 by parallels         #+#    #+#             */
/*   Updated: 2025/03/12 23:01:16 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    char *form;
    
    if (argc != 2)
        return (ft_printf("arg error\n"),1);
    form = ft_strrchr(argv[1], '.');
    if (!form || ft_strcmp(form, ".ber") != 0)
        return (ft_printf("only .ber accepted\n"), 1);
    ft_memset(&game, 0, sizeof(t_game));
    if(!seemap(&game, argv[1]))
        return (ft_printf("map error\n"), 1);
    if (!initgame(&game))
        return (ft_printf("game init error\n"), exitgame(&game), 1);
    putmap(&game);
    mlx_hook(game.win, 2,1L<<0, keygest, &game);
    mlx_hook(game.win, 17, 0, (int(*)())exitgame, &game);
    mlx_loop(game.mlx);
    exitgame(&game);
    return (0);
}