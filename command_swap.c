/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:39:58 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/24 23:20:43 by riwatana         ###   ########.fr       */
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

void	swap_a(t_stack *head, t_command *command, t_form *flag, int output)
{
	swap(head);
	if (output == 1)
		output_command(flag, command, "sa\n");
}

void	swap_b(t_stack *head, t_command *command, t_form *flag, int output)
{
	swap(head);
	if (output == 1)
		output_command(flag, command, "sb\n");
}

void	swap_both(t_stack *a, t_stack *b, t_command *command, t_form *flag)
{
	swap_a(a, command, 0);
	swap_b(b, command, 0);
	output_command(flag, command, "ss\n");
}
