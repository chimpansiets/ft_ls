/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:31:18 by svoort         #+#    #+#                */
/*   Updated: 2019/08/20 14:57:40 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define SUDOKU		"sudoku"

int		ft_check_bonus_flags(int argc, char **argv)
{
	if (ft_strcmp(&argv[1][1], SUDOKU) == 0)
	{
		solve_sudoku(argc, argv);
		return (1);
	}
	return (0);
}
