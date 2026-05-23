/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:46:16 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/23 12:56:58 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_stack *head)
{
	if (!head || !head->top || head->size < 2)
		return ;
	head->top = head->top->prev;
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(*a);
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(*b);
}

void	rverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate_a(*a);
	reverse_rotate_a(*b);
}
