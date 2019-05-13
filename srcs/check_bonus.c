/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:31:18 by svoort         #+#    #+#                */
/*   Updated: 2019/05/11 13:33:33 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define SUDOKU		"sudoku"
#define KATSU		"katsu"
#define SHOP		"shop"
#define RNG			"rng"
#define DEDICATE	"dedicate"
#define MIMMA		"mimma"
#define COALITIONS	"coalitions"
#define VELA		"vela"

int		ft_check_bonus_flags(int argc, char **argv)
{
	if (ft_strcmp(&argv[1][1], SUDOKU) == 0)
		solve_sudoku(argc, argv);
	// else if (ft_strcmp(&argv[1][1], KATSU))
	// 	katsu();
	// else if (ft_strcmp(&argv[1][1], SHOP))
	// 	shop();
	// else if (ft_strcmp(&argv[1][1], RNG))
	// 	rng();
	// else if (ft_strcmp(&argv[1][1], DEDICATE))
	// 	dedicate();
	// else if (ft_strcmp(&argv[1][1], MIMMA))
	// 	mimma();
	// else if (ft_strcmp(&argv[1][1], COALITIONS))
	// 	coalitions();
	// else if (ft_strcmp(&argv[1][1], VELA))
	// 	vela();
	return (0);
}
