# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achemlal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 11:41:59 by achemlal          #+#    #+#              #
#    Updated: 2024/11/21 12:07:36 by achemlal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_unsigned_putnbr.c ft_puthex.c ft_putadr.c ft_printf.c

OBJ = $(SRC:.c=.o);

all = $(Name)

$(Name): $(OBJ)
	@ar rcs $(Name) $(OBJ)
	@echo "Library $(NAME) created."

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(Name)
	@echo "Library $(NAME) removed."

re : fclean all

