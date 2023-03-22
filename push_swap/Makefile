# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamizan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 12:07:02 by alamizan          #+#    #+#              #
#    Updated: 2023/01/26 09:49:08 by alamizan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

SRC = main.c\
	  push_swap_utils.c\
	  ft_init_stack.c\
	  ft_check.c\
	  ft_errors.c\
	  ft_stacks.c\
	  ft_swap.c\
	  ft_push.c\
	  ft_rotate.c\
	  ft_reverse.c\
	  ft_split.c\
	  ft_sorts.c\
	  ft_sort_three.c\
	  ft_sort_five.c\
	  ft_radix.c\
	
CFLAGS = -Wall -Werror -Wextra -g
.c.o:
	clang $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang $(CFLAGS) -o $(NAME) $(OBJ) 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
