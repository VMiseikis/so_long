/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ignore_black_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:05:11 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/05 16:36:34 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_ignore_black_color(t_img *tile, int i, int j)
{
	char	*pixel;

	pixel = tile->addr + (j * tile->l_len
			+ i * (tile->b_per_px / 8));
	if (*(unsigned int *)pixel != 0x00000001)
		return (1);
	return (0);
}
