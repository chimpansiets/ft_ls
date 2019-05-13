/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_sudoku.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 18:52:01 by svoort         #+#    #+#                */
/*   Updated: 2019/05/11 13:56:35 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	solve_sudoku(int argc, char **argv)
{
	extern char **environ;
	char		**arguments;

	arguments = read_sudoku_file(argc, argv);
	// Eerste argument moet filename worden, nu geen zin.
	execve("/Users/svoort/.brew/bin/sudoku_solver", arguments, environ);
}
