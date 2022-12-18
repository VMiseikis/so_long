/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:16:07 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/05 21:24:01 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_player_offset(t_game *game)
{
	game->pl.off.x = 0;
	game->pl.off.y = 0;
	if (game->pl.p.x > (game->w / 2) && game->w < (game->map.c_c * 32))
	{
		if (((game->map.c_c * game->sp.sp_w) - game->pl.p.x) < (game->w / 2))
			game->pl.off.x = game->w - (game->map.c_c * game->sp.sp_w);
		else
			game->pl.off.x = (game->w / 2) - game->pl.p.x;
	}
	else if (game->w > (game->map.c_c * 32))
		game->pl.off.x = (game->w - (game->map.c_c * 32)) / 2;
	if (game->pl.p.y > (game->h / 2) && game->h < (game->map.r_c * 32))
	{
		if (((game->map.r_c * game->sp.sp_h) - game->pl.p.y) < (game->h / 2))
			game->pl.off.y = game->h - (game->map.r_c * game->sp.sp_h);
		else
			game->pl.off.y = (game->h / 2) - game->pl.p.y;
	}
	else if (game->h > (game->map.r_c * 32))
		game->pl.off.y = (game->h - (game->map.r_c * 32)) / 2;
}

void	ft_background_offset(t_game *game)
{
	game->bg.p1.x = 0;
	game->bg.p1.y = 0;
	if (game->pl.off.x > 0)
		game->bg.p2.x = (game->w / game->sp.sp_w) + 1;
	else
	{
		game->bg.p1.x = game->pl.off.x / game->sp.sp_w * -1;
		game->bg.p2.x = game->bg.p1.x + (game->w / game->sp.sp_w) + 2;
	}
	if (game->pl.off.y > 0)
		game->bg.p2.y = (game->h / game->sp.sp_h) + 1;
	else
	{
		game->bg.p1.y = game->pl.off.y / game->sp.sp_h * -1;
		game->bg.p2.y = game->bg.p1.y + (game->h / game->sp.sp_h) + 2;
	}
}
