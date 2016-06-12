/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 20:49:31 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/12 21:27:37 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		add_elem(t_select *select, char *elem)
{
	t_arg	*new;

	if (!(new = (t_arg *)malloc(sizeof(*new))))
		exit_error(4, "");
	new->str = ft_strdup(elem);
	new->next = NULL;
	if (!(select->first))
	{
		select->first = new;
		select->last = new;
		new->prev = NULL;
	}
	else
	{
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
