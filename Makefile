# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 16:51:35 by jubarbie          #+#    #+#              #
#    Updated: 2018/05/15 14:06:25 by jubarbie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Ilibft -IIncludes
SRC=	Sources/main.c					\
		Sources/ft_printf.c				\
		Sources/unsigned_conversions.c	\
		Sources/signed_conversions.c	\
		Sources/format.c				\
		Sources/convert.c				\
		Sources/array.c					\
		Sources/str_conversions.c		\
		Sources/flags_parsing.c			

OBJS = $(SRC:.c=.o)
NAME = ft_printf_test

.PHONY: $(NAME) fclean clean re all

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) -Llibft/ -lft -o $@ $^
	@echo "\033[32m[OK]\033[0m ft_printf_test created"

all: $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@echo "\033[32m[OK]\033[0m object files deleted"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "\033[32m[OK]\033[0m ft_printf_test deleted"

re: fclean all
