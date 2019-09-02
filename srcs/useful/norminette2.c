/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norminette2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:14:21 by svoort         #+#    #+#                */
/*   Updated: 2019/09/02 10:08:15 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	biggie_r_recursion(char **paths, t_linelist *lines)
{
	int		i;

	i = 0;
	while (paths[i])
	{
		print_files(paths[i]);
		i++;
	}
	free_folders(paths);
	free_lines(lines);
}

void	init_variables_to_reduce_lines(char ***paths, \
		t_linelist **lines, DIR **d, char *folder)
{
	(*paths) = (char**)ft_memalloc(sizeof(char*) * 1000);
	(*lines) = NULL;
	(*d) = opendir(folder);
}

void	print_and_sort(t_linelist **lines)
{
	sort_list(lines);
	print_list(*lines);
}

void	print_header(char *folder)
{
	ft_printf("%s: \n", folder);
	if (g_fl.flags.l)
		ft_printf("total %i\n", get_block_size(folder));
}
