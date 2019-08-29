/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:41:33 by svoort         #+#    #+#                */
/*   Updated: 2019/08/29 09:34:25 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_folders(char **folders_to_free)
{
	int		i;

	i = 0;
	while (folders_to_free[i])
		free(folders_to_free[i++]);
	free(folders_to_free);
}

void	free_lines(t_linelist *lines)
{
	t_linelist	*prev;

	while (lines)
	{
		prev = lines;
		lines = lines->next;
		free(prev->content);
		free(prev);
	}
}