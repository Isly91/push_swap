/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 18:41:23 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/02 10:22:24 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
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
		*stack = second_element;
	}
	else
	{
		third_element = (*stack)->next->next;
		first_element->next = third_element;
		second_element->next = first_element;
		*stack = second_element;
	}
}

void	rotate(t_stack **stack)
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
	}
}

void	reverse_rotate(t_stack **stack)
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
	head->next = *stack;
	*stack = head;
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*second_element_a;

	head_a = *stack_a;
	head_b = *stack_b;
	second_element_a = head_a->next;
	if (*stack_a == NULL)
		return ;
	if (!head_b)
	{
		head_a = second_element_a;
		head_b = *stack_a;
		head_b->next = *stack_b;
	}
	else
	{
		head_b = head_a;
		head_b->next = *stack_b;
		head_a = second_element_a;
	}
	*stack_b = head_b;
	*stack_a = head_a;
}
