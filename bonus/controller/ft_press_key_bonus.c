/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 08:14:16 by nfordoxc         ###   Luxembourg.lu     */
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
	//info->user_deg = ft_normalize_rot(info->user_deg);
	info->move = 1;
	if (keysym == XK_space)
		ft_open_door(info);
	ft_minimap(info);
	ft_raycasting(info);
	return (0);
}
