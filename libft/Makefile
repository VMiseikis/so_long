# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:40:53 by vmiseiki          #+#    #+#              #
#    Updated: 2022/12/18 16:39:01 by vmiseiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m

# Name of the program
NAME = libft.a

# Compilation flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

SRC = ft_strlen.c\
ft_strchr.c\
ft_memcpy.c\
ft_max.c\
ft_min.c\
ft_copy_2d_arr.c\
ft_2d_arr_len.c\
ft_free_double_arr.c\
ft_itoa.c\
ft_strdup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
	
clean:
	@rm -f *.o

fclean: clean
	@rm -f *.a

re: fclean all

.PHONY: all clean fclean re bonus