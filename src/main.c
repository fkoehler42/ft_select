/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:29:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/22 15:40:41 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int ac, char **av)
{
	t_select	select;

	if (ac < 2)
	{
		ft_putstr_fd("ft_select: argument(s) required\n", 2);
		exit(EXIT_SUCCESS);
	}
	if (check_empty_args(ac, av) == -1)
	{
		ft_putstr_fd("ft_select: invalid argument(s): empty string\n", 2);
		exit(EXIT_SUCCESS);
	}
	sig_set();
	init_select_struct(&select, (ac - 1));
	init_term(&select);
	store_args(&select, ac, av);
	print_list(&select);
	read_input(&select);
	return (0);
}
