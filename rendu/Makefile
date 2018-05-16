# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 16:51:35 by jubarbie          #+#    #+#              #
#    Updated: 2018/05/16 18:18:27 by jubarbie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Ilibft -IIncludes -Wall -Wextra -Werror
SRC=	libft/ft_strlen.c				\
		libft/ft_strnew.c				\
		libft/ft_convert_base.c			\
		libft/ft_itoa_opt.c				\
		libft/ft_atoi.c					\
		libft/ft_isdigit.c				\
		libft/ft_power.c				\
		libft/ft_putendl.c				\
		libft/ft_putstr.c				\
		libft/ft_strchr.c				\
		libft/ft_strcpy.c				\
		libft/ft_strdup.c				\
		libft/ft_strequ.c				\
		libft/ft_strjoin.c				\
		libft/ft_strjoinfree.c			\
		libft/ft_strmap.c				\
		libft/ft_strncpy.c				\
		libft/ft_strrepeat.c			\
		libft/ft_toupper.c				\
		libft/ft_uitoa_opt.c			\
		libft/ft_putchar.c				\
		libft/ft_strcat.c				\
		libft/ft_strcmp.c				\
		Sources/ft_printf.c				\
		Sources/unsigned_conversions.c	\
		Sources/signed_conversions.c	\
		Sources/wchar_conversion.c		\
		Sources/format.c				\
		Sources/convert.c				\
		Sources/options.c				\
		Sources/tohex.c					\
		Sources/array.c					\
		Sources/str_conversions.c		\
		Sources/flags_parsing.c			

OBJS = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[32m[OK]\033[0m libftprintf.a created"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: fclean clean re all

clean:
	@rm -f $(OBJS)
	@echo "\033[32m[OK]\033[0m object files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32m[OK]\033[0m ft_printf_test deleted"

re: fclean all
