/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:41:13 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/24 22:15:59 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stack *to, t_stack *from)
{
	t_node	*node;

	if (!from || !from->top || from->size < 1)
		return ;
	node = from->top;
	from->top = node->next;
	from->top->prev = node->prev;
	node->prev->next = from->top;
	from->size--;
	if (to->size == 0)
	{
		node->next = node;
		node->prev = node;
		to->top = node;
		to->size++;
		return ;
	}
	node->next = to->top;
	node->prev = to->top->prev;
	to->top->prev->next = node;
	to->top->prev = node;
	to->top = node;
	to->size++;
}

void	push_a(t_stack *a, t_stack *b, t_command *command)
{
	push(a, b);
	output_command(command, "pa\n");
}

void	push_b(t_stack *b, t_stack *a, t_command *command)
{
	push(b, a);
	output_command(command, "pb\n");
}
