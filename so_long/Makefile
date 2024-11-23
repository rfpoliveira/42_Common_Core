# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 12:07:09 by rpedrosa          #+#    #+#              #
#    Updated: 2024/11/20 12:07:14 by rpedrosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###Files###

SRCS = so_long.c

#BONUS_SRCS =

OBJS = $(SRCS:.c=.o)

#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = so_long

MLX_PATH = minilibx-linux
###ALIAS###

RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

#OBJS_ALL = $(OBJS) $(BONUS_OBJS)

###Rules###

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx_Linux -Lusr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c
	cc $(CFLAGS) -I/usr/include -Iminilibx-linux -o $@ -c $<

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_ALL)
	$(AR) $(NAME) $(OBJS_ALL)
