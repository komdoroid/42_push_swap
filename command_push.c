/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:41:13 by kkomurat          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/24 22:15:59 by riwatana         ###   ########.fr       */
=======
/*   Updated: 2026/05/24 14:40:24 by kkomurat         ###   ########.fr       */
>>>>>>> chunk_sort
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stack *to, t_stack *from)
{
	t_node	*node;

	if (!from || !from->top || from->size < 1)
		return ;
	node = from->top;
	reconnect_from(from, node);
	reconnect_to(to, node);
}

void	reconnect_from(t_stack *from, t_node *node)
{
	if (from->size == 1)
		from->top = NULL;
	else 
	{
		from->top = node->next;
		from->top->prev = node->prev;
		node->prev->next = from->top;
	}
	from->size--;
	node->next = NULL;
	node->prev = NULL;
}

void	reconnect_to(t_stack *to, t_node *node)
{
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
