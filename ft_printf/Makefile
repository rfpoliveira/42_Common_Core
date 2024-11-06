# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 16:13:42 by rpedrosa          #+#    #+#              #
#    Updated: 2024/11/06 16:19:55 by rpedrosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###Files###

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

###ALIAS###

RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft/

###Rules###

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) libft/libft.a

$(LIBFT): 
	cd $(LIBFTDIR)
	make
	
%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
