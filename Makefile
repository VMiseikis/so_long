# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 12:45:38 by vmiseiki          #+#    #+#              #
#    Updated: 2021/12/10 18:18:34 by vmiseiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES = -Iincludes
LIBRARIES = -Llibraries -lmlx -Llibraries -lft
MFLAGS = -framework OpenGL -framework AppKit -lz -o
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx
LIBFT_DIR = ./libft
CC = gcc

SRC = ft_so_long.c\
ft_get_map.c\
ft_colisions.c\
ft_offset.c\
ft_load_sprites.c\
ft_sprite_to_bg.c\
ft_hitbox.c\
ft_create_bg_img.c\
ft_ignore_black_color.c\
ft_player_to_bg.c\
ft_anim_sett.c\
ft_key.c\
ft_enemy_to_bg.c\
ft_random.c\
ft_enm_mov_cases.c

MANDATORY = ft_render.c\
ft_check_map.c\

BONUS = ft_render_bonus.c\
ft_check_map_bonus.c\

all: lib_make $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(MFLAGS) $(NAME) $(SRC) $(MANDATORY) $(INCLUDES) $(LIBRARIES)

bonus: lib_make
	$(CC) $(CFLAGS) $(MFLAGS) $(NAME) $(SRC) $(BONUS) $(INCLUDES) $(LIBRARIES)

lib_make:
	$(MAKE) -C $(MLX_DIR)
	mv -f $(MLX_DIR)/libmlx.a libraries
	$(MAKE) -C $(LIBFT_DIR)
	mv -f $(LIBFT_DIR)/libft.a libraries

clean:
	rm -f *.o
	rm -f $(MLX_DIR)/*.o
	rm -f $(LIBFT_DIR)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_DIR)/*.a
	rm -f $(LIBFT_DIR)/*.a
	rm -f ./libraries/*.a

re: fclean all