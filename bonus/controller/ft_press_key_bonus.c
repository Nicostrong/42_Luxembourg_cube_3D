/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 18:02:08 by nfordoxc         ###   Luxembourg.lu     */
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
		ft_rotate(info, -ROTATE);
	else if (keysym == XK_Right)
		ft_rotate(info, ROTATE);
	else if (keysym == XK_space)
		ft_open_door(info);
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_Down || \
		keysym == XK_s || keysym == XK_a || keysym == XK_d || \
		keysym == XK_Left || keysym == XK_Right || keysym == XK_space)
		info->move = 1;
	return (0);
}
