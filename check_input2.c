/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 10:01:01 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/02 10:05:33 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '+' || input[i] == '-')
		{
			if (input[i + 1] == '0')
				return (1);
		}
		if ((input[i] >= '0' && input[i] <= '9') && (input[i + 1] == '+'
				|| input[i + 1] == '-'))
			return (1);
		if (ft_isnumber(input[i]) == 0)
			return (1);
		i++;
	}
	if (ft_atoi(input) != ft_long_atoi(input))
		return (1);
	return (0);
}

char	**validate_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (check_error(input[i]))
		{
			ft_printf(RED "Error\n"RESET);
			exit(EXIT_FAILURE);
		}
		if (ft_duplicate(input) == 1)
		{
			ft_printf(RED "Error\n"RESET);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (input);
}
