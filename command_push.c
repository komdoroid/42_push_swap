/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:41:13 by kkomurat          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/24 23:21:01 by kkomurat         ###   ########.fr       */
=======
/*   Updated: 2026/05/24 23:21:34 by riwatana         ###   ########.fr       */
>>>>>>> 9a7ec1e (bench_no_write)
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

void	push_a(t_stack *a, t_stack *b, t_command *command, t_form *flag)
{
	push(a, b);
	output_command(flag, command, "pa\n");
}

void	push_b(t_stack *b, t_stack *a, t_command *command, t_form *flag)
{
	push(b, a);
	output_command(flag, command, "pb\n");
}
