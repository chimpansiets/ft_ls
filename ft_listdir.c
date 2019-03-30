/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listdir.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 14:39:10 by svoort         #+#    #+#                */
/*   Updated: 2019/03/30 17:36:26 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ext_attr(const char *filename)
{
    t_file	new;
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
	new.info = sb;
	new.grpnam = grpnam;
	new.pwuser = pwuser;
    printf("%s:\n", filename);
    printf("\tinode: %llu\n", sb.st_ino);
    printf("\towner: %u (%s)\n", sb.st_uid, pwuser->pw_name);
    printf("\tgroup: %u (%s)\n", sb.st_gid, grpnam->gr_name);
    printf("\tperms: %o\n", sb.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
    printf("\tlinks: %d\n", sb.st_nlink);
    printf("\tsize: %lld\n", sb.st_size); /* you may use %lld */
    printf("\tatime: %s", ctime(&sb.st_atime));
    printf("\tmtime: %s", ctime(&sb.st_mtime));
    printf("\tctime: %s", ctime(&sb.st_ctime));
    printf("\n");
}

void listdir(char *name)
{
    DIR             *dir;
    struct dirent   *entry;
	char			*path;

    if (!(dir = opendir(name))) // hierin als het een file is
        ext_attr(name);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            ext_attr(entry->d_name);
        } else {
			path = ft_joinfree(name, "/", 0);
			path = ft_joinfree(path, entry->d_name, 1);
            ext_attr(path);
			free(path);
        }
    }
    closedir(dir);
}
