/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_list_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:12:45 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/01 17:14:30 by ibehluli      ########   odam.nl         */
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

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lista;

	if (*lst == NULL && new)
		*lst = new;
	else
	{
		lista = lstlast(*lst);
		lista ->next = new;
	}
}

int	ft_stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	min_val_distance(t_stack *stack_a, int value)
{
	int	distance;

	distance = 0;
	while (stack_a->next && stack_a->content != value)
	{
		distance++;
		stack_a = stack_a->next;
	}
	return (distance);
}

void ft_free_leaks(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}