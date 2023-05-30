/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:07:25 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/30 14:26:52 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((s[i] != '\0') && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] == 45 || s[i] == 43)
	{
		if (s[i] == 45)
			sign = -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		result *= 10;
		result += (s[i] - 48);
		i++;
	}
	return (result * sign);
}
