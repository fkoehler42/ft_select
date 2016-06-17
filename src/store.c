/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 20:49:31 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/17 18:48:40 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		add_elem(t_select *select, char *elem)
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
	return (0);
}

int		store_args(t_select *select, int ac, char **av)
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
