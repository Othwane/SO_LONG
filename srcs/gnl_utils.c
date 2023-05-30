/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:44:08 by omajdoub          #+#    #+#             */
/*   Updated: 2023/05/27 05:28:19 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	slength(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*searchr(char *string, int x)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == x)
			return (string + i);
		i++;
	}
	return (0);
}

char	*stringjoin(char *pref, char *suff)
{
	int		i;
	int		ii;
	char	*both;

	if (pref == NULL)
		pref = "";
	both = malloc(slength(pref) + slength(suff) + 1);
	i = 0;
	while (pref[i])
	{
		both[i] = pref[i];
		i++;
	}
	ii = 0;
	while (suff && suff[ii])
	{
		both[i] = suff[ii];
		i++;
		ii++;
	}
	both[i] = '\0';
	return (both);
}
