/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enm_mov_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:57:16 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/10 17:00:33 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_enm_mov_cases(t_game *game, t_enemy	*enemies)
{
	if (enemies->enm_dir == 1 && ft_collision_detection(game,
			enemies->pos.y, enemies->pos.x - 4, 0) == 1)
		enemies->pos.x = enemies->pos.x - 4;
	if (enemies->enm_dir == 2 && ft_collision_detection(game,
			enemies->pos.y, enemies->pos.x + 4, 0) == 1)
		enemies->pos.x = enemies->pos.x + 4;
	if (enemies->enm_dir == 3 && ft_collision_detection(game,
			enemies->pos.y - 4, enemies->pos.x, 0) == 1)
		enemies->pos.y = enemies->pos.y - 4;
	if (enemies->enm_dir == 0 && ft_collision_detection(game,
			enemies->pos.y + 4, enemies->pos.x, 0) == 1)
		enemies->pos.y = enemies->pos.y + 4;
}
