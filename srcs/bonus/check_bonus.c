/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:31:18 by svoort         #+#    #+#                */
/*   Updated: 2019/08/22 14:19:48 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define SUDOKU		"sudoku"
#define KATSU		"katsu"

int		ft_check_bonus_flags(int argc, char **argv)
{
	if (ft_strequ(&argv[1][1], SUDOKU))
	{
		solve_sudoku(argc, argv);
		return (1);
	}
	else if (ft_strequ(&argv[1][1], KATSU))
	{
		solve_katsu(argc, argv);
		return (1);
	}
	return (0);
}
