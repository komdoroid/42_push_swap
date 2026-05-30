/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_command_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:51:47 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/30 22:12:13 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int command_dispatch(char *command, t_stack *a, t_stack *b)
{
	if (ps_strncmp(command, "sa\n", 3) == 0)
		swap(a);
	else if (ps_strncmp(command, "sb\n", 3) == 0)
		swap(b);
	else if (ps_strncmp(command, "ss\n", 3) == 0)
		swap_both_bonus(a, b);
	else if (ps_strncmp(command, "pa\n", 3) == 0)
		push(a, b);
	else if (ps_strncmp(command, "pb\n", 3) == 0)
		push(b, a);
	else if (ps_strncmp(command, "ra\n", 3) == 0)
		rotate(a);
	else if (ps_strncmp(command, "rb\n", 3) == 0)
		rotate(b);
	else if (ps_strncmp(command, "rr\n", 3) == 0)
		rotate_both_bonus(a, b);
	else if (ps_strncmp(command, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ps_strncmp(command, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ps_strncmp(command, "rrr\n", 4) == 0)
		reverse_rotate_both_bonus(a, b);
	else
		return (-1);
	return (1);
}

void	swap_both_bonus(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate_both_bonus(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_both_bonus(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
