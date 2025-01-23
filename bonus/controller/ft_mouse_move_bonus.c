/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:55:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/23 09:13:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/setting_game.h"
#include "../../includes/minimap.h"

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
	if (x < info->mouse_rot)
		info->user_deg -= ROTATE;
	else if (x > info->mouse_rot)
		info->user_deg += ROTATE;
	info->mouse_rot = x;
	info->move = 1;
	ft_minimap(info);
	return (0);
}
