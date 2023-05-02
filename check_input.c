/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 17:10:01 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/02 10:19:52 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate(char **input)
{
	int	i;
	int	e;

	i = 0;
	while (input[i])
	{
		e = i + 1;
		while (input[e])
		{
			if (ft_atoi(input[e]) == ft_atoi(input[i]))
				return (1);
			e++;
		}
		i++;
	}
	return (0);
}

static int	ft_white_spaces(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (0);
	return (1);
}

long	ft_long_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	number = LONG_MIN;
	sign = 1;
	while ((str[i] < '0' || str[i] > '9'))
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			if (str[i] == '-')
				sign = -1;
		}
		else if ((str[i] > 32) || ft_white_spaces(str[i]))
			break ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * sign);
}

int	ft_isnumber(int c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	return (0);
}
