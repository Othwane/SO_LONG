/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:30:17 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/31 15:37:45 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	count_words(const char *s, char c)
{
	int	i;
	int	wd;

	i = 0;
	wd = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		wd++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (wd);
}

int	wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_mini_split(char **str, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		str[i] = (char *)malloc(sizeof(char) * (wordlen(s, c) + 1));
		j = 0;
		l = wordlen(s, c);
		while (j < l)
		{
			str[i][j++] = *s;
			s++;
		}
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	words = count_words(s, c);
	str = (char **)malloc((words + 1) * (sizeof(char *)));
	if (!str)
		return (NULL);
	str = ft_mini_split(str, s, c, words);
	return (str);
}
// #include <stdio.h>
// int main()
// {
//     char c[] = "      split       this for   me  !       ";
//     char **s = ft_split(c, ' ');
//     int count = count_words(c, ' ');
//     printf("%d\n", count);
//     for (int i = 0; i < 5; i++)
//         printf("%s\n", s[i]);
// }
