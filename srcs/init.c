/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:15 by omajdoub          #+#    #+#             */
/*   Updated: 2023/05/27 16:01:28 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initstuff(char **argv, t_game *game)
{
	game->mapname = argv[1];
	game->mapfd = open(argv[1], O_RDONLY);
	game->l_inmap = 0;
	game->c_inmap = 0;
	game->exit = 0;
	game->player = 0;
	game->collects = 0;
	game->moves = 0;
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", \
			&game->w_heigth, &game->w_weidth);
	game->imgs.backg = mlx_xpm_file_to_image(game->mlx, "./textures/ground.xpm", \
			&game->w_heigth, &game->w_weidth);
	game->imgs.player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", \
			&game->w_heigth, &game->w_weidth);
	game->imgs.coin = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm", \
			&game->w_heigth, &game->w_weidth);
	game->imgs.exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", \
			&game->w_heigth, &game->w_weidth);
}
