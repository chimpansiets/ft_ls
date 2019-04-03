/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 09:52:12 by svoort         #+#    #+#                */
/*   Updated: 2019/03/10 19:02:50 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(i + 1);
	if (!s1 || !(s2))
		return (0);
	s2[i] = '\0';
	while (i > 0)
	{
		i--;
		s2[i] = s1[i];
	}
	return (s2);
}
