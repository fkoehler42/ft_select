/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:15:30 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/21 20:34:52 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem			*arrow_up(t_select *select, t_elem *list_pos)
{
	int		i;
	t_elem	*new_pos;

	i = 0;
	if (!(new_pos = list_pos->prev))
		new_pos = select->last;
	list_pos->cursor = 0;
	new_pos->cursor = 1;
	return (new_pos);
}

t_elem			*arrow_down(t_select *select, t_elem *list_pos)
{
	t_elem	*new_pos;

	if (!(new_pos = list_pos->next))
		new_pos = select->first;
	list_pos->cursor = 0;
	new_pos->cursor = 1;
	return (new_pos);
}
t_elem			*arrow_left(t_select *select, t_elem *list_pos)
{
	int		i;
	t_elem	*new_pos;

	if (select->col == 1)
		return (arrow_up(select, list_pos));
	i = select->rows;
	new_pos = list_pos;
	while (i-- && new_pos)
		new_pos = new_pos->prev;
	if (!new_pos)
	{
		new_pos = list_pos;
		if (!list_pos->prev && (select->nb_elem % select->rows == 0))
			i = (select->rows * select->col) - 1;
		else
			i = (select->rows * (select->col - 1)) - 1;
		while (i-- && new_pos->next)
			new_pos = new_pos->next;
	}
	list_pos->cursor = 0;
	new_pos->cursor = 1;
	return (new_pos);
}

t_elem			*arrow_right(t_select *select, t_elem *list_pos)
{
	int		i;
	t_elem	*new_pos;

	if (select->col == 1)
		return (arrow_down(select, list_pos));
	i = select->rows;
	new_pos = list_pos;
	while (i-- && new_pos)
		new_pos = new_pos->next;
	if (!new_pos)
	{
		new_pos = list_pos;
		if (!list_pos->next && (select->nb_elem % select->rows == 0))
			i = (select->rows * select->col) - 1;
		else
			i = (select->rows * (select->col - 1)) - 1;
		while (i-- && new_pos->prev)
			new_pos = new_pos->prev;
	}
	list_pos->cursor = 0;
	new_pos->cursor = 1;
	return (new_pos);
}
