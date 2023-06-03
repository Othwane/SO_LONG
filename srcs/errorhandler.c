/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:04 by omajdoub          #+#    #+#             */
/*   Updated: 2023/06/03 22:52:56 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	errorf(int error)
{
	if (error == 1)
		ft_putstr_fd("Invalid Arguments.\n", 2);
	else if (error == 2)
		ft_putstr_fd("Map name is not correct.\n", 2);
	else if (error == 3)
		ft_putstr_fd("Empty line.\n", 2);
	else if (error == 4)
		ft_putstr_fd("Map not found.\n", 2);
	else if (error == 5)
		ft_putstr_fd("No way to our coin\n", 2);
	else if (error == 8)
		ft_putstr_fd("No way to our Exit\n", 2);
	else if (error == 6)
		ft_putstr_fd("Map is not correct.\n", 2);
	else if (error == 7)
		ft_putstr_fd("Map must contain at least one P one C and one E.\n", 2);
	else if (error == 9)
		ft_putstr_fd("Map size\n", 2);
	else if (error == 10)
	{
		ft_putstr_fd("You Won.\n", 1);
		exit(0);
	}
	exit(1);
}
