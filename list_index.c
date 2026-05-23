/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:56:48 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/23 21:36:33 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_index(t_stack *a)
{
	t_node	*current;
	t_node	*running;
	int		count;
	int		i;
	int		j;

	node = a->top;
	while (i < a->size)
	{
		while (j < a->size)
		{
			if (current->value > running->value)
				count++;
			running = running->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (count);
}
