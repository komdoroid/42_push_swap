/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:46:16 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/24 23:27:26 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_stack *head)
{
	if (!head || !head->top || head->size < 2)
		return ;
	head->top = head->top->prev;
}

void	reverse_rotate_a(t_stack *a, t_command *command, t_form *flag,
		int output)
{
	reverse_rotate(a);
	if (output == 1)
		output_command(flag, command, "rra\n");
}

void	reverse_rotate_b(t_stack *b, t_command *command, t_form *flag,
		int output)
{
	reverse_rotate(b);
	if (output == 1)
		output_command(flag, command, "rrb\n");
}

void	rverse_rotate_both(t_stack *a, t_stack *b, t_command *command,
		t_form *flag)
{
	reverse_rotate_a(a, command, flag, 0);
	reverse_rotate_b(b, command, flag, 0);
	output_command(flag, command, "rrr\n");
}
