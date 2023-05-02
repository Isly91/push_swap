/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:05:27 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/02 15:45:22 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*allocate_stack(int argc, char **numbers)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	i = -1;
	stack = NULL;
	while (++i < argc)
	{
		new = lstnew(ft_atoi(numbers[i]));
		if (! new)
		{
			ft_free_leaks(stack);
			exit(EXIT_FAILURE);
		}
		lstadd_back(&stack, new);
	}
	stack->index = 'a';
	return (stack);
}

void	sort_stack(t_stack **stack_a, int argc)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc <= 5)
		sort_elements(stack_a, argc);
	else
		ft_radix_sort(stack_a, &stack_b, argc);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (count_argc(argv) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		argc = count_argc(argv);
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
