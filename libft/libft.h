/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiseiki <vmiseiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:53:50 by vmiseiki          #+#    #+#             */
/*   Updated: 2021/12/05 19:07:46 by vmiseiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_strchr(char *str, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_max(int i, int j);
int		ft_min(int i, int j);
char	**ft_copy_2d_arr(char **str1, char **str2);
int		ft_2d_arr_len(char **arr);
void	ft_free_double_arr(char **arr);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
#endif