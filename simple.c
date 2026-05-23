/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:29:02 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/23 23:36:01 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	simple_sort(t_stack *a, t_stack *b)
{
	int	i;

	if (!a || !b || a->size < 2)
		return ;
	i = 0;
	while (a->size > 0)
	{
		while (a->top->index != i)
			rotate_a(a);
		push_b(b, a);
		i++;
	}
	while (b->size > 0)
	{
		rotate_b(b);
		push_a(a, b);
	}
}
