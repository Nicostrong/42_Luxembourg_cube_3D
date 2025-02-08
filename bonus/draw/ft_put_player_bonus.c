/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:22 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/08 14:37:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_put_player(t_info *info, t_img *player, int x, int y)
 * </summary>
 *
 * <description>
 * 	ft_put_player is a function that draws a player in the minimap. If no image 
 * 	of player it draw a circle.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_img *" name="player">player image</param>
 * <param type="int" name="x">coordinate in x</param>
 * <param type="int" name="y">coordinate in y</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_put_player(t_info *info, t_img *player, int x, int y)
{
	if (player && player->addr)
	{
		ft_put_imgalpha(info->mini, info->player, x - (info->player->w / 2), \
			y - (info->player->h / 2));
		mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, \
			0, 0);
	}
	else
		ft_put_circle(info, x, y);
	return ;
}
