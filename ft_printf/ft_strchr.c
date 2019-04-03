/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 08:31:59 by svoort         #+#    #+#                */
/*   Updated: 2019/04/02 15:47:14 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char*)s;
	while (*ptr != c && *ptr != '\0')
		ptr++;
	if (*ptr != c)
		return (NULL);
	else
		return (ptr);
}
