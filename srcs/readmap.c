/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:22 by omajdoub          #+#    #+#             */
/*   Updated: 2023/06/03 21:26:16 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	readmap(t_game *game)
{
	char	*map;
	ssize_t	bytes_read;
	char	*line;

	line = ft_calloc(2, 1);
	map = NULL;
	if (!line)
		errorf(1);
	while (1)
	{
		bytes_read = read(game->mapfd, line, 1);
		if (bytes_read == 0)
			break ;
		map = ft_strjoin(map, line);
	}
	game->mapx = map;
	ddnl(game);
	game->map = ft_split(map, '\n');
	free(line);
	line = NULL;
	close(game->mapfd);
}

void	ddnl(t_game *game)
{
	int	i;

	i = 0;
	while (game->mapx[i])
	{
		if (game->mapx[i] == '\n' && game->mapx[i + 1] == '\n')
			errorf(3);
		i++;
	}
}

int	strlenn(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
