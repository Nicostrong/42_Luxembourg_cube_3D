/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:28:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/27 14:50:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

/*
 *	liste des identifiants de touches Mac
 *
 * 	a			=	0	=>	rotate left
 * 	e			=	14	=>	rotate right
 * 	z			=	6	=>	up
 * 	q			=	12	=>	left
 * 	s			=	1	=>	down
 * 	d			=	2	=>	right
 * 	dir up		=	126
 * 	dir left	=	123
 * 	dir down	=	125
 * 	dir right	=	124
 * 	escape		=	53
 * 	space		=	49
 *
 */
int	ft_press_key_mac(int keysym, t_info *info)
{
	double	new_padx;
	double	new_pady;

	if (keysym == ESCAP)
		ft_exit(info);
	else if (keysym == KZ || keysym == UP)
	{
		new_padx = info->pad_x + (STEP * cos(info->user_deg));
		new_pady = info->pad_y + (STEP * sin(info->user_deg));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == KS || keysym == DOWN)
	{
		new_padx = info->pad_x - (STEP * cos(info->user_deg));
		new_pady = info->pad_y - (STEP * sin(info->user_deg));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == KQ || keysym == LEFT)
	{
		new_padx = info->pad_x + (STEP * cos(info->user_deg - M_PI_2));
		new_pady = info->pad_y + (STEP * sin(info->user_deg - M_PI_2));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == KD || keysym == RIGHT)
	{
		new_padx = info->pad_x + (STEP * cos(info->user_deg + M_PI_2));
		new_pady = info->pad_y + (STEP * sin(info->user_deg + M_PI_2));
		ft_move(info, new_padx, new_pady);
	}
	else if (keysym == KA)
		info->user_deg += ROTATE;
	else if (keysym == KE)
		info->user_deg -= ROTATE;
	if (info->user_deg > 2 * M_PI)
		info->user_deg -= 2 * M_PI;
	else if (info->user_deg < 0)
		info->user_deg += 2 * M_PI;
	//ft_print_user_data(info);
	//ft_print_map(info);
	if ((keysym >= 0 && keysym <= 14) || (keysym >= 123 && keysym <= 126))
		ft_minimap(info);
	return (0);
}