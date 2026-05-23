/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:45:32 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/23 12:57:01 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack *head)
{
	if (!head || !head->top || head->size < 2)
		return ;
	head->top = head->top->next;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
}

void	rotate_b(t_stack *b)
{
	rotate(b);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}

