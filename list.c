/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:00:51 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/19 23:12:35 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	stack_init(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

t_node	node_init(long value)
{
	t_node	*res;

	res = (t_node *)malloc(sizeof(t_node));
	if (res == NULL)
		return (NULL);
	res->value= value;
	res->next = NULL;
	res->prev= NULL;
	return (res);
}
