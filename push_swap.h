/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 19:10:08 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/03/29 21:58:25 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/headers/libft.h"
# include <stdlib.h>
# include <limits.h>

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"

typedef struct s_stack
{
	int				content;
	char			c;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	sort_elements(t_stack **stack);

void	print_list(t_stack *stack);

t_stack	*lstlast(t_stack *lst);

void	lstadd_back(t_stack **lst, t_stack *new);

t_stack	*lstnew(int content);

void	swap(t_stack **stack, char c);

void	reverse_rotate(t_stack **stack, char c);

void	rotate(t_stack **stack, char c);

void	push(t_stack **stack_a, t_stack **stack_b, char c);

char	**validate_input(char **input);

int		ft_stacksize(t_stack *lst);

#endif
