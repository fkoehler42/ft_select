/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 20:49:31 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/22 14:37:12 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char	*file_colorization(char *file)
{
	struct stat	buf;

	if ((lstat(file, &buf)) == 0)
	{
		if (S_ISBLK(buf.st_mode))
			return (ft_strdup(BLUE));
		else if (S_ISCHR(buf.st_mode))
			return (ft_strdup(GREEN));
		else if (S_ISDIR(buf.st_mode))
			return (ft_strdup(CYAN));
		else if (S_ISLNK(buf.st_mode))
			return (ft_strdup(PURPLE));
		else if (S_ISSOCK(buf.st_mode))
			return (ft_strdup(YELLOW));
		else if (S_ISFIFO(buf.st_mode))
			return (ft_strdup(RED));
	}
	return (ft_strdup(WHITE));
}

int			add_elem(t_select *select, char *elem)
{
	t_elem	*new;

	if (!(new = (t_elem *)malloc(sizeof(*new))))
		exit_error(4, "");
	new->str = ft_strdup(elem);
	new->select = 0;
	new->next = NULL;
	if (!(select->first))
	{
		new->cursor = 1;
		select->first = new;
		select->last = new;
		new->prev = NULL;
	}
	else
	{
		new->cursor = 0;
		select->last->next = new;
		new->prev = select->last;
		select->last = new;
	}
	new->color = file_colorization(new->str);
	return (0);
}

int			store_args(t_select *select, int ac, char **av)
{
	int		i;
	size_t	len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		add_elem(select, av[i]);
		if ((len = ft_strlen(av[i])) > select->max_len)
			select->max_len = len;
		i++;
	}
	return (0);
}
