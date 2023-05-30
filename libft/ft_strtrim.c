/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:34:34 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/30 21:47:51 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (!set || !s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	str = ft_substr(s1, i, len - i);
	return (str);
}
