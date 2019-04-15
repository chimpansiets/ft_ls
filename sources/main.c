/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:14:11 by svoort         #+#    #+#                */
/*   Updated: 2019/04/15 09:30:30 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
	flags = read_flags(argc, argv);
	if (argc < 2)
		listdir(".");
	else
		listdir(argv[1]);
}
