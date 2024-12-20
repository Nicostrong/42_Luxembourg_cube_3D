/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/20 09:35:31 by nfordoxc         ###   Luxembourg.lu     */
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
		ft_up(info);
	else if (keysym == XK_Down || keysym == XK_s)
		ft_down(info);
	else if (keysym == XK_Left || keysym == XK_a)
		ft_left(info);
	else if (keysym == XK_Right || keysym == XK_d)
		ft_right(info);
	else if (keysym == XK_q)
		info->user_deg -= 5;
	else if (keysym == XK_e)
		info->user_deg += 5;
	else if (keysym == XK_space)
		printf("jump\n");
	if (info->user_deg < 0)
		info->user_deg += 360;
	else if (info->user_deg >= 360)
		info->user_deg -= 360;
	ft_print_user_data(info);
	//ft_print_map(info);
	//ft_render(info);
	ft_minimap(info);
	return (0);
}