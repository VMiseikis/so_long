/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colisions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:17:18 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/10 17:04:47 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_rec_rec_collision(int i, int j, int x, int y)
{
	if (x < (i + 28) && x + 32 > i
		&& y < (j + 24) && y + 24 > j)
		return (1);
	return (0);
}

int	ft_pl_enm_collision(int i, int j, int x, int y)
{
	if (x < (i + 28) && x + 28 > i
		&& y < (j + 24) && y + 24 > j)
		return (1);
	return (0);
}
/*int ft_rec_circle_collision(int xc, int yc, int x, int y, int r)
{
	int Xn;
	int Yn;
	int Dx;
	int Dy;
	
	Xn = ft_max(x, ft_min(xc, x + 32));
	Yn = ft_max(y, ft_min(yc, y + 32));
    Dx = Xn - xc;
    Dy = Yn - yc;
	if((Dx * Dx + Dy * Dy) <= r * r)
		return(0);
	return(1);
}*/

int	ft_collision_cases(t_game *game, t_hitbox *hbox, int flag)
{
	if (hbox->type == '1')
		return (0);
	else if (hbox->type == 'E')
	{
		if (game->map.points < 1)
			game->state = 1;
		return (0);
	}
	else if (hbox->type == 'C')
	{
		if (flag == 1)
		{
			game->map.map_grid[hbox->p.x][hbox->p.y] = '0';
			game->map.points--;
			ft_render_image(game);
			return (1);
		}
		return (0);
	}
	return (1);
}

int	ft_collision_detection(t_game *game, int x, int y, int flag)
{
	t_hitbox	*hbox;

	hbox = game->hbox;
	while (hbox != NULL)
	{
		if (ft_rec_rec_collision(hbox->p.x * 32, hbox->p.y * 32, x, y))
			return (ft_collision_cases(game, hbox, flag));
		hbox = hbox->next;
	}
	return (1);
}

int	ft_enemy_collision(t_game *game, int x, int y)
{
	t_enemy	*enemies;

	enemies = game->enm;
	while (enemies != NULL)
	{
		if (ft_pl_enm_collision(enemies->pos.y, enemies->pos.x, x, y))
		{
			game->state = 2;
			return (0);
		}
		enemies = enemies->next;
	}
	return (1);
}
