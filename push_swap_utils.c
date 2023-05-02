/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 10:02:51 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/02 10:41:54 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_free_leaks(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
