/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:20:54 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/13 20:16:09 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <ft_printf.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>

#define debug ft_putendl(__FILE__)

typedef struct		s_elem
{
	char			*str;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_select
{
	size_t			nb_elem;
	size_t			max_len;
	size_t			rows;
	size_t			col;
	struct termios	termios;
	struct winsize	winsize;
	struct s_elem	*first;
	struct s_elem	*last;
}					t_select;

void				init_select_struct(t_select *select, int nb_args);
void				init_term(t_select *select);

void				exit_error(int errnum, char *arg);
void				winsize_error(int errnum);

int					putchar(int c);
int					print_list(t_select *select);
int					read_input(t_select *select);

int					store_args(t_select *select, int ac, char **av);
int					add_elem(t_select *select, char *elem);

#endif
