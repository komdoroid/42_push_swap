/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:41:13 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/23 12:45:24 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push(t_stack *to, t_stack *from)
{
	t_node	*node;

	if (!from || !from->top || from->size < 2)
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
	node->prev = to->prev;
	to->top->prev->next = node;
	to->top = node;
	to->size++;
}

void	push_a(t_stack *a)
{
	push(a);
}

void	push_b(t_stack *b)
{
	push(b);
}
