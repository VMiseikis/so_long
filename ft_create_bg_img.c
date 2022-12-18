/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bg_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:38:49 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/06 15:22:02 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_place_bg_tiles(t_game *game)
{
	ft_generate_hitbox(game, game->pos.y,
		game->pos.x, game->map.map_grid[game->pos.y][game->pos.x]);
	if (game->map.map_grid[game->pos.y][game->pos.x] == '1')
		ft_sprite_to_img(game, &game->sp.wall, 0);
	else if (game->map.map_grid[game->pos.y][game->pos.x] == 'C')
		ft_sprite_to_img(game, &game->coll.coll_img, game->coll.coll_fr);
	else if (game->map.map_grid[game->pos.y][game->pos.x] == 'E')
	{
		if (game->map.points < 1)
			ft_sprite_to_img(game, &game->ex_on.on_img, game->ex_on.ex_fr);
		else
			ft_sprite_to_img(game, &game->sp.exit_off, 0);
	}
}

void	ft_create_bg_img(t_game *game)
{
	game->pos.y = game->bg.p1.y;
	while (game->pos.y < game->bg.p2.y && game->pos.y < game->map.r_c)
	{
		game->pos.x = game->bg.p1.x;
		while (game->pos.x < game->bg.p2.x && game->pos.x < game->map.c_c)
		{
			ft_sprite_to_img(game, &game->sp.bg_t, 0);
			if (ft_strchr("1CE", game->map.map_grid[game->pos.y][game->pos.x]))
				ft_place_bg_tiles(game);
			game->pos.x++;
		}
		game->pos.y++;
	}
}
