/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:15:30 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/14 20:58:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem	*arrow_up(t_select *select, char *move, t_elem *list_pos)
{
	(void)select;
	(void)move;
	(void)list_pos;
	return (0);
}

t_elem	*arrow_down(t_select *select, char *move, t_elem *list_pos)
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

t_elem	*arrow_left(t_select *select, char *move, t_elem *list_pos)
{
	(void)select;
	(void)move;
	(void)list_pos;
	return (0);
}

t_elem	*arrow_right(t_select *select, char *move, t_elem *list_pos)
{
	(void)select;
	(void)move;
	(void)list_pos;
	return (0);
}
