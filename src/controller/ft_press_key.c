/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/08 11:48:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

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
	if (info->user_deg > 2 * M_PI)
		info->user_deg -= 2 * M_PI;
	else if (info->user_deg < 0)
		info->user_deg += 2 * M_PI;
	/*if (DEBUG)
	{
		ft_print_user_data(info);
		ft_print_map(info);
	}*/
	ft_minimap(info);
	//ft_raycasting(info);
	return (0);
}