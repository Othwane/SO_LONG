/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:15 by omajdoub          #+#    #+#             */
/*   Updated: 2023/06/03 21:49:58 by omajdoub         ###   ########.fr       */
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
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx, \
			"./textures/wall.xpm", &game->w_heigth, &game->w_weidth);
	game->imgs.backg = mlx_xpm_file_to_image(game->mlx, \
			"./textures/ground.xpm", &game->w_heigth, &game->w_weidth);
	game->imgs.player = mlx_xpm_file_to_image(game->mlx, \
			"./textures/player.xpm", &game->w_heigth, &game->w_weidth);
	game->imgs.coin = mlx_xpm_file_to_image(game->mlx, \
			"./textures/coin.xpm", &game->w_heigth, &game->w_weidth);
	game->imgs.exit = mlx_xpm_file_to_image(game->mlx, \
			"./textures/exit.xpm", &game->w_heigth, &game->w_weidth);
}

t_pos	get_pos(char **map, char c)
{
	t_pos	pos;
	int		index1;
	int		index2;

	pos.x = -1;
	pos.y = -1;
	index1 = 0;
	while (map[index1])
	{
		index2 = 0;
		while (map[index1][index2])
		{
			if (map[index1][index2] == c)
			{
				pos.x = index2;
				pos.y = index1;
				return (pos);
			}
			index2++;
		}
		index1++;
	}
	return (pos);
}

void	check_noneeded(t_game *game)
{
	int	i;
	int	ii;

	i = 0;
	while (game->map[i])
	{
		ii = 0;
		while (game->map[i][ii])
		{
			if (game->map[i][ii] != '0' \
					&& game->map[i][ii] != '1' \
					&& game->map[i][ii] != 'P' \
					&& game->map[i][ii] != 'C' \
					&& game->map[i][ii] != 'E' \
					&& game->map[i][ii] != '\n')
				errorf(1);
			ii++;
		}
		i++;
	}
}

char	get_in_pos(t_game *game, int x, int y)
{
	int	i;
	int	ii;

	i = 0;
	while (game->map[i])
	{
		ii = 0;
		while (game->map[i][ii])
		{
			if (i == y && ii == x)
				return (game->map[i][ii]);
			ii++;
		}
		i++;
	}
	return (0);
}
