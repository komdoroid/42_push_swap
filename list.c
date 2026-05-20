/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:00:51 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/20 19:47:42 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	list_apply(t_stack **head, long num)
{
	t_node	*tmp;

	tmp = node_init(num);
	if (tmp == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	*lst->size = *lst->size + 1;
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

void	stack_init(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

void	ft_lstclear(t_stack *lst, )
{
	t_node	*current;
	t_node	*next_node;

	if (lst == NULL)
		return ;
	current = (*lst)->top;
	while (*lst != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	lst = NULL;
	return ;
}

t_node	*node_init(long value)
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
