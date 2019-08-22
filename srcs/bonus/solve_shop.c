/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_shop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:19:58 by svoort         #+#    #+#                */
/*   Updated: 2019/08/22 15:20:44 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	solve_shop(void)
{
	int		rand;
	int		fd;
	int		fd_2;
	char	buf[4];
	char	*buf_2;
	int		i;

	i = 0;
	fd = open("/dev/urandom", O_RDONLY);
	fd_2 = open("shops.txt", O_RDONLY);
	read(fd, buf, 3);
	rand = (buf[0] + buf[1] + buf[2] + 345) * 31;
	while (i < (rand % 420))
	{
		get_next_line(fd_2, &buf_2);
		i++;
	}
	ft_printf("%s\n", buf_2);
}
