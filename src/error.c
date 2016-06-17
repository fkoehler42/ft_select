/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:45:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/17 16:18:40 by fkoehler         ###   ########.fr       */
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
	else if (errnum == 5)
		ft_putstr_fd("unable to retrieve the window size\n", 2);
	else if (errnum == 6)
		ft_putstr_fd("an error occured while reading input\n", 2);
	else if (errnum == 7)
	{
		ft_putstr_fd("Your terminal does not support the capabilities", 2);
		ft_putstr_fd("required\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	winsize_error(int errnum)
{
	if (errnum == 0)
		ft_putstr_fd("Not enough width to display the list of arguments\n", 2);
	else if (errnum == 1)
		ft_putstr_fd("Not enough height to display the list of arguments\n", 2);
	ft_putstr_fd("Please resize the window\n", 2);
}
