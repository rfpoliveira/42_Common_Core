# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 10:00:30 by rpedrosa          #+#    #+#              #
#    Updated: 2024/10/31 11:09:14 by rpedrosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###Files###

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	  get_next_line.c get_next_line_fd.c r_free.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			 ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF = $(LIBFTDIR)/libftprintf.a
PRINTFDIR = ft_printf

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = libft.a

###ALIAS###

RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

OBJS_ALL = $(OBJS) $(BONUS_OBJS)

###Rules###

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(AR) $(NAME) $(OBJS) $(PRINTFDIR)/*.o

$(PRINTF): $(PRINTFDIR)
	$(MAKE) -C $(PRINTFDIR)
	
%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

clean: 
	$(RM) $(OBJS_ALL)
	$(MAKE) clean -C $(PRINTFDIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(PRINTFDIR)

re: fclean all

bonus: $(OBJS_ALL)
	$(AR) $(NAME) $(OBJS_ALL)
