/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:41:45 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/10 16:51:12 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_esc_key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit(game);
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (game->state == 0)
	{
		if (keycode == 1)
		{
			game->keys.s = 1;
			game->pl.pl_dir = 0;
		}
		if (keycode == 13)
		{
			game->keys.w = 1;
			game->pl.pl_dir = 3;
		}
		if (keycode == 0)
		{
			game->keys.a = 1;
			game->pl.pl_dir = 1;
		}
		if (keycode == 2)
		{
			game->keys.d = 1;
			game->pl.pl_dir = 2;
		}
	}
	ft_esc_key_press(keycode, game);
	return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == 0)
		game->keys.a = 0;
	if (keycode == 2)
		game->keys.d = 0;
	if (keycode == 1)
		game->keys.s = 0;
	if (keycode == 13)
		game->keys.w = 0;
	return (0);
}

void	ft_update(t_game *game, int x, int y, int dir)
{
	game->pl.p.x = x;
	game->pl.p.y = y;
	game->pl.pl_dir = dir;
	game->step_count++;
	ft_player_move_anim(game);
	printf("Player steps count: %d \n", game->step_count);
}

void	ft_key_action(t_game *game)
{
	int	step;

	step = 4;
	if (game->keys.a == 1)
		if (ft_collision_detection(game, game->pl.p.y, game->pl.p.x - step, 1)
			&& ft_enemy_collision(game, game->pl.p.y, game->pl.p.x - step))
			ft_update(game, game->pl.p.x - step, game->pl.p.y, 1);
	if (game->keys.d == 1)
		if (ft_collision_detection(game, game->pl.p.y, game->pl.p.x + step, 1)
			&& ft_enemy_collision(game, game->pl.p.y, game->pl.p.x + step))
			ft_update(game, game->pl.p.x + step, game->pl.p.y, 2);
	if (game->keys.s == 1)
		if (ft_collision_detection(game, game->pl.p.y + step, game->pl.p.x, 1)
			&& ft_enemy_collision(game, game->pl.p.y + step, game->pl.p.x))
			ft_update(game, game->pl.p.x, game->pl.p.y + step, 0);
	if (game->keys.w == 1)
		if (ft_collision_detection(game, game->pl.p.y - step, game->pl.p.x, 1)
			&& ft_enemy_collision(game, game->pl.p.y - step, game->pl.p.x))
			ft_update(game, game->pl.p.x, game->pl.p.y - step, 3);
}
