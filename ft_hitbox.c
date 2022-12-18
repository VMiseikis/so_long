/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:19:05 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/07 20:00:40 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

t_hitbox	*ft_new_hitbox(int x, int y, char c)
{
	t_hitbox	*new;

	new = (t_hitbox *)malloc(sizeof(t_hitbox));
	if (!new)
		return (NULL);
	new->p.x = x;
	new->p.y = y;
	new->type = c;
	new->next = NULL;
	return (new);
}

void	ft_generate_hitbox(t_game *game, int x, int y, char c)
{
	t_hitbox	*new;

	if (game->hbox == NULL)
	{
		game->hbox = ft_new_hitbox(x, y, c);
	}
	else
	{
		new = game->hbox;
		game->hbox = ft_new_hitbox(x, y, c);
		game -> hbox->next = new;
	}
}

void	ft_free_hitbox_list(t_hitbox **lst)
{
	t_hitbox	*temp;

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
