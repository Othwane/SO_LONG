/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rungame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:43:42 by omajdoub          #+#    #+#             */
/*   Updated: 2023/05/27 11:34:19 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw(t_game *game, int i, int ii)
{
	if (game->map[i][ii] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->imgs.wall, ii * 64, i * 64);
	else if (game->map[i][ii] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->imgs.backg, ii * 64, i * 64);
	else if (game->map[i][ii] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->imgs.player, ii * 64, i * 64);
	else if (game->map[i][ii] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->imgs.coin, ii * 64, i * 64);
	else if (game->map[i][ii] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
				game->imgs.exit, ii * 64, i * 64);
}

void	drawmap(t_game *game)
{
	int	i;
	int	ii;

	i = 0;
	while (game->map[i])
	{
		ii = 0;
		while (game->map[i][ii])
		{
			draw(game, i, ii);
			ii++;
		}
		i++;
	}
}

void	change_char_in_map(t_game *game, t_pos ppostion, \
		t_pos nextposition)
{
	int	i;
	int	ii;

	i = 0;
	while (game->map[i])
	{
		ii = 0;
		while (game->map[i][ii])
		{
			if (i == ppostion.y && ii == ppostion.x)
				game->map[i][ii] = '0';
			if (i == nextposition.y && ii == nextposition.x)
				game->map[i][ii] = 'P';
			ii++;
		}
		i++;
	}
	drawmap(game);
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

int	handle_event(int keycode, t_game *game)
{
	t_pos	pposition;

	pposition = get_pos(game->map, 'P');
	if (keycode == 0)
		go_left(game, pposition);
	else if (keycode == 2)
		go_right(game, pposition);
	else if (keycode == 13)
		go_up(game, pposition);
	else if (keycode == 1)
		go_down(game, pposition);
	if (keycode == 53)
		leave(game);
	return (1);
}


int	playgame(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, \
			game->c_inmap * 64, game->l_inmap * 64, "SO_LONGAME");
	drawmap(game);
	mlx_key_hook(game->win, &handle_event, game);
	mlx_hook(game->win, 17, 0, &leave, game);
	mlx_loop(game->mlx);
	return (0);
}
