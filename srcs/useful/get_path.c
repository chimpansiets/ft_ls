/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 13:59:20 by svoort         #+#    #+#                */
/*   Updated: 2019/08/22 11:49:11 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_path(char *folder, char *dir_name)
{
	char	*path;

	if (folder[ft_strlen(folder) - 1] != '/')
	{
		path = ft_strjoin(folder, "/");
		path = ft_joinfree(path, dir_name, 1);
	}
	else
		path = ft_strjoin(folder, dir_name);
	return (path);
}
