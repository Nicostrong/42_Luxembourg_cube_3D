/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:28:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/19 17:58:01 by nfordoxc         ###   Luxembourg.lu     */
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
	if (keysym == 53)
		ft_exit(info);
	else if (keysym == 6 || keysym == 126)
		ft_up(info);
	else if (keysym == 1 || keysym == 125)
		ft_down(info);
	else if (keysym == 12 || keysym == 123)
		ft_left(info);
	else if (keysym == 2 || keysym == 124)
		ft_right(info);
	else if (keysym == 0)
		info->user_deg -= 5;
	else if (keysym == 14)
		info->user_deg += 5;
	else if (keysym == 49)
		printf("jump\n");
	if (info->user_deg < 0)
		info->user_deg += 360;
	else if (info->user_deg >= 360)
		info->user_deg -= 360;
	//ft_print_user_data(info);
	//ft_print_map(info);
	//ft_render(info);
	if ((keysym >= 0 && keysym <= 14) || (keysym >= 123 && keysym <= 126))
		ft_minimap(info);
	return (0);
}