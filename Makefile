# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 12:26:32 by pdeguing          #+#    #+#              #
#    Updated: 2018/08/09 10:17:18 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line 
CFLAG = -Wall -Wextra -Werror
SRC = *.c
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB)
	gcc -o $(NAME) $(CFLAG) $(SRC) -lft -L./libft/ 

$(LIB):
	cd libft/ && make

clean:
	cd libft/ && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft/ && make fclean

re: fclean all

.PHONY: clean fclean all re
