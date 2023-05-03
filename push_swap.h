/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 19:10:08 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/03 14:47:24 by ibehluli      ########   odam.nl         */
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
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_isnumber(int c);

char	**handle_quotes(char **input);

long	ft_long_atoi(const char *str);

int		count_argc(char **argv);

int		ft_duplicate(char **input);

void	sort_elements(t_stack **stack, int argc);

void	print_list(t_stack *stack);

t_stack	*lstlast(t_stack *lst);

void	lstadd_back(t_stack **lst, t_stack *new);

t_stack	*lstnew(int content);

void	swap(t_stack **stack);

void	reverse_rotate(t_stack **stack);

void	rotate(t_stack **stack);

void	push(t_stack **stack_a, t_stack **stack_b);

char	**validate_input(char **input);

int		ft_stacksize(t_stack *stack);

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

int		ft_stack_is_sorted(t_stack *stack);

void	sort_3_elements(t_stack	**stack);

void	pa(t_stack **stack_a, t_stack **stack_b);

void	pb(t_stack **stack_b, t_stack **stack_a);

void	ra(t_stack **stack);

void	rra(t_stack **stack);

void	sa(t_stack **stack);

int		min_val_distance(t_stack *stack_a, int value);

void	ft_free_leaks(t_stack *stack);

#endif
