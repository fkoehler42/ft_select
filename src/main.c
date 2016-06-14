/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:29:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/14 20:44:51 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int ac, char **av)
{
	t_select	select;

	ft_putstr("\033[?1049h\033[H");
	if (ac < 2)
		exit(EXIT_SUCCESS);
	init_select_struct(&select, (ac - 1));
	init_term(&select);
	store_args(&select, ac, av);
	print_list(&select);
	read_input(&select);
	/* ft_putstr("\033[?1049l"); */
	return (0);
}
