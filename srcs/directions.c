/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:00 by omajdoub          #+#    #+#             */
/*   Updated: 2023/05/27 11:17:56 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_char(t_game *game, char c)
{
	int	index;
	int	index2;
	int	counter;

	index = 0;
	counter = 0;
	while (game->map[index])
	{
		index2 = 0;
		while (game->map[index][index2])
		{
			if (game->map[index][index2] == c)
				counter++;
			index2++;
		}
		index++;
	}
	return (counter);
}

void	go_left(t_game *game, t_pos pposition)
{
	char	nextposition;
	t_pos	next_pos;

	nextposition = get_in_pos(game, pposition.x - 1, pposition.y);
	next_pos = pposition;
	if (nextposition == '0' || nextposition == 'C')
	{
		if (nextposition == 'C')
			game->collects--;
		next_pos.x--;
		change_char_in_map(game, pposition, next_pos);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (nextposition == 'E' && count_char(game, 'C') == 0)
		errorf(10);
}

void	go_right(t_game *game, t_pos pposition)
{
	char	nextposition;
	t_pos	next_pos;

	nextposition = get_in_pos(game, pposition.x + 1, pposition.y);
	next_pos = pposition;
	if (nextposition == '0' || nextposition == 'C')
	{
		if (nextposition == 'C')
			game->collects--;
		next_pos.x++;
		change_char_in_map(game, pposition, next_pos);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (nextposition == 'E' && count_char(game, 'C') == 0)
		errorf(10);
}

void	go_up(t_game *game, t_pos player_pos)
{
	char	nextposition;
	t_pos	next_pos;

	nextposition = get_in_pos(game, player_pos.x, player_pos.y - 1);
	next_pos = player_pos;
	if (nextposition == '0' || nextposition == 'C')
	{
		if (nextposition == 'C')
			game->collects--;
		next_pos.y--;
		change_char_in_map(game, player_pos, next_pos);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (nextposition == 'E' && count_char(game, 'C') == 0)
		errorf(10);
}

void	go_down(t_game *game, t_pos pposition)
{
	char	nextposition;
	t_pos	next_pos;

	nextposition = get_in_pos(game, pposition.x, pposition.y + 1);
	next_pos = pposition;
	if (nextposition == '0' || nextposition == 'C')
	{
		if (nextposition == 'C')
			game->collects--;
		next_pos.y++;
		change_char_in_map(game, pposition, next_pos);
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (nextposition == 'E' && count_char(game, 'C') == 0)
		errorf(10);
}
