/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 18:41:23 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/04/25 19:13:00 by ibehluli      ########   odam.nl         */
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
		first_element->prev = second_element;
		second_element->prev = NULL;
		*stack = second_element;
	}
	else
	{
		third_element = (*stack)->next->next;
		first_element->next = third_element;
		second_element->next = first_element;
		first_element->prev = second_element;
		third_element->prev = first_element;
		second_element->prev = NULL;
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
		head->prev = tail;
	}
	head->prev = NULL;
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
	head->prev = NULL;
	head->next = *stack;
	(*stack)->prev = head;
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

	if(!head_b)
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

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ra(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	sa(t_stack **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}