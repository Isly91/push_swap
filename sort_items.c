/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_items.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 14:29:05 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/04/25 18:51:37 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_stack	**stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && first > third && second > third)
	{
		ra(stack);
		sa(stack);
	}
	else if (first > second && first > third && second < third)
		ra(stack);
	else if (first > second && first < third && second < third)
		sa(stack);
	else if (first < second && first > third && second > third)
		rra(stack);
	else if (first < second && first < third && second > third)
	{
		rra(stack);
		sa(stack);
	}
	else
		return ;
}

void	sort_4_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp_value;
	int	distance;
	t_stack	*curr;

	curr = *stack_a;
	tmp_value = curr->content;
	while (curr->next)
	{
		if (curr->next->content < tmp_value)
			tmp_value = curr->next->content;
		curr = curr->next;
	}
	curr = *stack_a;
	distance = min_val_distance(curr, tmp_value);
	if(distance == 0)
		pb(stack_a, stack_b);
	else if (distance == 1)
	{
	 	sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (distance == 2)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_3_elements(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp_value;
	int	distance;
	t_stack	*curr;

	curr = *stack_a;
	tmp_value = curr->content;
	while (curr->next)
	{
		if (curr->next->content < tmp_value)
			tmp_value = curr->next->content;
		curr = curr->next;
	}
	curr = *stack_a;
	distance = min_val_distance(curr, tmp_value);
	if (distance == 0)
		pb(stack_a, stack_b);
	else if (distance == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_4_elements(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	sort_elements(t_stack **stack, int argc)
{
	t_stack *stack_b;
	
	stack_b = NULL;
	
	if (argc <= 3)
		free(stack_b);
	if (argc == 1 || ft_stack_is_sorted(*stack))
		return ;
	if (argc == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
		else
			return ;
	}
	else if (argc == 3)
		sort_3_elements(stack);
	else if (argc == 4)
		sort_4_elements(stack, &stack_b);
	else
		sort_5_elements(stack, &stack_b);
}
