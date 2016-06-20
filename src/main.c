/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:29:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/20 18:32:04 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int ac, char **av)
{
	t_select	select;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	sig_set();
	init_select_struct(&select, (ac - 1));
	init_term(&select);
	store_args(&select, ac, av);
	if (print_list(&select) == 0)
		read_input(&select);
	return (0);
}
