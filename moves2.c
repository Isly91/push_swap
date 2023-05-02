/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 10:07:13 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/02 10:07:46 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	sa(t_stack **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}
