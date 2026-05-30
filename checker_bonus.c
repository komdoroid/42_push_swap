/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:51:43 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/30 20:56:11 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	parse_bonus(t_stack *head, int argc, char **argv)
{
	int	pos;

	stack_init(head);
	pos = 1;
	if ((parse_num(head, argv, argc, pos)) == -1)
		return (-1);
	if (check_duplicates(head) == -1)
	{
		ps_lstclear(head);
		return (-1);
	}
	assign_index(head);
	return (1);
}

int	sort_check_bonus(t_stack *a)
{
	t_node	*current;
	t_node	*next_node;
	int		i;

	i = 1;
	if (a == NULL || a->top == NULL)
		return (-1);
	current = a->top;
	while (i < a->size)
	{
		next_node = current->next;
		if (current->index > next_node->index)
			return (-1);
		current = current->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	heada;
	t_stack	headb;
	char	*command;

	if (argc <= 1)
		return (0);
	stack_init(&headb);
	if (parse_bonus(&heada, argc, argv) == -1)
		return (write_error());
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		command_dispatch(command, &heada, &headb);
	}
	free(command);
	if ((sort_check_bonus(&heada) == 1) && headb.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ps_lstclear(&heada);
	ps_lstclear(&headb);
	return (0);
}
