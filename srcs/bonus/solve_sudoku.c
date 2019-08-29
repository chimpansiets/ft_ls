/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_sudoku.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 18:52:01 by svoort         #+#    #+#                */
/*   Updated: 2019/08/29 09:51:15 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	solve_sudoku(int argc, char **argv)
{
	extern char **environ;
	char		**arguments;

	arguments = read_sudoku_file(argc, argv);
	execve("/Users/svoort/.brew/bin/sudoku_solver", arguments, environ);
}
