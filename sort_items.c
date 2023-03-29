/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_items.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 14:29:05 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/29 16:55:15 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate(stack);

// reverse_rotate(stack);

// push(stack_a, stack_b);

// swap(stack);

// 1 elementi
// gia ordinato

// 2 elementi
// 1 3 gia ordinato
// 3 1 swap

// 3 elementi
// 1 2 3 gia ordinato
// 3 2 1 rotate + swap
// 3 1 2 rotate
// 2 1 3 swap
// 2 3 1 reverse_rotate
// 1 3 2 reverse_rotate + swap

// 4 elementi
// 1 2 3 4 gia ordinati
// 2 4 1 3 reverse_rotate reverse_rotate push
// use function 3 elementi
// push back the smallest

void	sort_3_elements(t_stack	**stack)
{
	int	first;
	int	second;
	int	third;
	char	c;

	c = (*stack)->c;
	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && first > third && second > third)
	{
		rotate(stack, c);
		swap(stack, c);
	}
	else if (first > second && first > third && second < third)
		rotate(stack, c);
	else if (first > second && first < third && second < third)
		swap(stack, c);
	else if (first < second && first > third && second > third)
		reverse_rotate(stack, c);
	else if (first < second && first < third && second > third)
	{
		reverse_rotate(stack, c);
		swap(stack, c);
	}
	else
		return ;
}

void sort_5_elements(t_stack **stack)
{
	t_stack *stack_b;
	//char	c;
	int	smallest_number;
	int	index;
	int lst_size;

	stack_b = NULL;
	//c = stack_b->c;
	lst_size = ft_stacksize(*stack);
	index = 0;
	//ft_printf("%d", lst_size);
	smallest_number = (*stack)->content;
	while (*stack)
	{
		if (smallest_number > (*stack)->content)
			smallest_number = (*stack)->content;
		index++;
		*stack = (*stack)->next;
	}
	while (lst_size > 3)
	{
		ft_printf("%d", lst_size);
		push(stack, &stack_b, (*stack)->c);
		lst_size--;
	}
	//print_list(stack_b);
}

void	sort_elements(t_stack **stack)
{
	if (! (*stack)->next)
		return ;
	else if (! (*stack)->next->next)
	{
		if ((*stack)->content > (*stack)->next->content)
			swap(stack, (*stack)->c);
	}
	else if (! (*stack)->next->next->next)
		sort_3_elements(stack);
	else
	{
		sort_5_elements(stack);
	}
}
