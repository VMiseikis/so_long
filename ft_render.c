/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render mandatory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:34:51 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/08 00:35:17 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_render_window(t_game *game)
{
	game->w = 800;
	game->h = 608;
	game->window = mlx_new_window(game->mlx, game->w, game->h, "So_Long!");
}

void	ft_prepare_bg_for_counter(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_put_image_to_window(game->mlx,
			game->window, game->sp.black.img, i * 32, 0);
		i++;
	}
}

void	ft_step_count(t_game *game)
{
	char	*str;

	str = ft_itoa(game->step_count);
	mlx_string_put(game->mlx, game->window,
		16, 16, 0x00FF0000, "Player steps count: ");
	mlx_string_put(game->mlx, game->window,
		160, 16, 0x00FF0000, str);
	free(str);
}

void	ft_render_image(t_game *game)
{
	if (game->state == 0)
	{
		ft_free_hitbox_list(&game->hbox);
		ft_player_offset(game);
		ft_background_offset(game);
		ft_create_bg_img(game);
		ft_draw_player_to_bg(game, &game->pl.pl_img);
		ft_prepare_bg_for_counter(game);
		mlx_put_image_to_window(game->mlx, game->window,
			game->bg.bg_img.img, (game->pl.off.x + (game->bg.p1.x * 32)),
			(game->pl.off.y + (game->bg.p1.y * 32)));
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, game->sp.v.img, 0, 0);
	ft_step_count(game);
}

void	ft_render(t_game *game)
{
	game->mlx = mlx_init();
	ft_render_window(game);
	game->hbox = NULL;
	game->bg.bg_img.img = mlx_new_image(game->mlx, game->w + 64, game->h + 64);
	ft_load_sprites(game);
	ft_render_image(game);
	mlx_loop_hook (game->mlx, &ft_frames, game);
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.s = 0;
	game->keys.w = 0;
	mlx_hook(game->window, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->window, 3, 1L << 1, ft_key_release, game);
	mlx_hook(game->window, 17, 1L << 0, ft_exit, game);
	mlx_loop(game->mlx);
}
