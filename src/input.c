/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 16:32:33 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/20 19:18:36 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem	*parse_input(t_select *select, char *buf, t_elem *list_pos)
{
	size_t	buf_len;

	buf_len = ft_strlen(buf);
	if (buf[0] == 10 && !buf[1])
		key_return(select);
	else if ((buf[0] == 27 || buf[0] == 4) && !buf[1])
		key_esc(select);
	else if (buf[0] == 32 && !buf[1])
		return(key_space(select, list_pos));
	else if ((buf[0] == 127 && !buf[1]) || (buf_len == 4 && buf[0] == 27 &&
				buf[1] == 91 && buf[2] == 51 && buf[3] == 126))
		return (key_delete(select, list_pos));
	else if (buf_len == 3 && buf[0] == 27 && buf[1] == 91)
	{
		if (buf[2] == 65)
			return (arrow_up(select, list_pos));
		else if (buf[2] == 66)
			return (arrow_down(select, list_pos));
		else if (buf[2] == 67)
			return (arrow_right(select, list_pos));
		else if (buf[2] == 68)
			return (arrow_left(select, list_pos));
	}
	return (NULL);
}

int		read_input(t_select *select)
{
	t_elem	*list_pos;
	char	buf[7];

	list_pos = select->first;
	while (42)
	{
		ft_bzero((void *)buf, 7);
		if (read(0, buf, 7) == -1)
			exit_error(6, "");
		if (buf[0])
		{
			if ((list_pos = parse_input(select, buf, list_pos)))
				print_list(select);
		}
	}
	return (0);
}
