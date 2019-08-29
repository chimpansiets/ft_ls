/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linelist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 13:00:49 by svoort         #+#    #+#                */
/*   Updated: 2019/08/29 10:00:41 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_linelstadd(t_linelist **alst, t_linelist *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		(*alst)->prev = new;
		*alst = new;
	}
}

t_linelist	*ft_linelstnew(void const *content, \
			size_t content_size, struct tm time)
{
	t_linelist	*new;

	new = (t_linelist*)ft_memalloc(sizeof(t_linelist));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (char*)ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->time = time;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
