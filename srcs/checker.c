/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:43:56 by omajdoub          #+#    #+#             */
/*   Updated: 2023/06/03 21:23:19 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	argschecker(char **argv)
{
	int		fd;
	char	*tmp;

	tmp = NULL;
	if ((argv[1][ft_strlen(argv[1]) - 1] == 'r') \
			&& (argv[1][ft_strlen(argv[1]) - 2] == 'e') \
			&& (argv[1][ft_strlen(argv[1]) - 3] == 'b') \
			&& (argv[1][ft_strlen(argv[1]) - 4] == '.'))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			errorf(4);
		if (!(read(fd, tmp, 1)))
			errorf(6);
		close(fd);
		return ;
	}
	errorf(2);
}
