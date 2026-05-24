/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:48:41 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/24 22:50:26 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ps_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	output_command(t_command *command, char *type)
{
	int	len;

	len = ps_strlen(type);
	if (write(1, type, len) == -1)
		return (-1);
	count_command(command, type);
	return (1);
}

int	select_strategy(t_stack *a, t_stack *b, t_form *flag)
{
	double		dis;
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (command == NULL)
		return (-1);
	if (flag->simple == 1)
		simple_sort(a, b, command);
	else if (flag->medium == 1)
		chunk_sort(a, b, command);
	else if (flag->complex == 1)
		radix_sort(a, b, command);
	dis = disorder(a);
	printf("DISORDER ===== %f\n", dis); // テスト用！！！！！！
	if (dis < 0.2)
		simple_sort(a, b, command);
	else if (dis >= 0.2 && dis < 0.5)
		chunk_sort(a, b, command);
	else
		radix_sort(a, b, command);
	free(command);
	return (1);
}
