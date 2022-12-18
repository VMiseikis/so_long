/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_sett.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:08:05 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/10 18:21:47 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_enm_animation(t_game *game)
{
	t_enemy	*enemies;
	int		i;

	i = 0;
	if (game->frame_limit % 10 == 0)
	{
		enemies = game->enm;
		while (enemies != NULL)
		{
			enemies->enm_frame++;
			if (enemies->enm_frame > 3)
				enemies->enm_frame = 0;
			if (game->frame_limit % 120 == 0)
				enemies->enm_dir = ft_random_number(0, 3);
			if ((enemies->pos.x + 32) >= (game->bg.p1.x * 32)
				&& (enemies->pos.y + 32) >= (game->bg.p1.y * 32)
				&& (enemies->pos.x + 32) <= (game->bg.p2.x * 32)
				&& (enemies->pos.y + 32) <= (game->bg.p2.y * 32))
				ft_enm_mov_cases(game, enemies);
			if (ft_pl_enm_collision(enemies->pos.x, enemies->pos.y,
					game->pl.p.x, game->pl.p.y) == 1)
				game ->state = 2;
			enemies = enemies->next;
		}	
	}
}

void	ft_ex_on_animation(t_game *game)
{
	if (game->frame_limit % 30 == 0)
	{
		game->ex_on.ex_fr++;
		if (game->ex_on.ex_fr > 3)
			game->ex_on.ex_fr = 0;
	}
}

void	ft_collectible_animation(t_game *game)
{
	if (game->frame_limit % 4 == 0)
	{
		game->coll.coll_fr++;
		if (game->coll.coll_fr > 14)
			game->coll.coll_fr = 0;
	}
}

void	ft_player_move_anim(t_game *game)
{
	if (game->frame_limit % 20 == 0)
	{
		game->pl.pl_frame++;
		if (game->pl.pl_frame > 3)
			game->pl.pl_frame = 0;
	}
}

int	ft_frames(t_game *game)
{
	game->frame_limit++;
	if (game->frame_limit % 166 == 0)
	{
		ft_key_action(game);
		ft_collectible_animation(game);
		ft_ex_on_animation(game);
		ft_enm_animation(game);
		ft_render_image(game);
	}	
	if (game->frame_limit >= 10000)
		game->frame_limit = 0;
	return (1);
}
