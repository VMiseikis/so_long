/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:11:33 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/07 20:29:43 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_exec_input_check(int argc, char **argv, int *fd)
{
	if (argc == 2)
	{
		*fd = open(argv[1], O_RDONLY);
		if (*fd >= 0)
			return (*fd);
	}
	printf("Error\nError occurred while opening map file!\n");
	printf("Program was terminated!\n");
	exit(0);
}

void	ft_free_enemy_lst(t_enemy **lst)
{
	t_enemy	*temp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			temp = *lst;
			*lst = (*lst)->next;
			free(temp);
		}
	}	
}

int	ft_exit(t_game *game)
{
	ft_free_hitbox_list(&game->hbox);
	ft_free_double_arr(game->map.map_grid);
	ft_free_enemy_lst(&game->enm);
	mlx_destroy_image(game->mlx, game->bg.bg_img.img);
	mlx_destroy_window(game->mlx, game->window);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	fd = -1;
	if (ft_exec_input_check(argc, argv, &fd) > -1)
	{
		game.state = 0;
		game.frame_limit = 0;
		game.sp.sp_w = 32;
		game.sp.sp_h = 32;
		game.step_size = 8;
		game.step_count = 0;
		game.pl.pl_dir = 2;
		game.pl.pl_frame = 0;
		game.coll.coll_fr = 0;
		game.ex_on.ex_fr = 0;
		game.enm = NULL;
		game.hbox = NULL;
		ft_get_map(fd, &game);
		ft_render(&game);
	}
	exit(1);
}
