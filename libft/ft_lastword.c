/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lastword.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 13:26:53 by svoort         #+#    #+#                */
/*   Updated: 2019/09/21 13:17:16 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	gets a line as input and returns a pointer to the last word in that line.
**	does NOT make a copy or duplicate of that word, just the pointer.
*/

char	*ft_lastword(char *content)
{
	if (content && *content)
	{
		while (*content)
			content++;
		content--;
		while (*content && *content != ' ')
			content--;
		content++;
		return (content);
	}
	return (NULL);
}
