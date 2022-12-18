/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_to_bg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:49:55 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/07 22:25:40 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_sprite_px_to_bg(t_game *game, t_img *tile, int x, int y)
{
	char	*dest;
	char	*input;

	dest = game->bg.bg_img.addr
		+ ((y + (game->pos.y - game->bg.p1.y) * game->sp.sp_h)
			* game->bg.bg_img.l_len
			+ (x + (game->pos.x - game->bg.p1.x) * game->sp.sp_w)
			* (game->bg.bg_img.b_per_px / 8));
	input = tile->addr + (y * tile->l_len
			+ (x + game->temp) * (tile->b_per_px / 8));
	*(unsigned int *)dest = *(unsigned int *)input;
}

void	ft_sprite_to_img(t_game *game, t_img *tile, int x)
{
	int		i;
	int		j;

	i = 0;
	game->temp = x * 32;
	while ((i + game->temp) < (game->temp + 32))
	{
		j = 0;
		while (j < game->sp.sp_h)
		{
			if (ft_ignore_black_color(tile, (i + game->temp), j))
				ft_sprite_px_to_bg(game, tile, i, j);
			j++;
		}
		i++;
	}
}
