/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:29:02 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/30 13:43:22 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	simple_sort(t_stack *a, t_stack *b, t_command *command)
{
	int	i;

	if (!a || !b || a->size < 2)
		return ;
	i = 0;
	while (a->size > 0)
	{
		while (a->top->index != i)
		{
			if (find_pos(a, i))
				rotate_a(a, command, 1);
			else
				reverse_rotate_a(a, command, 1);
		}
		push_b(b, a, command);
		i++;
	}
	while (b->size > 0)
		push_a(a, b, command);
}
