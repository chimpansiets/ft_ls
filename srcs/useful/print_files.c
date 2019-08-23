/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 16:48:50 by svoort         #+#    #+#                */
/*   Updated: 2019/08/23 13:51:47 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_or_init(t_list **list, char *content)
{
	if (!(*list))
		*list = ft_lstnew(content, ft_strlen(content) + 1);
	else
		ft_lslstadd(list, ft_lstnew(content, ft_strlen(content) + 1));
}

void	print_files(char *folder)
{
	DIR				*d;
	struct dirent	*dir;
	char			**paths;
	char			*tmp_line;
	t_list			*lines;
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
					paths[i++] = get_path(folder, dir->d_name);
				tmp_line = ft_printfile(folder, dir);
				add_or_init(&lines, tmp_line);
				free(tmp_line);
			}
		}
		sort_list(&lines);
		print_list(lines);
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
