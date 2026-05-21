/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:55:42 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/21 23:44:34 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(t_stack **a)
{
	t_node	*prev;
	t_node	*first;
	t_node	*secnd;

	prev = a->prev;
	first = a->next;
	secnd = first->next;
	
	a = secnd;
	sednd->next = first;

