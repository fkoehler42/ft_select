/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:29:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/12 21:31:06 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			main(int ac, char **av)
{
	t_select	select;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	init_struct(&select);
	init_term(&select);
	store_args(&select, ac, av);
	while (select.first)
	{
		ft_putendl(select.first->str);
		select.first = select.first->next;
	}
	return (0);
}
