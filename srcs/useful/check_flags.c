/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 15:05:50 by svoort         #+#    #+#                */
/*   Updated: 2019/08/20 16:43:07 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    parse_flags(char *flags)
{
    int     i;

    i = 1;
    while (flags[i])
    {
        if (flags[i] == 'l')
            g_fl.flags.l = 1;
        else if (flags[i] == 'R')
            g_fl.flags.biggie_r = 1;
        else if (flags[i] == 'a')
            g_fl.flags.a= 1;
        else if (flags[i] == 'r')
            g_fl.flags.r = 1;
        else if (flags[i] == 't')
            g_fl.flags.t = 1;
        else
            ft_error("ls: illegal option -- z\nusage: ls [-lRart] [file ...]\n");
        i++;
    }
}

void    ft_check_real_flags(int argc, char **argv)
{
    int     i;

    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-')
            parse_flags(argv[i]);
        else
            return ;
        i++;
    }
}
