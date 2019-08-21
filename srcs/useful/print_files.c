/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 16:48:50 by svoort         #+#    #+#                */
/*   Updated: 2019/08/20 17:14:25 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    print_files(int argc, char **argv)
{
    DIR             *d;
    struct dirent   *dir;

    (void)argc;
    (void)argv;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            ft_printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}
