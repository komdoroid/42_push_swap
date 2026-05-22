/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:42:47 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/19 20:15:56 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	word_count(char const *s, char c)
{
	int	word_num;

	word_num = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			word_num++;
		}
	}
	return (word_num);
}

char	*fill_words(char const *s, int len)
{
	int		i;
	char	*row;

	i = 0;
	row = malloc(sizeof(char) * (len + 1));
	if (row == NULL)
		return (NULL);
	while (i < len)
	{
		row[i] = s[i];
		i++;
	}
	row[i] = '\0';
	return (row);
}

void	free_all(char **res, int row_num)
{
	int	i;

	i = 0;
	while (i < row_num)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**make_grid(char **res, char const *s, char c)
{
	int			i;
	char const	*start;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			start = s;
			while (*s != c && *s)
				s++;
			res[i] = fill_words(start, s - start);
			if (res[i] == NULL)
			{
				free_all(res, i);
				return (NULL);
			}
			i++;
		}
	}
	return (res);
}

char	**ps_split(char const *s, char c)
{
	char	**res;
	int		word_num;

	word_num = word_count(s, c);
	res = malloc(sizeof(char *) * (word_num + 1));
	if (res == NULL)
		return (NULL);
	if (make_grid(res, s, c) == NULL)
		return (NULL);
	res[word_num] = NULL;
	return (res);
}
// #include <stdio.h>

// static void	free_split(char **res)
// {
// 	int	i;

// 	if (!res)
// 		return ;
// 	i = 0;
// 	while (res[i])
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// }

// int	main(void)
// {
// 	char	**res;
// 	int		i;

// 	printf("===== BASIC =====\n");
// 	res = ft_split("hello world 42", ' ');
// 	i = 0;
// 	while (res && res[i])
// 	{
// 		printf("[%d] %s\n", i, res[i]);
// 		i++;
// 	}
// 	free_split(res);
// 	printf("\n===== MULTIPLE SPACES =====\n");
// 	res = ft_split("hello   world    42", ' ');
// 	i = 0;
// 	while (res && res[i])
// 	{
// 		printf("[%d] %s\n", i, res[i]);
// 		i++;
// 	}
// 	free_split(res);
// 	printf("\n===== LEADING / TRAILING =====\n");
// 	res = ft_split("   hello world   ", ' ');
// 	i = 0;
// 	while (res && res[i])
// 	{
// 		printf("[%d] %s\n", i, res[i]);
// 		i++;
// 	}
// 	free_split(res);
// 	printf("\n===== ONLY DELIMITER =====\n");
// 	res = ft_split("     ", ' ');
// 	if (!res || !res[0])
// 		printf("empty\n");
// 	free_split(res);
// 	printf("\n===== EMPTY STRING =====\n");
// 	res = ft_split("", ' ');
// 	if (!res || !res[0])
// 		printf("empty\n");
// 	free_split(res);
// 	printf("\n===== COMMA CASE =====\n");
// 	res = ft_split(",,a,,b,,,c,,", ',');
// 	i = 0;
// 	while (res && res[i])
// 	{
// 		printf("[%d] %s\n", i, res[i]);
// 		i++;
// 	}
// 	// free_split(res);
// 	return (0);
// }
