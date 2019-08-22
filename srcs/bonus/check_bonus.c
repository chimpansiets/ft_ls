/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:31:18 by svoort         #+#    #+#                */
/*   Updated: 2019/08/22 15:26:17 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define SUDOKU		"sudoku"
#define SHOP		"shop"

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
	return (0);
}
