/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_to_bg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:04:06 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/05 16:36:32 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_pl_pixel_to_bg(t_game *game, t_img *tile, int x, int y)
{
	char	*dest;
	char	*input;

	dest = game->bg.bg_img.addr
		+ ((y + (game->pl.p.y - (game->bg.p1.y * game->sp.sp_h)))
			* game->bg.bg_img.l_len
			+ (x + (game->pl.p.x - (game->bg.p1.x * game->sp.sp_w)))
			* (game->bg.bg_img.b_per_px / 8));
	input = tile->addr + ((y + game->pl.pl_dir * 32) * tile->l_len
			+ (x + game->pl.pl_frame * 32) * (tile->b_per_px / 8));
	*(unsigned int *)dest = *(unsigned int *)input;
}

void	ft_draw_player_to_bg(t_game *game, t_img *tile)
{
	int		i;
	int		j;

	i = 0;
	while ((i + game->pl.pl_frame * 32) < (game->pl.pl_frame * 32 + 32))
	{
		j = 0;
		while ((j + game->pl.pl_dir * 32) < (game->pl.pl_dir * 32 + 32))
		{
			if (ft_ignore_black_color(tile,
					(i + game->pl.pl_frame * 32), (j + game->pl.pl_dir * 32)))
				ft_pl_pixel_to_bg(game, tile, i, j);
			j++;
		}
		i++;
	}
}
