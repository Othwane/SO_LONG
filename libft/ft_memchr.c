/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:16 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/31 17:07:47 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	i = 0;
	ss = (unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return (&ss[i]);
		i++;
	}
	return (NULL);
}
