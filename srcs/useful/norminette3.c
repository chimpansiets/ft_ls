/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norminette3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/21 13:22:44 by svoort         #+#    #+#                */
/*   Updated: 2019/09/21 13:27:37 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*short_format_flow(struct dirent *dir, struct stat file_stat)
{
	char	*line;

	if (S_ISLNK(file_stat.st_mode))
	{
		line = ft_strdup("\e[0;35m");
		line = ft_joinfree(line, dir->d_name, 1);
		line = ft_joinfree(line, "\e[0m", 1);
	}
	else if (dir->d_type == DT_DIR && (file_stat.st_mode & S_IXOTH) == 1)
	{
		line = ft_strdup("\e[1;36m");
		line = ft_joinfree(line, dir->d_name, 1);
		line = ft_joinfree(line, "\e[0m", 1);
	}
	else if ((file_stat.st_mode & S_IXOTH) == 1)
	{
		line = ft_strdup("\e[0;31m");
		line = ft_joinfree(line, dir->d_name, 1);
		line = ft_joinfree(line, "\e[0m", 1);
	}
	else
		line = ft_strdup(dir->d_name);
	return (line);
}
