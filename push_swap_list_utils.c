/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_list_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:12:45 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/02 15:47:57 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	if (stack == NULL)
		ft_printf("Empty stack");
	while (stack)
	{
		ft_printf("print number: number: %i\n", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	ft_stacksize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*lstnew(int content)
{
	t_stack	*something;

	something = (t_stack *) malloc(sizeof (t_stack));
	if (!something)
		return (NULL);
	something -> content = content;
	something -> next = NULL;
	return (something);
}

int	count_argc(char **argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	return (i);
}
