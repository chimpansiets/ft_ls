/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   block_size.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 09:51:37 by svoort         #+#    #+#                */
/*   Updated: 2019/09/02 09:53:39 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_block_size(char* directory)
{
	int				size;
	DIR				*d;
	struct dirent	*dir;
	struct stat		file_stat;

	d = opendir(directory);
	size = 0;
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (dir->d_name[0] != '.') { // Ignore hidden files
				// Create the path to stat
				char info_path[PATH_MAX + 1];
				strcpy(info_path, directory);
				if (directory[strlen(directory) - 1] != '/')
					strcat(info_path, "/");
				strcat(info_path, dir->d_name);	
				stat(info_path, &file_stat);	
				size += file_stat.st_blocks;
			}
		}
	}

	return (size);
}