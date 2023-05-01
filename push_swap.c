/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:05:27 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/01 18:32:33 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*allocate_stack(int argc, char **numbers)
{
	t_stack	*stack;
	int	i;

	i = -1;
	stack = NULL;
	while (++i < argc)
		lstadd_back(&stack, lstnew(ft_atoi(numbers[i])));
	stack->index = 'a';
	return (stack);
}

void	sort_stack(t_stack **stack_a, int argc)
{
	if (argc <= 5)
		sort_elements(stack_a, argc);
	else
	{
		t_stack *stack_b;
		stack_b = NULL;
		ft_radix_sort(stack_a, &stack_b, argc);
	}
}
void f_leaks(void)
{
	system("leaks push_swap");
}
int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	atexit(f_leaks);
	i = 0;
	stack = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[i])
			i++;
		if (i == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		argc = i;
	}
	else
	{
		argc--;
		argv++;
	}
	validate_input(argv);
	stack = allocate_stack(argc, argv);
	sort_stack(&stack, argc);
	ft_free_leaks(stack);
	return (0);
}
