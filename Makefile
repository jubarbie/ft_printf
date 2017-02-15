# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 16:51:35 by jubarbie          #+#    #+#              #
#    Updated: 2017/01/09 14:29:23 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Ilibft -IIncludes -Wall -Wextra -Werror
SRC=	Sources/main.c				\
		Sources/ft_printf.c			

OBJS = $(SRC:.c=.o)
NAME = ft_printf_test

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) -Llibft/ -lft -o $@ $^
	@echo "\033[32m[OK]\033[0m ft_printf_test created"

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJ)
	@echo "\033[32m[OK]\033[0m object files deleted"

.PHONY: fclean

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "\033[32m[OK]\033[0m ft_printf_test deleted"

re: fclean all
