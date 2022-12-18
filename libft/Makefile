# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:40:53 by vmiseiki          #+#    #+#              #
#    Updated: 2021/12/05 19:07:33 by vmiseiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

COMPILER = gcc

CFLAGS = -Wall -Wextra -Werror

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
	ar -r $(NAME) $(OBJ)
	
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all