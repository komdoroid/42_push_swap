/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:08:21 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/25 19:39:17 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	calc_mistakes(t_stack *head, int size)
{
	int		i;
	int		j;
	t_node	*left;
	t_node	*right;
	long	mistakes;

	left = head->top;
	mistakes = 0;
	i = 0;
	while (i < size - 1)
	{
		right = left->next;
		j = i + 1;
		while (j < size)
		{
			if (left->value > right->value)
				mistakes++;
			right = right->next;
			j++;
		}
		left = left->next;
		i++;
	}
	return (mistakes);
}

double	disorder(t_stack *head)
{
	long	mistakes;
	int		size;
	double	total_pairs;

	size = head->size;
	if (size < 2)
		return (0.0);
	mistakes = calc_mistakes(head, size);
	total_pairs = (double)size * (size - 1) / 2;
	return ((double)mistakes / total_pairs);
}
