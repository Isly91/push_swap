/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:05:27 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/29 21:58:32 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*allocate_stack(int argc, char **numbers)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (i < argc)
	{
		lstadd_back(&stack, lstnew(ft_atoi(numbers[i])));
		i++;
	}
	stack->c = 'a';
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

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
	sort_elements(&stack);
	print_list(stack);
	return (0);
}
