/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:56:48 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/24 12:43:43 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	calc_index(t_stack *a, t_node *current)
{
	t_node	*running;
	int		count;
	int		i;

	running = a->top;
	i = 0;
	count = 0;
	while (i < a->size)
	{
		if ((current->value) > (running->value))
			count++;
		running = running->next;
		i++;
	}
	return (count);
}

void	assign_index(t_stack *a)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (i < a->size)
	{
		current->index = calc_index(a, current);
		current = current->next;
		i++;
	}
}

// static void	print_index(t_stack *a)
// {
// 	t_node	*n;
// 	int		i;
// 
// 	n = a->top;
// 	i = 0;
// 	while (i < a->size)
// 	{
// 		printf("value=%3ld  index=%d\n", n->value, n->index);
// 		n = n->next;
// 		i++;
// 	}
// }
// 
// int	main(void)
// {
// 	t_stack	a;
// 	long	vals[] = {30, 10, 50, 20, 40};
// 	int		i;
// 
// 	stack_init(&a);
// 	i = 0;
// 	while (i < 5)
// 		list_apply(&a, vals[i++]);
// 	printf("--- before assign_index ---\n");
// 	print_index(&a);
// 	assign_index(&a);
// 	printf("--- after assign_index ---\n");
// 	print_index(&a);
// 	ps_lstclear(&a);
// 	return (0);
// }
