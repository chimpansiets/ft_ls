/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_blocks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:32:11 by svoort         #+#    #+#                */
/*   Updated: 2019/09/20 13:12:18 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_blocks(char *folder)
{
	struct stat	file_stat;

	if (lstat(folder, &file_stat) < 0)
		ft_error("Error getting file information (-l)\n");
	ft_printf("total: %i\n", file_stat.st_blocks);
}
