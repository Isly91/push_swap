/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:43:09 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/19 20:34:09 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	variable;

	i = 0;
	variable = (unsigned char) c;
	if (variable)
	{
		while (s[i] != '\0')
		{
			if (s[i] == variable)
				return ((char *) s + i);
			i++;
		}
		return (0);
	}
	else
		return ((char *)s + ft_strlen(s));
}
