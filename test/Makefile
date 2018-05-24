# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 16:51:35 by jubarbie          #+#    #+#              #
#    Updated: 2018/05/16 13:17:53 by jubarbie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -I../rendu/libft -I../rendu/Includes
SRC=	main.c
	
OBJS = $(SRC:.c=.o)
NAME = printf_test

all: $(NAME)

.PHONY: $(NAME) fclean clean re all test

$(NAME): $(OBJS)
	@make -C ../rendu
	@$(CC) -L../rendu/ -lftprintf -o $@ $^

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJS)
	@echo "\033[32m[OK]\033[0m object files deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[32m[OK]\033[0m ft_printf_test deleted"

re: fclean all
