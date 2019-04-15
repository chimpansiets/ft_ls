/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:29:08 by svoort         #+#    #+#                */
/*   Updated: 2019/04/15 09:30:36 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_isflag(char c)
{
	char	*ptr;

	ptr = ft_strchr(ACC_FLAGS, c);
	if (ptr != NULL)
		return (1);
	else
		return (0);
}

void	ft_store(int *flags, char c)
{
	if (c == 'l')
		*flags = *flags | 1;
	else if (c == 'R')
		*flags = *flags | 2;
	else if (c == 'a')
		*flags = *flags | 4;
	else if (c == 'r')
		*flags = *flags | 8;
	else if (c == 't')
		*flags = *flags | 16;
}

void	store_flags(char *str, int *flags)
{
	int	i;

	i = 1;
	(void)flags;
	while (str[i])
	{
		if (ft_isflag(str[i]))
			ft_store(flags, str[i]);
		i++;
	}
}
