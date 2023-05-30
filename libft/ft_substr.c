/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:55:20 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/30 22:10:00 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		len = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (len > 0 && s[start + i])
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}
