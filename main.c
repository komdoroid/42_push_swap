/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:15:58 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/23 00:51:39 by riwatana         ###   ########.fr       */
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
	if ((nb > INT_MAX) || (sign * nb < INT_MIN))
		return (LONG_MAX);
	return ((sign * nb));
}

int	ps_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (-1);
}

void	flag_init(t_form *flag)
{
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 0;
	flag->bench = 0;
	return ;
}

int	flag_check(t_form *flag, char **argv, int argc)
{
	int	i;

	i = 1;
	flag_init(flag);
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ps_strncmp(argv[i], "--simple", 8) == 0)
			flag->simple = 1;
		else if (ps_strncmp(argv[i], "--medium", 8) == 0)
			flag->medium = 1;
		else if (ps_strncmp(argv[i], "--complex", 9) == 0)
			flag->complex = 1;
		else if (ps_strncmp(argv[i], "--adaptive", 10) == 0)
			flag->adaptive = 1;
		else if (ps_strncmp(argv[i], "--bench", 7) == 0)
			flag->bench = 1;
		else
			return (-1);
		i++;
	}
	if (flag->simple + flag->medium + flag->complex + flag->adaptive > 1)
		return (-1);
	return (i);
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

void	write_error(void)
{
	write(2, "Error\n", 6);
	return ;
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

	// デバッグ用
	current = head->top;
	i = 0;
	while (i < head->size)
	{
		printf("node %d: addr=%p, next=%p, prev=%p\n", i, (void *)current,
			(void *)current->next, (void *)current->prev);
		current = current->next;
		i++;
	}

	printf("DEBUG: freeing addr=%p (i=%d, size=%d)\n", (void *)current, i,
		head->size);
}

int	main(int argc, char **argv)
{
	t_stack	heada;
	t_form	flag;

	if (argc <= 1)
		return (0);
	if (parse(&heada, &flag, argc, argv) == -1)
	{
		write_error();
		return (-1);
	}
	print_stack(&heada);
	ft_lstclear(&heada);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	heada;
// 	t_form	flag;

// 	// t_stack	headb;
// 	if (parse(&heada, &flag, argc, argv) == -1)
// 		write_error();
// 	return(0);
// }
