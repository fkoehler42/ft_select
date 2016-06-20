/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:27:57 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/20 12:46:47 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	restore_term(t_select *select)
{
	char	*clear;
	char	*show_curs;

	if (!(clear = tgetstr("cl", NULL)))
		exit_error(7, "");
	if (!(show_curs = tgetstr("ve", NULL)))
		exit_error(7, "");
	tputs(clear, select->fd, &putchar);
	tputs(show_curs, select->fd, &putchar);
	ft_putstr_fd("\033[?1049l", select->fd);
	if ((tcsetattr(0, TCSADRAIN, &(select->term_save))) == -1)
		exit_error(3, "");
}
