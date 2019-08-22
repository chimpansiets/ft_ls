/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 16:48:50 by svoort         #+#    #+#                */
/*   Updated: 2019/08/22 14:11:27 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(char *folder)
{
	DIR				*d;
	struct dirent	*dir;
	char			**paths;
	int				i;

	paths = (char**)ft_memalloc(sizeof(char*) * 1000);
	d = opendir(folder);
	i = 0;
	if (d)
	{
		ft_printf("\e[1;35m%s:\n\e[0m", folder); // after this we can get stat() of folder and then print st_blocks.
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.' || g_fl.flags.a == 1)
			{
				if (dir->d_type == DT_DIR && g_fl.flags.biggie_r == 1 && \
				!ft_strequ(dir->d_name, ".") && !ft_strequ(dir->d_name, ".."))
				{
					paths[i] = get_path(folder, dir->d_name);
					i++;
				}
				ft_printfile(folder, dir);
			}
		}
		closedir(d);
	}
	else
	{
		ft_printf("\e[1;35m%s:\n\e[0m", folder);
		ft_printf("Error: can't open given folder\n");
	}
	i = 0;
	while (paths[i])
		print_files(paths[i++]);
	free_all(paths);
}
