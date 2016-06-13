/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:52:50 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/13 16:20:20 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_select_struct(t_select *select, int nb_elem)
{
	select->nb_elem = nb_elem;
	select->max_len = 0;
	select->first = NULL;
}

void	init_term(t_select *select)
{
	char	*term_name;

	if ((term_name = getenv("TERM")) == NULL)
		exit_error(0, "");
	if ((tgetent(NULL, term_name)) == ERR)
		exit_error(1, term_name);
	if ((tcgetattr(0, &(select->termios))) == -1)
		exit_error(2, "");
	select->termios.c_lflag &= ~(ICANON);
	select->termios.c_lflag &= ~(ECHO);
	select->termios.c_cc[VMIN] = 1;
	select->termios.c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, &(select->termios))) == -1)
		exit_error(3, "");
}
