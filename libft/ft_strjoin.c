/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:31:46 by omajdoub          #+#    #+#             */
/*   Updated: 2023/05/23 17:30:10 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		str_index;
	int		word_index;
	char	*new_s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	new_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_s)
		return (NULL);
	str_index = 0;
	word_index = 0;
	while (s1[str_index])
		new_s[word_index++] = s1[str_index++];
	str_index = 0;
	while (s2[str_index])
		new_s[word_index++] = s2[str_index++];
	new_s[word_index] = '\0';
	free(s1);
	return (new_s);
}
