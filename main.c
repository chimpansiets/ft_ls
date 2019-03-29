/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:14:11 by svoort         #+#    #+#                */
/*   Updated: 2019/03/29 16:55:21 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void listdir(const char *name, int indent)
{
	DIR *dir;
	struct dirent *entry;

	if (!(dir = opendir(name)))
		return;
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_DIR) {
			char path[1024];
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
			printf("%*s[%s]\n", indent, "", entry->d_name);
			listdir(path, indent + 2);
		} else {
			printf("%*s- %s\n", indent, "", entry->d_name);
		}
	}
	closedir(dir);
}

void	read_arguments(int argc, char **argv)
{
	int	i;
	int	file_found;
	int	flags;

	i = 1;
	file_found = 0;
	flags = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && file_found == 0)
			store_flags(argv[i], &flags);
		else
			file_found = 1;
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		read_arguments(argc, argv);
}