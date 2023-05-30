/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:18 by omajdoub          #+#    #+#             */
/*   Updated: 2023/05/27 15:05:32 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	strlenn(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	cf_line(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	len = strlenn(game->map);
	while (game->map[len - 1][i])
	{
		if (game->map[len - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	cl_lines(t_game *game)
{
	int	i;
	int	holder;

	i = 0;
	holder = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != holder)
			return (1);
		if (game->map[i][0] != '1' || game->map[i][holder - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_walls(t_game *game)
{
	game->c_inmap = ft_strlen(game->map[0]);
	if (cf_line(game) || cl_lines(game))
		errorf(6);
}

void	check_pce(t_game *game)
{
	int	i;
	int	ii;

	i = 0;
	while (game->map[i])
	{
		ii = 0;
		while (game->map[i][ii])
		{
			check_noneeded(game);
			if (game->map[i][ii] == 'P')
			{
				game->player++;
				game->y_player = i;
				game->x_player = ii;
			}
			if (game->map[i][ii] == 'C')
				game->collects++;
			if (game->map[i][ii] == 'E')
			{
				game->exit++;
				game->y_exit = i;
				game->x_exit = ii;
			}
			ii++;
		}
		i++;
		game->l_inmap++;
	}
	if (game->player != 1 || game->collects == 0 || game->exit != 1)
		errorf(7);
}
void	check_noneeded(t_game *game)
{
	int i = 0;
	int ii;
	while (game->map[i])
	{
		ii = 0;
		while (game->map[i][ii])
		{
			if (game->map[i][ii] != '0' && game->map[i][ii] != '1' && game->map[i][ii] != 'P' && game->map[i][ii] != 'C' && game->map[i][ii] != 'E' && game->map[i][ii] != '\n')
				errorf(1);
			ii++;
		}
		
		i++;		
	}
	
}

void	mapchecker(t_game *game)
{	
	check_walls(game);
	check_pce(game);
}
