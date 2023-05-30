/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:02:51 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/30 17:46:27 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_countn(long num)
{
	int	i;
	int	ng;

	i = 0;
	ng = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		ng = 1;
		num = -num;
	}
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	if (ng)
		return (i + 1);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		stop;
	long	number;

	number = n;
	stop = 0;
	len = ft_countn(number);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (number < 0)
	{
		stop = 1;
		str[0] = '-';
		number = -number;
	}
	str[len--] = '\0';
	while (len >= stop)
	{
		str[len--] = (number % 10) + 48;
		number /= 10;
	}
	return (str);
}
