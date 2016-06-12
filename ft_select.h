/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:20:54 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/12 21:22:47 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <term.h>
# include <termios.h>
# include <curses.h>

typedef struct		s_arg
{
	char			*str;
	struct s_arg	*prev;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_select
{
	size_t			max_len;
	struct s_arg	*first;
	struct s_arg	*last;
	struct termios	*termios;
}					t_select;

void				init_struct(t_select *select);
void				init_term(t_select *select);
void				exit_error(int errnum, char *arg);

int					store_args(t_select *select, int ac, char **av);
int					add_elem(t_select *select, char *elem);

#endif
