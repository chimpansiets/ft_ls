/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:31:18 by svoort         #+#    #+#                */
/*   Updated: 2019/09/02 10:30:24 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define SUDOKU		"sudoku"
#define SHOP		"shop"
#define HELP		"help"

int		ft_check_bonus_flags(int argc, char **argv)
{
	if (ft_strequ(&argv[1][1], SUDOKU))
	{
		solve_sudoku(argc, argv);
		return (1);
	}
	else if (ft_strequ(&argv[1][1], SHOP))
	{
		solve_shop();
		return (1);
	}
	else if (ft_strequ(&argv[1][1], HELP))
	{
		ft_printf("\e[1;31musage: ./ft_ls [-lRart] [file ...]\e[0m");
		return (1);
	}
	return (0);
}
