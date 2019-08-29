/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 16:48:50 by svoort         #+#    #+#                */
/*   Updated: 2019/08/29 09:38:00 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_or_init(t_linelist **list, char *content, struct tm time)
{
	if (!(*list))
		*list = ft_linelstnew(content, ft_strlen(content) + 1, time);
	else
		ft_linelstadd(list, ft_linelstnew(content, ft_strlen(content) + 1, time));
}

static void	print_list(t_linelist *list)
{
	t_linelist	*tmp;

	tmp = list;
	if (!g_fl.flags.r)
	{
		while (tmp->next)
			tmp = tmp->next;
		while (tmp)
		{
			ft_printf("%s\n", tmp->content);
			tmp = tmp->prev;
		}
	}
	while (tmp)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_files(char *folder)
{
	DIR				*d;
	struct dirent	*dir;
	char			**paths;
	t_file			tmp_file;
	t_linelist		*lines;
	int				i;

	paths = (char**)ft_memalloc(sizeof(char*) * 1000);
	lines = NULL;
	d = opendir(folder);
	i = 0;
	if (d)
	{
		ft_printf("%s: \n\n", folder);
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.' || g_fl.flags.a == 1)
			{
				if (dir->d_type == DT_DIR && g_fl.flags.biggie_r == 1 && \
				!ft_strequ(dir->d_name, ".") && !ft_strequ(dir->d_name, ".."))
					paths[i++] = get_path(folder, dir->d_name);
				tmp_file = ft_printfile(folder, dir);
				add_or_init(&lines, tmp_file.tmp_line, tmp_file.time);
				free(tmp_file.tmp_line);
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
	free_folders(paths);
	free_lines(lines);
}
