/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:36:41 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/24 00:59:21 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)dst;
	if (n != 0)
	{
		while (i < n)
		{
			p[i] = 0;
			i++;
		}
	}
}
