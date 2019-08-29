/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:31:05 by svoort         #+#    #+#                */
/*   Updated: 2019/08/29 09:34:54 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define FLAG_S	5

static inline int	parse_flags(int argc, char **argv)
{
	int		index;

	index = 1;
	if (argc < 2)
		return (0);
	if (!ft_check_bonus_flags(argc, argv))
	{
		ft_check_real_flags(argc, argv);
		return (0);
	}
	return (1);
}

int 					main(int argc, char **argv)
{
	int		bonus;
	int		i;
	char	**folders_to_print;

	i = 0;
	bonus = parse_flags(argc, argv);
	if (!bonus)
	{
		folders_to_print = get_folders(argc, argv);
		while (folders_to_print[i] != NULL)
		{
			print_files(folders_to_print[i]);
			i++;
		}
		free_folders(folders_to_print);
	}
	return (argc);
}
