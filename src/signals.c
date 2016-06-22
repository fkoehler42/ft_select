/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 12:50:31 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/22 17:59:35 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_handler(int signum)
{
	char		suspend;
	t_select	*select;

	select = get_struct(0);
	suspend = 26;
	if (signum == 18)
	{
		signal(SIGTSTP, SIG_DFL);
		restore_term(select);
		ioctl(0, TIOCSTI, &suspend);
	}
	else if (signum == 19)
	{
		init_term(select);
		print_list(select);
		signal(SIGTSTP, &sig_handler);
	}
	else if (signum == 28)
		print_list(select);
	else
	{
		restore_term(select);
		exit(EXIT_SUCCESS);
	}
}

void	sig_set(void)
{
	int	i;

	i = 0;
	while (++i < 30)
		signal(i, &sig_handler);
}
