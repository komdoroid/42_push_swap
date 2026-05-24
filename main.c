/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:15:58 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/24 12:56:56 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ps_atol(const char *nptr)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	if (!((*nptr >= '0' && *nptr <= '9')))
		return (LONG_MAX);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && nb > (INT_MAX - (*nptr - '0')) / 10)
			return (LONG_MAX);
		if (sign == -1 && nb > (INT_MAX - (*nptr - '0') + 1) / 10)
			return (LONG_MAX);
		nb = nb * 10 + *nptr++ - '0';
	}
	if (*nptr != '\0')
		return (LONG_MAX);
	nb = sign * nb;
	if ((nb < INT_MIN) || (nb > INT_MAX))
		return (LONG_MAX);
	return (nb);
}

int	parse_num(t_stack *head, char **argv, int argc, int pos)
{
	char	**tmp;
	int		i;
	long	num;

	i = 0;
	while (pos < argc)
	{
		tmp = ps_split(argv[pos], ' ');
		if (tmp == NULL)
			return (-1);
		i = 0;
		while (tmp[i])
		{
			num = ps_atol(tmp[i]);
			if (num == LONG_MAX || (list_apply(head, num) == -1))
			{
				free_all(tmp);
				return (-1);
			}
			i++;
		}
		free_all(tmp);
		pos++;
	}
	return (1);
}

int	check_duplicates(t_stack *head)
{
	t_node	*current;
	t_node	*runner;
	int		i;
	int		rest;

	if (head->top == NULL || head->size <= 1)
		return (1);
	current = head->top;
	runner = head->top->next;
	rest = head->size;
	while (rest - 1 > 0)
	{
		i = 0;
		while (i < rest - 1)
		{
			if (current->value == runner->value)
				return (-1);
			runner = runner->next;
			i++;
		}
		current = current->next;
		runner = current->next;
		rest--;
	}
	return (1);
}

int	parse(t_stack *head, t_form *flag, int argc, char **argv)
{
	int	pos;

	stack_init(head);
	pos = flag_check(flag, argv, argc);
	if (pos == -1)
		return (-1);
	if ((parse_num(head, argv, argc, pos)) == -1)
		return (-1);
	if (check_duplicates(head) == -1)
	{
		ft_lstclear(head);
		return (-1);
	}
	return (1);
}

void	print_stack(t_stack *head) // mainのテスト用関数
{
	t_node *current;

	int i;

	if (head == NULL || head->top == NULL)
	{
		printf("empty stack\n");
		return ;
	}
	current = head->top;
	i = 0;
	while (i < head->size)
	{
		printf("[%d] value = %ld\n", i, current->value);
		current = current->next;
		i++;
	}
	printf("size = %d\n", head->size);

	current = head->top;
	i = 0;
	while (i < head->size)
	{
		printf("node %d: addr=%p, next=%p, prev=%p\n", i, (void *)current,
			(void *)current->next, (void *)current->prev);
		current = current->next;
		i++;
	}
	current = head->top;
	printf("DEBUG: freeing addr=%p (i=%d, size=%d)\n", (void *)current, i,
		head->size);

	i = 0;
	while (i < head->size)
	{
		printf("node %d: num=%ld\n", i, current->value);
		current = current->next;
		i++;
	}
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
	{
		write_error();
		return (-1);
	}
	simple_sort(&heada, &headb);
	print_stack(&heada);
	ft_lstclear(&heada);
	return (0);
}
