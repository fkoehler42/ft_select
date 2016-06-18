/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:19:53 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/18 18:52:04 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	key_return(t_select *select)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	restore_term(select);
	if ((tmp = select->first))
	{
		while (tmp)
		{
			if (tmp->select)
			{
				if (i)
					ft_putchar(' ');
				ft_putstr(tmp->str);
				i++;
			}
			tmp = tmp->next;
		}
	}
	exit(EXIT_SUCCESS);
}

void	key_esc(t_select *select)
{
	restore_term(select);
	exit(EXIT_SUCCESS);
}

t_elem	*key_space(t_select *select, t_elem *list_pos)
{
	if (list_pos->select == 0)
		list_pos->select = 1;
	else
		list_pos->select = 0;
	list_pos->cursor = 0;
	return (arrow_down(select, list_pos));
}

t_elem	*key_delete(t_select *select, t_elem *list_pos)
{
	t_elem	*new_pos;

	if (select->nb_elem == 1)
		key_esc(select);
	if (!list_pos->prev)
	{
		select->first = list_pos->next;
		select->first->prev = NULL;
		new_pos = select->first;
	}
	else if (!list_pos->next)
	{
		select->last = list_pos->prev;
		select->last->next = NULL;
		new_pos = select->last;
	}
	else
	{
		list_pos->prev->next = list_pos->next;
		list_pos->next->prev = list_pos->prev;
		new_pos = list_pos->next;
	}
	free(list_pos->str);
	free(list_pos);
	new_pos->cursor = 1;
	select->nb_elem--;
	return (new_pos);
}
