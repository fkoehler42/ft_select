/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:20:54 by fkoehler          #+#    #+#             */
/*   Updated: 2016/06/17 19:30:03 by fkoehler         ###   ########.fr       */
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
	int				cursor;
	int				select;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_select
{
	size_t			nb_elem;
	size_t			max_len;
	size_t			rows;
	size_t			col;
	size_t			pos_x;
	size_t			pos_y;
	struct termios	termios;
	struct winsize	winsize;
	struct s_elem	*first;
	struct s_elem	*last;
}					t_select;

void				init_select_struct(t_select *select, int nb_args);
void				init_term(t_select *select);

void				exit_error(int errnum, char *arg);
void				winsize_error(int errnum);

void				set_print_cap(t_elem *elem);
void				unset_print_cap();

int					putchar(int c);
int					print_list(t_select *select);
int					read_input(t_select *select);
t_elem				*parse_input(t_select *select, char *buf,
					char *move, t_elem *list_pos);

int					store_args(t_select *select, int ac, char **av);
int					add_elem(t_select *select, char *elem);

int					key_return(t_select *select);
int					key_esc(t_select *select);
int					key_space(t_select *select);
int					key_delete(t_select *select);

t_elem				*arrow_up(t_select *select, char *move, t_elem *list_pos);
t_elem				*arrow_down(t_select *select, char *move, t_elem *list_pos);
t_elem				*arrow_left(t_select *select, char *move, t_elem *list_pos);
t_elem				*arrow_right(t_select *select, char *move, t_elem *list_pos);

#endif
