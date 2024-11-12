# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:46:15 by rpedrosa          #+#    #+#              #
#    Updated: 2024/11/12 16:50:12 by rpedrosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = get_next_line.a

RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: flcean all


