/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_folders.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 11:42:21 by svoort         #+#    #+#                */
/*   Updated: 2019/08/21 15:47:27 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_folders(char **folders)
{
	int	i;

	i = 0;
	while (folders[i][0] != '\0')
	{
		ft_printf("%s\n", folders[i]);
		i++;
	}
}

char	**get_folders(int argc, char **argv)
{
	char	**ret;
	int		i;
	int		index;

	i = 1;
	index = 0;
	ret = (char**)ft_memalloc(sizeof(char*) * argc + 2);
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			ret[index] = ft_strdup(argv[i]);
			index++;
		}
		i++;
	}
	if (ret[0] == NULL)
	{
		ret[0] = ft_strdup(".");
		ret[1] = NULL;
	}
	return (ret);
}
