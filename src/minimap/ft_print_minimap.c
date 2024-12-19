/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:06:16 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/19 09:07:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3d.h"
#include "../includes/structures.h"
#include "../includes/setting_game.h"

/*
 *	pour afficher la minimap
 *	il faut un array de la minimap
 *	on attribue une couleur a chaque case de la minimap
 *	on affiche la map
 *	on affiche le joueur
 */
void	ft_print_minimap(t_info *info)
{
	char	**map;

	map = ft_create_map(info);
	ft_putstrarray(map);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	if (info->player)
		mlx_put_image_to_window(info->mlx, info->mini->win, info->player->img, \
			(MINI_W / 2) - 21, (MINI_H / 2) - 21);
	else
		ft_put_circle(info, MINI_W / 2, MINI_H / 2);
}