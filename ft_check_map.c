/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:09:25 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/07 20:58:58 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_check_if_rectangle(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map_grid[i] != NULL)
	{
		j = 0;
		while (game->map.map_grid[i][j] != '\0')
		{
			if (!ft_strchr("01CEP", game->map.map_grid[i][j]))
				return (printf("Error\nNot valid map symbols found!\n"));
			j++;
		}
		if (i == 0)
			game->map.c_c = j;
		else
			if (game->map.c_c != j)
				return (printf("Error\nMap is not rectangular!\n"));
		i++;
	}
	if (i < 3 || j < 3 || (i == 3 && j < 5) || (i < 5 && j == 3))
		return (printf("Error\nMap size is too small!\n"));
	game->map.r_c = i;
	return (1);
}

int	ft_count_map_elem(t_game *game, int *elem_count, int i, int j)
{
	if (game->map.map_grid[i][j] == 'E')
		elem_count[0]++;
	if (game->map.map_grid[i][j] == 'C')
		elem_count[1]++;
	if (game->map.map_grid[i][j] == 'P')
	{
		elem_count[2]++;
		game->pl.p.x = j * game->sp.sp_w;
		game->pl.p.y = i * game->sp.sp_h;
	}
	return (1);
}

int	ft_check_map_edge(t_game *game, int i, int j)
{
	if (((i == 0 || i == (game->map.r_c - 1))
			&& game->map.map_grid[i][j] != '1')
			|| ((j == 0 || j == (game->map.c_c - 1))
			&& game->map.map_grid[i][j] != '1'))
		return (0);
	return (1);
}

int	ft_check_map_elem(t_game *game)
{
	int	i;
	int	j;
	int	elem_count[3];

	elem_count[0] = 0;
	elem_count[1] = 0;
	elem_count[2] = 0;
	i = 0;
	while (game->map.map_grid[i] != NULL)
	{
		j = 0;
		while (game->map.map_grid[i][j] != '\0')
		{
			ft_count_map_elem(game, elem_count, i, j);
			if (!ft_check_map_edge(game, i, j))
				return (printf("Error\nMap is not closed/surrounded by wall!\n"));
			j++;
		}
		i++;
	}
	if (elem_count[0] < 1 || elem_count[1] < 1 || elem_count[2] != 1)
		return (printf("Error\nWrong map configuration!\n"));
	game->map.points = elem_count[1];
	return (1);
}
