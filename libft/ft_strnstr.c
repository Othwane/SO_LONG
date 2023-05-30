/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:52:56 by omajdoub          #+#    #+#             */
/*   Updated: 2022/10/24 01:23:48 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cn;

	if (*needle == 0 || haystack == needle)
		return ((char *)haystack);
	cn = ft_strlen(needle);
	while (*haystack && cn <= len--)
	{
		if (!(ft_strncmp((char *)haystack, (char *)needle, cn)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
