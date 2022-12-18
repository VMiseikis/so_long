/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:15:08 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/03 14:28:14 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_copy_2d_arr(char **str1, char **str2)
{
	int	i;

	i = 0;
	while (str1[i] != NULL)
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = NULL;
	return (str2);
}
