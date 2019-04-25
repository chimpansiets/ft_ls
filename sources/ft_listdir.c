/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listdir.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 14:39:10 by svoort         #+#    #+#                */
/*   Updated: 2019/04/15 09:30:46 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	append_list(t_file *elem, t_file **list)
{
	t_file	*ptr;

	ptr = *list;
	if (ptr == NULL)
		*list = elem;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = elem;
	}
}

void	ext_attr(const char *filename, t_file **list)
{
    t_file			*new;
	struct stat		sb;
	struct passwd	*pwuser;
	struct group	*grpnam;

    if (-1 == stat(filename, &sb))
    {
        perror("stat()");
        exit(EXIT_FAILURE);
    }

    if (NULL == (pwuser = getpwuid(sb.st_uid)))
    {
        perror("getpwuid()");
        exit(EXIT_FAILURE);
    }

    if (NULL == (grpnam = getgrgid(sb.st_gid)))
    {
        perror("getgrgid()");
        exit(EXIT_FAILURE);
    }
	// printf("lmao\n");
	new = (t_file*)malloc(sizeof(t_file));
	new->filename = ft_strdup(filename);
	new->info = sb;
	new->grpnam = grpnam;
	new->pwuser = pwuser;
	new->next = NULL;
	append_list(new, list);
}

void listdir(char *name)
{
    DIR             *dir;
    struct dirent   *entry;
	char			*path;
	t_file			*files;
	t_file			*ptr;
	int				i;

	i = 0;
	files = NULL;
    if (!(dir = opendir(name)))
        ext_attr(name, &files);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
			if (ft_strlen(name) > 0 && name[ft_strlen(name) - 1] != '/')
			{
            	path = ft_joinfree(name, "/", 0);
				path = ft_joinfree(path, entry->d_name, 1);
			}
			else
				path = ft_joinfree(name, entry->d_name, 0);
			printf("path: %s\n", path);
            ext_attr(path, &files);
			i++;
			free(path);
        } else {
			if (ft_strlen(name) > 0 && name[ft_strlen(name) - 1] != '/')
			{
            	path = ft_joinfree(name, "/", 0);
				path = ft_joinfree(path, entry->d_name, 1);
			}
			else
				path = ft_joinfree(name, entry->d_name, 0);
			printf("path: %s\n", path);
            ext_attr(path, &files);
			i++;
			free(path);
        }
    }
	ptr = files;
	while (ptr)
	{
		printf("filename: %s\n", ptr->filename);
		ptr = ptr->next;
	}
    closedir(dir);
}
