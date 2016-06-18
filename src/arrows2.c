/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:15:30 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/18 14:52:16 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_elem	*arrow_left2(t_select *select, size_t i)
{
	t_elem	*new_pos;

	new_pos = select->last;
	if ((i = select->nb_elem % select->rows) == 0 || (i >= select->pos_y))
	{
		if (i == 0)
			i = select->rows;
		while (i-- > select->pos_y && new_pos)
			new_pos = new_pos->prev;
		i = select->nb_elem % select->rows == 0 ? (select->nb_elem /
				select->rows) - 1 : select->nb_elem / select->rows;
		select->pos_x = (select->max_len + 1) * i;
	}
	else
	{
		i += (select->rows - select->pos_y);
		while (i-- && new_pos)
			new_pos = new_pos->prev;
		i = (select->nb_elem / select->rows) - 1;
		select->pos_x = (select->max_len + 1) * i;
	}
	select->pos_y -= 1;
	return (new_pos);
}

t_elem			*arrow_left(t_select *select, t_elem *list_pos)
{
	size_t	i;
	t_elem	*new_pos;

	i = 0;
	if (!(new_pos = list_pos->prev))
		return (arrow_up(select, list_pos));
	else if (select->pos_x == 0)
		new_pos = arrow_left2(select, i);
	else
	{
		i = select->rows;
		new_pos = list_pos;
		while (i-- && new_pos)
			new_pos = new_pos->prev;
		select->pos_x -= select->max_len + 1;
	}
	new_pos->cursor = 1;
	return (new_pos);
}

static t_elem	*arrow_right2(t_select *select, size_t i, t_elem *list_pos)
{
	t_elem	*new_pos;

	new_pos = NULL;
	i = select->rows;
	new_pos = list_pos;
	while (i-- && new_pos)
		new_pos = new_pos->next;
	if (!new_pos && ((select->rows - select->pos_y) > 1))
	{
		new_pos = select->first;
		i = select->pos_y + 1;
		while (i-- && new_pos)
			new_pos = new_pos->next;
		select->pos_x = 0;
		select->pos_y += 1;
	}
	else if (new_pos)
		select->pos_x += select->max_len + 1;
	else
		return (list_pos);
	return (new_pos);
}

t_elem			*arrow_right(t_select *select, t_elem *list_pos)
{
	size_t	i;
	t_elem	*new_pos;

	i = 0;
	if (!(new_pos = list_pos->next))
		return (arrow_down(select, list_pos));
	else if (select->pos_x == ((select->col - 1) * (select->max_len + 1)))
	{
		new_pos = select->first;
		i = select->pos_y + 1;
		while (i-- && new_pos)
			new_pos = new_pos->next;
		select->pos_x = 0;
		select->pos_y += 1;
	}
	else
		new_pos = arrow_right2(select, i, list_pos);
	new_pos->cursor = 1;
	return (new_pos);
}
