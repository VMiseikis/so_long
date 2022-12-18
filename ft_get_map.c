/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:22:32 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/07 20:56:20 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

char	*ft_str_join_c(char const *str, char const c)
{
	int		i;
	char	*res;

	i = 0;
	if (str == NULL)
		res = (char *)malloc(2 * sizeof(char));
	else
		res = (char *) malloc ((ft_strlen(str) + 2) * sizeof(char));
	if (!res)
		return (NULL);
	if (str == NULL)
		res[i] = c;
	else
	{
		while (str[i] != '\0')
		{
			res[i] = str[i];
			i++;
		}
		res[i] = c;
	}
	res[i + 1] = '\0';
	free((char *)str);
	return (res);
}

int	ft_get_line(int fd, char **line)
{
	char	buffer;
	int		size;

	size = 0;
	*line = NULL;
	buffer = '\0';
	if (fd < 0 || read(fd, &buffer, 0) < 0)
		return (0);
	size = read(fd, &buffer, 1);
	if (!buffer || buffer == '\n')
		return (0);
	*line = ft_str_join_c(*line, buffer);
	while (buffer != '\n' && size == 1)
	{
		size = read(fd, &buffer, 1);
		if (!buffer)
			return (0);
		if (buffer != '\n' && size == 1)
			*line = ft_str_join_c(*line, buffer);
	}
	return (1);
}

int	ft_get_map_grid(int fd, t_map *map, char **line)
{
	char	**tmp;

	map->r_c = 0;
	while (ft_get_line(fd, &*line))
	{
		if (map->r_c == 0)
			map->map_grid[0] = *line;
		else
		{
			tmp = malloc((ft_2d_arr_len(map->map_grid) + 1) * sizeof(char *));
			if (!tmp)
				return (printf("Error\nMap could not be read!\n"));
			ft_copy_2d_arr(map->map_grid, tmp);
			free(map->map_grid);
			map->map_grid = malloc((map->r_c + 2) * sizeof(char *));
			if (!map->map_grid)
				return (printf("Error\nMap could not be read!\n"));
			ft_copy_2d_arr(tmp, map->map_grid);
			free(tmp);
			map->map_grid[map->r_c] = *line;
		}
		map->r_c++;
		map->map_grid[map->r_c] = NULL;
	}
	return (1);
}

int	ft_get_map(int fd, t_game *game)
{
	char	*line;

	game->map.map_grid = (char **) malloc (2 * sizeof(char *));
	if (!game->map.map_grid)
		return (0);
	if (ft_get_map_grid(fd, &game->map, &line) != 1
		|| ft_check_if_rectangle(game) != 1
		|| ft_check_map_elem(game) != 1)
	{
		close(fd);
		ft_free_double_arr(game->map.map_grid);
		ft_free_enemy_lst(&game->enm);
		printf("Program was terminated!\n");
		exit(0);
	}
	close(fd);
	return (1);
}
