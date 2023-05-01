/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 08:58:59 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/01 16:30:28 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_min(t_stack **stack, long limit)
{
	t_stack	*current;
	t_stack	*min;
	int		min_found;

	if (!*stack)
		return (NULL);

	current = *stack;
	min_found = INT_MAX;
	min = NULL;

	while (current)
	{
		if (current->content > limit && current->content < min_found)
		{
			min_found = current->content;
			min = current;
		}
		current = current->next;
	}
	return (min);
}

void	ft_give_index(t_stack **stack, int size)
{
	int		i;
	long	min_found;
	t_stack	*min;
	t_stack	*copy;

	min_found = -2147483649;
	i = 0;
	while (i < size)
	{
		min = ft_get_min(stack, min_found);
		min->index = i;
		min_found = min->content;
		i++;
	}
	copy = *stack;
	while (*stack)
	{
		if ((*stack)->content == min->content)
			(*stack)->index = min->index;
		*stack = (*stack)->next;
	}
	*stack = copy;
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int	size)
{
	int	bit;
	int i;

	bit = 1;
	ft_give_index(stack_a, size);
	while (!ft_stack_is_sorted(*stack_a))
	{
		i = 0;
		while (i < size)
		{
			if ((*stack_a)->index & bit)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		bit <<= 1;
		while (*stack_b)
			pa(stack_b, stack_a);
	}
	return ;
}

