/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 16:32:33 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/13 20:16:01 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		read_input(t_select *select)
{
	char	*cap;
	char	buf[7];

	if (!cap = tgetstr("cm", NULL))
		exit_error(7, "");
	tputs(tgoto(cap, 0, 0), 1, &putchar);
	while (42)
	{
		ft_bzero((void *)buf, 7);
		if (read(0, buf, 7) == -1)
			exit_error(6, "");
		int	i = 0;
		while (buf[i])
		{
			ft_putnbr(buf[i++]);
		}
	}
	++select;
	return (0);
}
