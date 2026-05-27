/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:39:47 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/27 23:25:14 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

char	*slice(char *s, int start, int size)
{
	char	*sub;
	int		i;

	i = 0;
	if (s == NULL || size == 0)
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
	}
	else
	{
		sub = malloc(sizeof(char) * (size + 1));
		if (sub == NULL)
			return (NULL);
		while (i < size && s[i])
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_join(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	strline(char *s)
{
	int	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
