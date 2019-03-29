/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:29:08 by svoort         #+#    #+#                */
/*   Updated: 2019/03/29 17:17:39 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isflag(char c)
{
	char	*ptr;

	ptr = ft_strchr(ACC_FLAGS, c);
	if (ptr != NULL)
	{
		ft_putchar(c);
		return (1);
	}
	else
		return (0);
}

void	store_flags(char *str, int *flags)
{
	int	i;

	i = 1;
	(void)flags;
	while (str[i])
	{
		if (ft_isflag(str[i]))
			//ft_store();
		i++;
	}
}
