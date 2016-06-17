/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capabilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:54:53 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/17 20:05:24 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_print_cap(t_elem *elem)
{
	char	*underline;
	char	*reverse_video;

	if (!(underline = tgetstr("us", NULL))
		|| !(reverse_video = tgetstr("mr", NULL)))
		exit_error(7, "");
	if (elem->cursor)
		tputs(underline, 0, &putchar);
	if (elem->select)
		tputs(reverse_video, 0, &putchar);
}

void	unset_print_cap(t_elem *elem)
{
	char	*no_underline;

	if (!(no_underline = tgetstr("ue", NULL)))
		exit_error(7, "");
	elem->cursor = 0;
	tputs(no_underline, 0, &putchar);
}
