/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 16:48:50 by svoort         #+#    #+#                */
/*   Updated: 2019/09/21 13:00:39 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_or_init(t_linelist **list, char *content, struct tm time, \
			char *filename)
{
	if (!(*list))
		*list = ft_linelstnew(content, ft_strlen(content) + 1, time, filename);
	else
		ft_linelstadd(list, ft_linelstnew(content, \
		ft_strlen(content) + 1, time, filename));
}

void		print_list(t_linelist *list)
{
	t_linelist	*tmp;

	tmp = list;
	if (!g_fl.flags.r && tmp)
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

void		print_files(char *folder)
{
	DIR				*d;
	struct dirent	*dir;
	char			**paths;
	t_linelist		*lines;
	int				i;

	init_variables_to_reduce_lines(&paths, &lines, &d, folder);
	i = 0;
	if (d)
	{
		print_header(folder);
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.' || g_fl.flags.a == 1)
			{
				check_and_get_path(&dir, &paths, &i, &folder);
				print_and_add_to_lines(folder, dir, &lines);
			}
		}
		print_and_sort(&lines);
		closedir(d);
	}
	else
		ft_printf("Error: can't open given folder\n");
	biggie_r_recursion(paths, lines);
}
