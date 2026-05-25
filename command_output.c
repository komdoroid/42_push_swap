/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:48:41 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/24 23:39:09 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	command_init(t_command *command)
{
	command->sa = 0;
	command->sb = 0;
	command->ss = 0;
	command->pa = 0;
	command->pb = 0;
	command->ra = 0;
	command->rb = 0;
	command->rr = 0;
	command->rra = 0;
	command->rrb = 0;
	command->rrr = 0;
}

void	count_command(t_command *command, char *type)
{
	if (ps_strncmp(type, "sa\n", 3) == 0)
		command->sa++;
	else if (ps_strncmp(type, "sb\n", 3) == 0)
		command->sb++;
	else if (ps_strncmp(type, "ss\n", 3) == 0)
		command->ss++;
	else if (ps_strncmp(type, "pa\n", 3) == 0)
		command->pa++;
	else if (ps_strncmp(type, "pb\n", 3) == 0)
		command->pb++;
	else if (ps_strncmp(type, "ra\n", 3) == 0)
		command->ra++;
	else if (ps_strncmp(type, "rb\n", 3) == 0)
		command->rb++;
	else if (ps_strncmp(type, "rr\n", 3) == 0)
		command->rr++;
	else if (ps_strncmp(type, "rra\n", 4) == 0)
		command->rra++;
	else if (ps_strncmp(type, "rrb\n", 4) == 0)
		command->rrb++;
	else if (ps_strncmp(type, "rrr\n", 4) == 0)
		command->rrr++;
}

int	output_command(t_form *flag, t_command *command, char *type)
{
	int	len;

	len = ps_strlen(type);
	if (flag->bench == 0)
	{
		if (write(1, type, len) == -1)
			return (-1);
	}
	count_command(command, type);
	return (1);
}

int	select_strategy(t_stack *a, t_stack *b, t_form *flag)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (command == NULL)
		return (-1);
	flag->disorder = disorder(a);
	if (flag->simple == 1)
	{
		simple_sort(a, b, command, flag);
		flag->strategy = "simple\n";
	}
	else if (flag->medium == 1)
	{
		chunk_sort(a, b, command, flag);
		flag->strategy = "medium\n";
	}
	else if (flag->complex == 1)
	{
		radix_sort(a, b, command, flag);
		flag->strategy = "complex\n";
	}
	else
		adaptive_select(a, b, command, flag);
	if (flag->bench == 1)
	{
		if (bench_output(command, flag) == -1)
			return (write_error());
	}
	free(command);
	return (1);
}

void	adaptive_select(t_stack *a, t_stack *b, t_command *command,
		t_form *flag)
{
	if (flag->disorder < 0.2)
	{
		simple_sort(a, b, command, flag);
		flag->strategy = "Adaptive / O(n2)\n";
	}
	else if (flag->disorder >= 0.2 && flag->disorder < 0.5)
	{
		chunk_sort(a, b, command, flag);
		flag->strategy = "Adaptive / O(n√n)\n";
	}
	else
	{
		radix_sort(a, b, command, flag);
		flag->strategy = "Adaptive / O(nlogn)\n";
	}
}
