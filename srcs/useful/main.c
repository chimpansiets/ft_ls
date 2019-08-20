/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:31:05 by svoort         #+#    #+#                */
/*   Updated: 2019/08/20 16:04:12 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define FLAG_S	5

static inline int	parse_flags(int argc, char **argv)
{
	int		index;

	index = 1;
	if (argc < 2)
		return (1);
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

	bonus = parse_flags(argc, argv);
	ft_printf("%i%i%i%i%i\n", FLAG_L, FLAG_BIG_R, \
			FLAG_A, FLAG_R, FLAG_T);
	if (!bonus)
	{
		// print_files(argc, argv);
	}
	return (argc);
}
