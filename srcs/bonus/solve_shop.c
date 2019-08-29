/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_shop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 09:51:28 by svoort         #+#    #+#                */
/*   Updated: 2019/08/29 09:52:20 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	solve_shop(void)
{
	int		rand;
	int		fd;
	char	buf[4];
	char	*buf_2;
	int		i;

	i = 0;
	fd = open("/dev/urandom", O_RDONLY);
	read(fd, buf, 3);
	rand = (buf[0] + buf[1] + buf[2] + 345) * 31;
	fd = open("shops.txt", O_RDONLY);
	while (i < (rand % 420))
	{
		get_next_line(fd, &buf_2);
		i++;
	}
	ft_printf("%s\n", buf_2);
}
