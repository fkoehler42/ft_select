/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:45:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/18 18:52:07 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			putchar(int c)
{
	write(1, &c, 1);
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
	tmp->cursor || tmp->select ? set_print_cap(tmp) : (0);
	ft_putstr(tmp->str);
	tmp->cursor || tmp->select ? unset_print_cap(tmp) : (0);
	i = select->max_len - ft_strlen(tmp->str) + 1;
	while (i--)
		ft_putchar(' ');
	while (--j && tmp)
	{
		i = select->rows;
		while (i-- && tmp)
			tmp = tmp->next;
		if (tmp)
		{
			tmp->cursor || tmp->select ? set_print_cap(tmp) : (0);
			ft_putstr(tmp->str);
			tmp->cursor || tmp->select ? unset_print_cap(tmp) : (0);
			i = select->max_len - ft_strlen(tmp->str) + 1;
			while (i--)
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
}

int			print_list(t_select *select)
{
	size_t	i;
	char	*clear;
	t_elem	*tmp;

	if (!(clear = tgetstr("cl", NULL)))
		exit_error(7, "");
	if (calculate_layout(select) == -1)
		return (-1);
	tputs(clear, 0, &putchar);
	i = select->rows;
	tmp = select->first;
	while (i--)
	{
		print_row(select, tmp);
		tmp = tmp->next;
	}
	return (0);
}
