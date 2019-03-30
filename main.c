/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:14:11 by svoort         #+#    #+#                */
/*   Updated: 2019/03/30 17:37:11 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		read_flags(int argc, char **argv)
{
	int	i;
	int	file_found;
	int	flags;

	i = 1;
	file_found = 0;
	flags = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && file_found == 0)
			store_flags(argv[i], &flags);
		else
			file_found = 1;
		i++;
	}
	return (flags);
}

int		main(int argc, char **argv)
{
	int	flags;

	flags = 0;
	if (argc > 1)
		flags = read_flags(argc, argv);
	listdir(argv[1]);
}
