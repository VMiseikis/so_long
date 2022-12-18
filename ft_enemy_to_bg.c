/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_to_bg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:04:06 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/10 18:22:03 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_enm_pixel_to_bg(t_game *game, t_img *tile, int x, int y)
{
	char	*dest;
	char	*input;

	dest = game->bg.bg_img.addr
		+ ((y + (game->tmp_enm.pos.y - (game->bg.p1.y * game->sp.sp_h)))
			* game->bg.bg_img.l_len
			+ (x + (game->tmp_enm.pos.x - (game->bg.p1.x * game->sp.sp_w)))
			* (game->bg.bg_img.b_per_px / 8));
	input = tile->addr + ((y + game->tmp_enm.enm_dir * 32) * tile->l_len
			+ (x + game->tmp_enm.enm_frame * 32) * (tile->b_per_px / 8));
	*(unsigned int *)dest = *(unsigned int *)input;
}

void	ft_draw_enemy_to_bg(t_game *game, t_img *tile)
{
	int		i;
	int		j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			if (ft_ignore_black_color(tile,
					(i + game->tmp_enm.enm_frame * 32),
					(j + game->tmp_enm.enm_dir * 32)))
				ft_enm_pixel_to_bg(game, tile, i, j);
			j++;
		}
		i++;
	}
}

void	ft_draw_enemies(t_game *game)
{
	t_enemy	*enemy;

	enemy = game->enm;
	while (enemy != NULL)
	{
		if ((enemy->pos.x + 32) >= (game->bg.p1.x * 32)
			&& (enemy->pos.y + 32) >= (game->bg.p1.y * 32)
			&& (enemy->pos.x + 32) <= (game->bg.p2.x * 32)
			&& (enemy->pos.y + 32) <= (game->bg.p2.y * 32))
		{
			game->tmp_enm = *enemy;
			ft_draw_enemy_to_bg(game, &game->sp.enm);
		}
		enemy = enemy -> next;
	}
}
