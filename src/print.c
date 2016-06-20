/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:45:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/20 19:55:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			putchar(int c)
{
	t_select	*select;

	select = get_struct(0);
	write(select->fd, &c, 1);
	return (0);
}

static int	calculate_layout(t_select *select)
{
	if ((ioctl(0, TIOCGWINSZ, &(select->winsize))) < 0)
		exit_error(5, "");
	if (!(select->col = select->winsize.ws_col / (select->max_len + 1)))
	{
		winsize_error(0);
		return (-1);
	}
	select->rows = (select->nb_elem % select->col == 0) ?
	select->nb_elem / select->col : (select->nb_elem / select->col) + 1;
	if (select->rows > select->winsize.ws_row)
	{
		winsize_error(1);
		return (-1);
	}
	return (0);
}

static void	print_row(t_select *select, t_elem *elem)
{
	int		i;
	int		j;
	t_elem	*tmp;

	j = select->col;
	tmp = elem;
	tmp->cursor || tmp->select ? set_print_cap(select->fd, tmp) : (0);
	ft_putstr_fd(tmp->str, select->fd);
	tmp->cursor || tmp->select ? unset_print_cap(select->fd, tmp) : (0);
	i = select->max_len - ft_strlen(tmp->str) + 1;
	while (i--)
		ft_putchar_fd(' ', select->fd);
	while (--j && tmp)
	{
		i = select->rows;
		while (i-- && tmp)
			tmp = tmp->next;
		if (tmp)
		{
			tmp->cursor || tmp->select ? set_print_cap(select->fd, tmp) : (0);
			ft_putstr_fd(tmp->str, select->fd);
			tmp->cursor || tmp->select ? unset_print_cap(select->fd, tmp) : (0);
			i = select->max_len - ft_strlen(tmp->str) + 1;
			while (i--)
				ft_putchar_fd(' ', select->fd);
		}
	}
	ft_putchar_fd('\n', select->fd);
}

int			print_list(t_select *select)
{
	size_t	i;
	t_elem	*tmp;

	ft_putstr_fd("\033[?1049h\033[H", select->fd);
	if (calculate_layout(select) == -1)
		return (-1);
	i = select->rows;
	tmp = select->first;
	while (i--)
	{
		print_row(select, tmp);
		tmp = tmp->next;
	}
	return (0);
}
