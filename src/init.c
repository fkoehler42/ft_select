/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:52:50 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/22 15:39:12 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			check_empty_args(int ac, char **av)
{
	int		i;
	int		j;
	size_t	spaces;

	i = 1;
	while (i < ac)
	{
		j = 0;
		spaces = 0;
		while (av[i][j])
		{
			if (ft_isspace(av[i][j]))
				spaces++;
			j++;
		}
		if (spaces == ft_strlen(av[i]))
			return (-1);
		i++;
	}
	return (0);
}

t_select	*get_struct(t_select *struc)
{
	static t_select	*select = NULL;

	if (struc == 0)
		return (select);
	else
		select = struc;
	return (0);
}

void		init_select_struct(t_select *select, int nb_elem)
{
	if ((select->fd = open("/dev/tty", O_RDWR)) == -1)
		exit_error(8, "");
	select->nb_elem = nb_elem;
	select->max_len = 0;
	select->rows = 0;
	select->col = 0;
	select->no_display = false;
	select->first = NULL;
	select->last = NULL;
	get_struct(select);
}

void		init_term(t_select *select)
{
	char	*term_name;
	char	*hide_curs;

	if ((term_name = getenv("TERM")) == NULL)
		exit_error(0, "");
	if ((tgetent(NULL, term_name)) == -1)
		exit_error(1, term_name);
	if ((tcgetattr(0, &(select->term_save))) == -1)
		exit_error(2, "");
	if ((tcgetattr(0, &(select->termios))) == -1)
		exit_error(2, "");
	select->termios.c_lflag &= ~(ICANON);
	select->termios.c_lflag &= ~(ECHO);
	select->termios.c_cc[VMIN] = 1;
	select->termios.c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, &(select->termios))) == -1)
		exit_error(3, "");
	if (!(hide_curs = tgetstr("vi", NULL)))
		exit_error(7, "");
	tputs(hide_curs, select->fd, &putchar);
}
