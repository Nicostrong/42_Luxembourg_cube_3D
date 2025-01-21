/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/21 17:25:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"
#include "../../includes/minimap.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_press_key(int keysym, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_press_key manage the key pressed by the user on Linux.
 * </description>
 *
 * <param type="int" name="keysym">key pressed</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	exit code 0.
 * </return>
 *
 */
int	ft_press_key(int keysym, t_info *info)
{
	if (keysym == XK_Escape)
		ft_exit(info);
	else if (keysym == XK_Up || keysym == XK_w)
		ft_move(info, 0, 1);
	else if (keysym == XK_Down || keysym == XK_s)
		ft_move(info, 0, -1);
	else if (keysym == XK_a)
		ft_move(info, -M_PI_2, 1);
	else if (keysym == XK_d)
		ft_move(info, M_PI_2, 1);
	else if (keysym == XK_Left)
		info->user_deg -= ROTATE;
	else if (keysym == XK_Right)
		info->user_deg += ROTATE;
	info->user_deg = ft_normalize_rot(info->user_deg);
	if (BONUS)
	{
		if (keysym == XK_space)
			ft_open_door(info);
		ft_minimap(info);
	}
	ft_raycasting(info);
	return (0);
}
