/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 18:41:23 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/29 12:34:08 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*first_element;
	t_stack	*second_element;
	t_stack	*third_element;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_element = *stack;
	second_element = (*stack)->next;
	if (!second_element->next)
	{
		first_element->next = NULL;
		second_element->next = first_element;
		first_element->prev = second_element;
		*stack = second_element;
	}
	else
	{
		third_element = second_element->next;
		first_element->next = third_element;
		second_element->next = first_element;
		first_element->prev = second_element;
		third_element->prev = first_element;
		second_element->prev = NULL;
		*stack = second_element;
	}
	ft_printf("s%c\n", c);
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	*stack = head->next;
	head->next = NULL;
	if (*stack)
	{
		tail = *stack;
		while (tail->next)
			tail = tail->next;
		tail->next = head;
		head->prev = tail;
	}
	head->prev = NULL;
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack		*head;
	t_stack		*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	while (head->next)
	{
		tail = head;
		head = head->next;
	}
	if (!tail)
		return ;
	tail->next = NULL;
	head->prev = NULL;
	head->next = *stack;
	(*stack)->prev = head;
	*stack = head;
	ft_printf("rr%c\n", c);
}

void	push(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*second_element_a;

	if (!stack_a || !*stack_a)
		return ;
	second_element_a = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = *stack_a;
	*stack_b = *stack_a;
	*stack_a = second_element_a;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	ft_printf("p%c\n", c);
}
