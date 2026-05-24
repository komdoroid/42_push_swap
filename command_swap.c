/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:39:58 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/23 23:00:59 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *head)
{
	t_node	*prev;
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!head || !head->top || head->size < 2)
		return ;
	prev = head->top->prev;
	first = head->top;
	second = head->top->next;
	third = head->top->next->next;
	prev->next = second;
	second->prev = prev;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	head->top = second;
}

void	swap_a(t_stack *head)
{
	swap(head);
}

void	swap_b(t_stack *head)
{
	swap(head);
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}
