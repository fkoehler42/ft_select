/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:15:30 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/17 12:39:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem			*arrow_up(t_select *select, char *move, t_elem *list_pos)
{
	int		i;
	t_elem	*new_pos;

	i = 0;
	if (!(new_pos = list_pos->prev))
	{
		i = select->nb_elem / select->rows;
		new_pos = select->last;
		select->pos_x = select->nb_elem % select->rows == 0 ?
		(select->max_len + 1) * (i - 1) : (select->max_len + 1) * i;
		select->pos_y = select->nb_elem % select->rows == 0 ?
		select->rows - 1 : (select->nb_elem % select->rows) - 1;
	}
	else if (select->pos_y == 0)
	{
		select->pos_x -= (select->max_len + 1);
		select->pos_y = select->rows - 1;
	}
	else
		select->pos_y -= 1;
	tputs(tgoto(move, select->pos_x, select->pos_y), 1, &putchar);
	return (new_pos);
}

t_elem			*arrow_down(t_select *select, char *move, t_elem *list_pos)
{
	t_elem	*new_pos;

	if (!(new_pos = list_pos->next))
	{
		new_pos = select->first;
		select->pos_x = 0;
		select->pos_y = 0;
	}
	else if (select->pos_y == (select->rows - 1))
	{
		select->pos_x += (select->max_len + 1);
		select->pos_y = 0;
	}
	else
		select->pos_y += 1;
	tputs(tgoto(move, select->pos_x, select->pos_y), 1, &putchar);
	return (new_pos);
}

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

t_elem			*arrow_left(t_select *select, char *move, t_elem *list_pos)
{
	size_t	i;
	t_elem	*new_pos;

	i = 0;
	if (!(new_pos = list_pos->prev))
		return (arrow_up(select, move, list_pos));
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
	tputs(tgoto(move, select->pos_x, select->pos_y), 1, &putchar);
	return (new_pos);
}

t_elem			*arrow_right(t_select *select, char *move, t_elem *list_pos)
{
	t_elem	*new_pos;

	if (!list_pos->next)
		return (arrow_down(select, move, list_pos));
	return (0);
}
