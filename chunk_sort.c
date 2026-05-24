/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:53:11 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/24 23:26:23 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	calc_chunk_size(int n)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < n)
		chunk_size++;
	return (chunk_size);
}

bool	find_pos(t_stack *b, int target)
{
	t_node	*node;
	int		median;
	int		i;

	node = b->top;
	median = b->size / 2;
	i = 0;
	while (i < median)
	{
		if (node->index == target)
			return (true);
		i++;
		node = node->next;
	}
	return (false);
}

void	push_chunks_to_b(t_stack *a, t_stack *b, t_command *command)
{
	int	size;
	int	order;
	int	index;
	int	count;

	size = calc_chunk_size(a->size);
	order = 1;
	while (order <= size)
	{
		count = 0;
		while (a->size > 0)
		{
			index = a->top->index;
			if ((order - 1) * size <= index && index < order * size)
			{
				push_b(b, a, command);
				count++;
				if (count == size)
					break;
			}
			else
			{
				rotate_a(a, command, 1);
			}
			printf("a->size: %d\n", a->size);
		}
		order++;
	}
}

void	sort_chunks_to_a(t_stack *a, t_stack *b, t_command *command)
{
	int	target_index;

	target_index = b->size - 1;
	while (b->size > 0)
	{
		if (find_pos(b, target_index))
		{
			while (target_index != b->top->index)
				rotate_b(b, command, 1);
			push_a(a, b,command);
		}
		else
		{
			while (target_index != b->top->index)
				reverse_rotate_b(b, command, 1);
			push_a(a, b, command);
		}
		target_index--;
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_command *command)
{
	if (!a || !b || a->size < 2)
		return ;
	push_chunks_to_b(a, b, command);
	sort_chunks_to_a(a, b, command);
}
