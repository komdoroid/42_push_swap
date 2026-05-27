/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:45:32 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/27 22:20:33 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack *head)
{
	if (!head || !head->top || head->size < 2)
		return ;
	head->top = head->top->next;
}

void	rotate_a(t_stack *a, t_command *command, int output)
{
	rotate(a);
	if (output == 1)
		output_command(command, "ra\n");
}

void	rotate_b(t_stack *b, t_command *command, int output)
{
	rotate(b);
	if (output == 1)
		output_command(command, "rb\n");
}

void	rotate_both(t_stack *a, t_stack *b, t_command *command)
{
	rotate_a(a, command, 0);
	rotate_b(b, command, 0);
	output_command(command, "rr\n");
}
