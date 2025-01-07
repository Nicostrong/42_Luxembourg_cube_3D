/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/07 16:42:30 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

int	ft_press_key(int keysym, t_info *info)
{
	double	new_padx;
	double	new_pady;

	if (keysym == XK_Escape)
		ft_exit(info);
	else if (keysym == XK_Up || keysym == XK_w)
	{
		new_padx = info->user_x + (STEP * cos(info->user_deg));
		new_pady = info->user_y + (STEP * sin(info->user_deg));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		new_padx = info->user_x - (STEP * cos(info->user_deg));
		new_pady = info->user_y - (STEP * sin(info->user_deg));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == XK_Left || keysym == XK_a)
	{
		new_padx = info->user_x + (STEP * cos(info->user_deg - M_PI_2));
		new_pady = info->user_y + (STEP * sin(info->user_deg - M_PI_2));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == XK_Right || keysym == XK_d)
	{
		new_padx = info->user_x + (STEP * cos(info->user_deg + M_PI_2));
		new_pady = info->user_y + (STEP * sin(info->user_deg + M_PI_2));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == XK_q)
		info->user_deg -= ROTATE;
	else if (keysym == XK_e)
		info->user_deg += ROTATE;
	if (info->user_deg > 2 * M_PI)
		info->user_deg -= 2 * M_PI;
	else if (info->user_deg < 0)
		info->user_deg += 2 * M_PI;
	ft_print_user_data(info);
	//ft_print_map(info);
	ft_minimap(info);
	ft_raycasting(info);
	return (0);
}