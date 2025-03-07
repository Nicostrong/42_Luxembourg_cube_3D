/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:55:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 18:01:55 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../includes/raycasting_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_mouse_move(int x, int y, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_mouse_move change the direction of the player.
 * </description>
 *
 * <param type="int" name="x">position of the mouse</param>
 * <param type="int" name="y">position of the mouse</param>
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	0.
 * </return>
 *
 */
int	ft_mouse_move(int x, int y, t_info *info)
{
	(void)y;
	info->mouse_diff++;
	if (info->mouse_diff > M_REFRESH)
	{
		if ((x < info->mouse_rot + 100) && x < info->mouse_lc)
			ft_rotate(info, -ROTATE);
		else if ((x > info->mouse_rot - 100) && x > info->mouse_lc)
			ft_rotate(info, +ROTATE);
		info->mouse_lc = x;
		info->move = 1;
		info->mouse_diff = 0;
	}
	return (0);
}
