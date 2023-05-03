/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:30:51 by ibehluli      #+#    #+#                 */
/*   Updated: 2022/10/21 12:16:31 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	i = 0;
	dest = (char *) s1;
	src = (char *) s2;
	while ((dest[i] != '\0' || src[i] != '\0') && i < n && n >= 0)
	{
		if (dest[i] == src[i])
			i++;
		else
		{
			if ((unsigned char) dest[i] - (unsigned char) src[i] > 0)
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}
