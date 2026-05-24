

#include "pushswap.h"

void	print_stack(t_stack *head)
{
	t_node	*current;
	int		i;

	if (head == NULL || head->top == NULL)
	{
		printf("  (empty stack)\n");
		return ;
	}
	current = head->top;
	i = 0;
	while (i < head->size)
	{
		printf("  [%d] value = %ld\n", i, current->value);
		current = current->next;
		i++;
	}
	printf("  size = %d\n", head->size);
}

int	main(int argc, char **argv)
{
	t_stack	heada;
	t_form	flag;
	double	d;

	if (argc <= 1)
	{
		printf("no arguments\n");
		return (0);
	}
	if (parse(&heada, &flag, argc, argv) == -1)
	{
		write_error();
		return (1);
	}
	printf("=== parsed stack ===\n");
	print_stack(&heada);
	printf("=== disorder ===\n");
	d = disorder(&heada);
	printf("  disorder = %.4f (%.2f%%)\n", d, d * 100);
	printf("=== strategy by disorder ===\n");
	if (d < 0.2)
		printf("  -> simple (O(n^2))\n");
	else if (d < 0.5)
		printf("  -> medium (O(n sqrt n))\n");
	else
		printf("  -> complex (O(n log n))\n");
	ft_lstclear(&heada);
	return (0);
}