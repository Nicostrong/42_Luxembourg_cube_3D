/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:28:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/08 11:48:11 by nfordoxc         ###   Luxembourg.lu     */
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
	if (keysym == ESCAP)
		ft_exit(info);
	else if (keysym == KZ || keysym == UP)
		ft_move(info, 0, 1);
	else if (keysym == KS || keysym == DOWN)
		ft_move(info, 0, -1);
	else if (keysym == KQ)
		ft_move(info, -M_PI_2, 1);
	else if (keysym == KD)
		ft_move(info, M_PI_2, 1);
	else if (keysym == KA || keysym == LEFT)
		info->user_deg += ROTATE;
	else if (keysym == KE || keysym == RIGHT)
		info->user_deg -= ROTATE;
	if (info->user_deg > 2 * M_PI)
		info->user_deg += 2 * M_PI;
	else if (info->user_deg < 0)
		info->user_deg -= 2 * M_PI;
	ft_print_user_data(info);
	//ft_print_map(info);
	if ((keysym >= 0 && keysym <= 14) || (keysym >= 123 && keysym <= 126))
		ft_minimap(info);
	//ft_raycasting(info);
	return (0);
}