/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:57:53 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/24 21:55:05 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_max_bits(int size)
{
	int	bits;
	int	max;

	if (size < 2)
		return (0);
	max = size - 1;
	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b, t_command *command)
{
	int	bit;
	int	max_bits;
	int	i;
	int	size;

	if (!a || !b || a->size < 2)
		return ;
	bit = 0;
	max_bits = get_max_bits(a->size);
	while (bit < max_bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if ((a->top->index >> bit) & 1)
				rotate_a(a, command,1);
			else
				push_b(b, a, command);
			i++;
		}
		while (b->size > 0)
			push_a(a, b, command);
		bit++;
	}
}
