/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:33 by omajdoub          #+#    #+#             */
/*   Updated: 2023/05/27 16:09:11 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

int	leave(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->imgs.backg);
	mlx_destroy_image(game->mlx, game->imgs.wall);
	mlx_destroy_image(game->mlx, game->imgs.player);
	mlx_destroy_image(game->mlx, game->imgs.coin);
	mlx_destroy_image(game->mlx, game->imgs.exit);
	free_map(game->map);
	free(game->mapx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		errorf(1);
	argschecker(argv);
	initstuff(argv, &game);
	readmap(&game);
	mapchecker(&game);
	check_valid_path(&game);
	check_map_size(&game);
	playgame(&game);
	return (0);
}