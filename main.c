/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:15:58 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/30 18:28:08 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack(t_stack *head, const char *label)
{
	t_node	*current;
	int		i;

	printf("===== %s =====\n", label);
	if (head == NULL || head->top == NULL)
	{
		printf("  (empty)\n");
		return ;
	}
	current = head->top;
	i = 0;
	while (i < head->size)
	{
		printf("  [%d] value=%ld  index=%d\n", i, current->value,
			current->index);
		current = current->next;
		i++;
	}
	printf("  size = %d\n", head->size);
}

int	is_sorted(t_stack *head)
{
	t_node	*current;
	int		i;

	if (head == NULL || head->top == NULL || head->size < 2)
		return (1);
	current = head->top;
	i = 0;
	while (i < head->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	heada;
	t_stack	headb;
	t_form	flag;

	if (argc <= 1)
		return (0);
	stack_init(&headb);
	if (parse(&heada, &flag, argc, argv) == -1)
		return (write_error());
	print_stack(&heada, "BEFORE sort");
	if (select_strategy(&heada, &headb, &flag) == -1)
		return (write_error());
	print_stack(&heada, "AFTER sort");
	if (is_sorted(&heada))
		printf(">> RESULT: OK (sorted)\n");
	else
		printf(">> RESULT: KO (not sorted)\n");
	ps_lstclear(&heada);
	ps_lstclear(&headb);
	return (0);
}
