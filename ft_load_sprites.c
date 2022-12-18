/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:20:40 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/08 01:08:21 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_get_img_address_1(t_game *game)
{
	game->bg.bg_img.addr = mlx_get_data_addr(game->bg.bg_img.img,
			&game->bg.bg_img.b_per_px, &game->bg.bg_img.l_len,
			&game->bg.bg_img.endian);
	game->sp.wall.addr = mlx_get_data_addr(game->sp.wall.img,
			&game->sp.wall.b_per_px, &game->sp.wall.l_len,
			&game->sp.wall.endian);
	game->ex_on.on_img.addr = mlx_get_data_addr(game->ex_on.on_img.img,
			&game->ex_on.on_img.b_per_px, &game->ex_on.on_img.l_len,
			&game->ex_on.on_img.endian);
	game->sp.exit_off.addr = mlx_get_data_addr(game->sp.exit_off.img,
			&game->sp.exit_off.b_per_px, &game->sp.exit_off.l_len,
			&game->sp.exit_off.endian);
	game->sp.bg_t.addr = mlx_get_data_addr(game->sp.bg_t.img,
			&game->sp.bg_t.b_per_px, &game->sp.bg_t.l_len,
			&game->sp.bg_t.endian);
	game->coll.coll_img.addr = mlx_get_data_addr(game->coll.coll_img.img,
			&game->coll.coll_img.b_per_px, &game->coll.coll_img.l_len,
			&game->coll.coll_img.endian);
	game->sp.black.addr = mlx_get_data_addr(game->sp.black.img,
			&game->sp.black.b_per_px, &game->sp.black.l_len,
			&game->sp.black.endian);
}

void	ft_get_img_address_2(t_game *game)
{
	game->pl.pl_img.addr = mlx_get_data_addr(game->pl.pl_img.img,
			&game->pl.pl_img.b_per_px, &game->pl.pl_img.l_len,
			&game->pl.pl_img.endian);
	game->sp.v.addr = mlx_get_data_addr(game->sp.v.img,
			&game->sp.v.b_per_px, &game->sp.v.l_len,
			&game->sp.v.endian);
	game->sp.enm.addr = mlx_get_data_addr(game->sp.enm.img,
			&game->sp.enm.b_per_px, &game->sp.enm.l_len,
			&game->sp.enm.endian);
	game->sp.end.addr = mlx_get_data_addr(game->sp.end.img,
			&game->sp.end.b_per_px, &game->sp.end.l_len,
			&game->sp.end.endian);
}

void	ft_check_sp_load(t_game *game)
{
	if (!game->sp.wall.img || !game->sp.bg_t.img
		|| !game->sp.exit_off.img || !game->ex_on.on_img.img
		|| !game->coll.coll_img.img || !game->pl.pl_img.img
		|| !game->sp.v.img || !game->sp.black.img
		|| !game->sp.enm.img || !game->sp.end.img)
	{
		printf("Error\nError occurred while loafding sprites!\n");
		printf("Program was terminated!\n");
		ft_exit(game);
	}
}

void	ft_load_sprites(t_game *game)
{
	game->sp.wall.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/egle.xpm", &game->sp.sp_w, &game->sp.sp_h);
	game->sp.bg_t.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/snow.xpm", &game->sp.sp_w, &game->sp.sp_h);
	game->sp.exit_off.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/egle.xpm", &game->sp.sp_w, &game->sp.sp_h);
	game->ex_on.on_img.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/egle2.xpm", &game->ex_on.sp_w, &game->ex_on.sp_h);
	game->coll.coll_img.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/spinning_box.xpm", &game->coll.sp_w, &game->coll.sp_h);
	game->pl.pl_img.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/santa_sheet.xpm", &game->pl.sp_w, &game->pl.sp_h);
	game->sp.v.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/congrats.xpm", &game->sp.v_w, &game->sp.v_h);
	game->sp.black.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/black.xpm", &game->sp.sp_w, &game->sp.sp_h);
	game->sp.enm.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/bat_sheet.xpm", &game->sp.e_w, &game->sp.e_h);
	game->sp.end.img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/end.xpm", &game->sp.v_w, &game->sp.v_h);
	ft_check_sp_load(game);
	ft_get_img_address_1(game);
	ft_get_img_address_2(game);
}
