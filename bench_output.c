/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:38:06 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/25 19:39:58 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	bench_output(t_command *command, t_form *flag)
{
	if (dis_output(flag) == -1)
		return (-1);
	if (stra_ops_output(command, flag) == -1)
		return (-1);
	if (swap_push_output(command) == -1)
		return (-1);
	if (rotate_output(command) == -1)
		return (-1);
	return (1);
}

int	dis_output(t_form *flag)
{
	int	error;
	int	int_part;
	int	frac_part;

	error = 0;
	int_part = (int)(flag->disorder * 100);
	frac_part = (int)(flag->disorder * 10000) % 100;
	while (error != -1)
	{
		error = ps_putstr_fd("disorder:  ", 2);
		error = ps_putnbr_fd(int_part, 2);
		error = ps_putstr_fd(".", 2);
		if (frac_part < 10)
			error = ps_putnbr_fd(0, 2);
		error = ps_putnbr_fd(frac_part, 2);
		error = ps_putstr_fd("%\n", 2);
		break ;
	}
	if (error == -1)
		return (-1);
	return (1);
}

int	stra_ops_output(t_command *command, t_form *flag)
{
	int	error;

	error = 0;
	while (error != -1)
	{
		error = ps_putstr_fd("strategy:  ", 2);
		error = ps_putstr_fd(flag->strategy, 2);
		error = ps_putstr_fd("total_ops:  ", 2);
		error = ps_putnbr_fd(command->total, 2);
		error = ps_putstr_fd("\n", 2);
		break ;
	}
	if (error == -1)
		return (-1);
	return (1);
}

int	swap_push_output(t_command *command)
{
	int	error;

	error = 0;
	while (error != -1)
	{
		error = ps_putstr_fd("sa:  ", 2);
		error = ps_putnbr_fd(command->sa, 2);
		error = ps_putstr_fd("  sb:  ", 2);
		error = ps_putnbr_fd(command->sb, 2);
		error = ps_putstr_fd("  ss:  ", 2);
		error = ps_putnbr_fd(command->ss, 2);
		error = ps_putstr_fd("  pa:  ", 2);
		error = ps_putnbr_fd(command->pa, 2);
		error = ps_putstr_fd("  pb:  ", 2);
		error = ps_putnbr_fd(command->pb, 2);
		error = ps_putstr_fd("\n", 2);
		break ;
	}
	if (error == -1)
		return (-1);
	return (1);
}

int	rotate_output(t_command *command)
{
	int	error;

	error = 0;
	while (error != -1)
	{
		error = ps_putstr_fd("ra:  ", 2);
		error = ps_putnbr_fd(command->ra, 2);
		error = ps_putstr_fd("  rb:  ", 2);
		error = ps_putnbr_fd(command->rb, 2);
		error = ps_putstr_fd("  rr:  ", 2);
		error = ps_putnbr_fd(command->rr, 2);
		error = ps_putstr_fd("  rra:  ", 2);
		error = ps_putnbr_fd(command->rra, 2);
		error = ps_putstr_fd("  rrb:  ", 2);
		error = ps_putnbr_fd(command->rrb, 2);
		error = ps_putstr_fd("  rrr:  ", 2);
		error = ps_putnbr_fd(command->rrr, 2);
		error = ps_putstr_fd("\n", 2);
		break ;
	}
	if (error == -1)
		return (-1);
	return (1);
}
