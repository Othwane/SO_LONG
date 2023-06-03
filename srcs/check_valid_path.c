/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:20:28 by omajdoub          #+#    #+#             */
/*   Updated: 2023/06/03 21:11:28 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**cpy_map(char **map)
{
	int		y_len;
	int		x_len;
	char	**cpy;
	int		index;

	index = 0;
	y_len = strlenn(map);
	x_len = ft_strlen(map[0]);
	cpy = ft_calloc(y_len + 1, sizeof(char *));
	while (index < y_len)
		cpy[index++] = ft_calloc(x_len + 1, 1);
	index = 0;
	while (map[index])
	{
		ft_strlcpy(cpy[index], map[index], x_len + 1);
		index++;
	}
	return (cpy);
}

int	findc_inmap(char **map, char c)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (map[index1])
	{
		index2 = 0;
		while (map[index1][index2])
		{
			if (map[index1][index2] == c)
				return (0);
			index2++;
		}
		index1++;
	}
	return (1);
}

static void	check(char **map_cpy, int x_next, int y_next)
{
	char	next_char;

	map_cpy[y_next][x_next] = 'P';
	next_char = map_cpy[y_next][x_next + 1];
	if (next_char == '0' || next_char == 'C')
		check(map_cpy, x_next + 1, y_next);
	next_char = map_cpy[y_next - 1][x_next];
	if (next_char == '0' || next_char == 'C')
		check(map_cpy, x_next, y_next - 1);
	next_char = map_cpy[y_next][x_next - 1];
	if (next_char == '0' || next_char == 'C')
		check(map_cpy, x_next - 1, y_next);
	next_char = map_cpy[y_next + 1][x_next];
	if (next_char == '0' || next_char == 'C')
		check(map_cpy, x_next, y_next + 1);
}

void	check_valid_path(t_game *game)
{
	char	**map_cpy;
	t_pos	pos;

	map_cpy = cpy_map(game->map);
	pos = get_pos(map_cpy, 'P');
	check(map_cpy, pos.x, pos.y);
	if (findc_inmap(map_cpy, 'C') == 0)
		errorf(5);
	pos = get_pos(map_cpy, 'E');
	if (map_cpy[pos.y][pos.x + 1] != 'P'
			&& map_cpy[pos.y - 1][pos.x] != 'P'
			&& map_cpy[pos.y][pos.x - 1] != 'P'
			&& map_cpy[pos.y + 1][pos.x] != 'P')
		errorf(8);
	free_map(map_cpy);
}

void	check_map_size(t_game *game)
{
	if (ft_strlen(game->map[0]) > 39)
		errorf(9);
	if (strlenn(game->map) > 21)
		errorf(9);
}
