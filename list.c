/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:00:51 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/23 00:11:12 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	list_apply(t_stack *head, long num)
{
	t_node	*new;

	new = node_new(num);
	if (new == NULL)
	{
		ft_lstclear(head);
		return (-1);
	}
	if (head->top == NULL)
		head->top = new;
	if (ps_lstadd_back(head, new) == -1)
	{
		ft_lstclear(head);
		return (-1);
	}
	head->size = head->size + 1;
	return (1);
}

void	stack_init(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

int	ps_lstadd_back(t_stack *head, t_node *new)
{
	t_node	*last;

	if (head == NULL || new == NULL)
		return (-1);
	if (head->size == 0)
	{
		new->next = new;
		new->prev = new;
		return (1);
	}
	last = head->top->prev;
	last->next = new;
	new->next = head->top;
	new->prev = last;
	head->top->prev = new;
	return (1);
}

void	ft_lstclear(t_stack *head)
{
	t_node	*current;
	t_node	*next_node;
	int		i;

	i = 0;
	if (head == NULL || head->top == NULL)
		return ;
	current = head->top;
	while (i < head->size)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		i++;
	}
	head->top = NULL;
	head->size = 0;
	return ;
}

t_node	*node_new(long value)
{
	t_node	*res;

	res = (t_node *)malloc(sizeof(t_node));
	if (res == NULL)
		return (NULL);
	res->value = value;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
