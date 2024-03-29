/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   block_size.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 09:51:37 by svoort         #+#    #+#                */
/*   Updated: 2019/09/21 13:30:00 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_block_size(char *directory)
{
	int				size;
	DIR				*d;
	struct dirent	*dir;
	struct stat		file_stat;
	char			info_path[PATH_MAX + 1];

	d = opendir(directory);
	size = 0;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.')
			{
				ft_strcpy(info_path, directory);
				if (directory[strlen(directory) - 1] != '/')
					ft_strcat(info_path, "/");
				ft_strcat(info_path, dir->d_name);
				lstat(info_path, &file_stat);
				size += file_stat.st_blocks;
			}
		}
	}
	return (size);
}
