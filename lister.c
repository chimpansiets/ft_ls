/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lister.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:19:25 by svoort         #+#    #+#                */
/*   Updated: 2019/03/30 16:10:29 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/xattr.h>
#include <locale.h>
#include <grp.h>
#include <langinfo.h>
#include <time.h>
#include <stdint.h>

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

void	ft_uid(void)
{
	struct passwd	*p;

	if ( ( p = getpwuid( getuid() )) == NULL)
	{
		fprintf(stderr, "WRONG\n");
		exit(1);
	}
	printf( "login name  %s\n", p->pw_name );
	printf( "login name  %s\n", p->pw_passwd );
    printf( "user ID     %d\n", p->pw_uid );
    printf( "group ID    %d\n", p->pw_gid );
    printf( "home dir    %s\n", p->pw_dir );
    printf( "login shell %s\n", p->pw_shell );
}

void	ext_attr(int argc, char **argv)
{
	struct stat sb;
	struct passwd *pwuser;
	struct group *grpnam;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s: file ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++)
	{
		if (-1 == stat(argv[i], &sb))
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

		printf("%s:\n", argv[i]);
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
}

int main(int argc, char **argv) {
	ext_attr(argc, argv);
    return 0;
}
