/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_list_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 12:12:45 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/28 18:05:18 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	while (stack)
	{
		ft_printf("\nprint number: number: %i\n", stack->content);
		stack = stack->next;
	}
}

int	ft_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst -> next ;
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
