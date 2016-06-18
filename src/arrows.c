/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:15:30 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/18 14:51:26 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem			*arrow_up(t_select *select, t_elem *list_pos)
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
	new_pos->cursor = 1;
	return (new_pos);
}

t_elem			*arrow_down(t_select *select, t_elem *list_pos)
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
	new_pos->cursor = 1;
	return (new_pos);
}
