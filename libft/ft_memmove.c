/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:42:40 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/31 16:19:35 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dp;
	unsigned char	*sp;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (dp > sp)
	{
		i = i + 1;
		while (i <= len)
		{
			dp[len - i] = sp[len - i];
			i++;
		}
	}
	else
		ft_memcpy (dst, src, len);
	return (dst);
}
