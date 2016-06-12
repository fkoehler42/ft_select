/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:45:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/12 21:08:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_error(int errnum, char *arg)
{
	ft_putstr_fd("ft_select: ", 2);
	if (errnum == 0)
		ft_putstr_fd("unable to retrieve the environnement variable TERM\n", 2);
	else if (errnum == 1)
	{
		ft_putstr_fd("unable to load the entry ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(" from the terminfo database\n", 2);
	}
	else if (errnum == 2)
		ft_putstr_fd("unable to retrieve the terminal state informations\n", 2);
	else if (errnum == 3)
		ft_putstr_fd("unable to set the terminal parameters\n", 2);
	else if (errnum == 4)
		ft_putstr_fd("memory allocation has failed\n", 2);
	exit(EXIT_FAILURE);
}
