# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/12 19:50:07 by fkoehler          #+#    #+#              #
#    Updated: 2016/06/13 17:03:43 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c ./src

SRC = error.c \
	  init.c \
	  main.c \
	  print.c \
	  read.c \
	  store.c

NAME = ft_select

FLAGS = -g -Wall -Werror -Wextra

LIBDIR = ./libft/

INCLUDES = $(LIBDIR)includes/

LIB = $(LIBDIR)libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@gcc $(FLAGS) $(OBJ) -L$(LIBDIR) -lft -o $@ -ltermcap
	@echo "\033[0;32mft_select compilation done !"

$(LIB):
	@make -C $(LIBDIR)

%.o: %.c
	@gcc $(FLAGS) -c $< -I . -I $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@echo "\033[0;32mObject files deleted !"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32mExecutable deleted !"

re: fclean all
