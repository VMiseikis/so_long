/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:18:37 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/10 17:00:41 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

typedef struct s_img
{
	void	*img;
	int		endian;
	void	*addr;
	int		b_per_px;
	int		l_len;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_sprite
{
	t_img	wall;
	t_img	bg_t;
	t_img	exit_off;
	t_img	coll;
	t_img	v;
	t_img	black;
	t_img	enm;
	t_img	end;
	int		sp_w;
	int		sp_h;
	int		v_w;
	int		v_h;
	int		e_w;
	int		e_h;
}	t_sprite;

typedef struct s_map
{
	char	**map_grid;
	int		r_c;
	int		c_c;
	int		points;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_backg
{
	char	*px_l;
	t_point	p1;
	t_point	p2;
	t_img	bg_img;
}	t_backg;

typedef struct s_player
{
	t_point	p;
	t_point	off;
	int		pl_dir;
	int		pl_frame;
	int		sp_w;
	int		sp_h;
	t_img	pl_img;
}	t_player;

typedef struct s_coll
{
	t_img	coll_img;
	int		coll_fr;
	int		sp_w;
	int		sp_h;
}	t_coll;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
}	t_keys;

typedef struct s_ex_on
{
	t_img	on_img;
	int		ex_fr;
	int		sp_w;
	int		sp_h;
}	t_ex_on;

typedef struct s_hitbox
{
	t_point			p;
	int				flag;
	char			type;
	struct s_hitbox	*next;
}	t_hitbox;

typedef struct s_enemy
{
	t_point			pos;
	int				enm_dir;
	int				enm_frame;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			w;
	int			h;
	t_hitbox	*hbox;
	t_enemy		*enm;
	t_enemy		tmp_enm;
	t_map		map;
	t_backg		bg;
	t_sprite	sp;
	t_point		pos;
	t_player	pl;
	t_coll		coll;
	t_keys		keys;
	t_ex_on		ex_on;
	int			step_size;
	int			step_count;
	int			frame_limit;
	int			state;
	int			temp;
}	t_game;

int		ft_get_map(int fd, t_game *game);
int		ft_rec_rec_collision(int i, int j, int x, int y);
int		ft_collision_detection(t_game *game, int x, int y, int flag);
int		ft_check_if_rectangle(t_game *game);
int		ft_check_map_elem(t_game *game);
void	ft_player_offset(t_game *game);
void	ft_background_offset(t_game *game);
void	ft_load_sprites(t_game *game);
void	ft_sprite_to_img(t_game *game, t_img *tile, int x);
void	ft_generate_hitbox(t_game *game, int x, int y, char c);
void	ft_free_hitbox_list(t_hitbox **lst);
void	ft_create_bg_img(t_game *game);
int		ft_ignore_black_color(t_img *tile, int i, int j);
void	ft_draw_player_to_bg(t_game *game, t_img *tile);
void	ft_render(t_game *game);
void	ft_render_image(t_game *game);
int		ft_frames(t_game *game);
void	ft_key_action(t_game *game);
int		ft_key_release(int keycode, t_game *game);
int		ft_key_press(int keycode, t_game *game);
int		ft_exit(t_game *game);
void	ft_collectible_animation(t_game *game);
void	ft_player_move_anim(t_game *game);
void	ft_free_enemy_lst(t_enemy **lst);
void	ft_draw_enemies(t_game *game);
int		ft_random_number(int i, int j);
int		ft_enemy_collision(t_game *game, int x, int y);
int		ft_pl_enm_collision(int i, int j, int x, int y);
void	ft_enm_mov_cases(t_game *game, t_enemy	*enemies);
#endif