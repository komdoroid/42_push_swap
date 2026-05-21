# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    disorder.c                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/21 21:30:56 by kkomurat          #+#    #+#              #
#    Updated: 2026/05/21 21:33:40 by kkomurat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

double	disorder(t_stack *head)
{
	long	mistakes;
	int	size;
	double	total_pairs;

	size = head->size;
	if (size < 2)
		return (0.0);
	mistakes = calc_mistakes(head, size);
	total_pairs = (double)size * (size - 1) / 2;
	return ((double)mistakes / total_pairs);
}

long	calc_mistakes(t_stack *head, int size)
{
	int	i;
	int	j;
	t_node	*left;
	t_node	*right;
	long	mistakes;

	left = head->top;
	right = left->next;
	mistakes = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (left->value > right-> value)
				mistakes++;
			right = right->next;
			j++;
		}
		left = left->next;
		right = left->next;
		i++;
	}
	return (mistakes);
}
