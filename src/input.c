/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 16:32:33 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/14 20:58:57 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem	*parse_input(t_select *select, char *buf, char *move, t_elem *list_pos)
{
	size_t	buf_len;

	buf_len = ft_strlen(buf);
	if (buf[0] == 10 && !buf[1])
		key_return(select);
	else if (buf[0] == 27 && !buf[1])
		key_esc(select);
	else if (buf[0] == 32 && !buf[1])
		key_space(select);
	else if ((buf[0] == 127 && !buf[1]) || (buf_len == 4 && buf[0] == 27
			&& buf[1] == 91	&& buf[2] == 51 && buf[3] == 126))
		key_delete(select);
	else if (buf_len == 3 && buf[0] == 27 && buf[1] == 91)
	{
		if (buf[2] == 65)
			return (arrow_up(select, move, list_pos));
		else if (buf[2] == 66)
			return (arrow_down(select, move, list_pos));
		else if (buf[2] == 67)
			return (arrow_right(select, move, list_pos));
		else if (buf[2] == 68)
			return (arrow_left(select, move, list_pos));
	}
	return (NULL);
}

int		read_input(t_select *select)
{
	t_elem	*list_pos;
	char	*move;
	char	buf[7];

	if (!(move = tgetstr("cm", NULL)))
		exit_error(7, "");
	tputs(tgoto(move, 0, 0), 1, &putchar);
	list_pos = select->first;
	while (42)
	{
		ft_bzero((void *)buf, 7);
		if (read(0, buf, 7) == -1)
			exit_error(6, "");
		if (buf[0])
			list_pos = parse_input(select, buf, move, list_pos);
	}
	return (0);
}
