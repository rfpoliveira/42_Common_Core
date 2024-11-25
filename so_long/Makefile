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

SRCS = handle_inputs.c so_long.c

#BONUS_SRCS =

OBJS = $(SRCS:.c=.o)

#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = so_long

MLX_PATH = minilibx-linux

LIBFT_PATH = libft
LIBFT_ARC = libft/libft.a
LIBFT_OBJS = libft/.build

LIB_NAME = so_long.a
###ALIAS###

RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
MAKEE = make extra

#OBJS_ALL = $(OBJS) $(BONUS_OBJS)

###Rules###

all: deps  $(LIBFT_ARC) $(LIB_NAME) $(NAME)

$(NAME): $(LIB_NAME) $(OBJS) 
	cc $(CFLAGS) $(LIBFT_ARC) $(LIB_NAME) -L$(MLX_PATH) -lmlx_Linux -Lusr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT_ARC): $(LIBFT_PATH)
	$(MAKEE) -C $(LIBFT_PATH)

$(LIB_NAME): $(OBJS)
	$(AR) $(LIB_NAME) $(OBJS) $(LIBFT_OBJS)/*.o

%.o: %.c
	cc $(CFLAGS) -I/usr/include -Iminilibx-linux -o $@ -c $<

deps:			## Download/Update libft
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(GRN)[Libft folder found]$(D)"; fi

get_libft:
	@echo "[$(CYA)Downloading Libft$(D)]"
	git clone git@github.com:rfpoliveira/42_Libft.git $(LIBFT_PATH)
	@echo "$(GRN)[Libft successfully downloaded]$(D)"

clean: 
	$(RM) $(OBJS)
	$(RM) $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB_NAME)
	$(RM) $(LIBFT_PATH)

re: fclean all

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
