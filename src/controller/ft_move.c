/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/10 14:07:45 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_move(t_info *info, double angle_offset, int dir)
 * </summary>
 *
 * <description>
 * 	ft_move move the player on the map. It check if the new position is 
 * 	available and limit the move in x or y or both if forbidden zone.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="angle_offset">delta new_angle</param>
 * <param type="int" name="dir">direction of move</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_move(t_info *info, double angle_offset, int dir)
{
	double	new_x;
	double	new_y;

	new_x = info->user_x + (dir * STEP * cos(info->user_deg + angle_offset));
	new_y = info->user_y + (dir * STEP * sin(info->user_deg + angle_offset));
	printf("***************************************************************\n");
	printf(BYELLOW"\t\t\tMOVE of player\n"RESET);
	printf("***************************************************************\n");
	printf("current_x:\t%.2f\tcurrent_y:\t%.2f\n", info->user_x, info->user_y);
	printf("new_x:\t\t%.2f\tnew_y:\t\t%.2f\n", new_x, new_y);
	printf("***************************************************************\n");
	ft_check_wall(info, &new_x, &new_y);
	printf("adjustation:\nnew_x: %.2f\tnew_y: %.2f\torientation: %.2f\n\t\t\t"\
		BBLUE"MOVING\n"RESET, new_x, new_y, info->user_deg);
	printf("***************************************************************\n");
	if (info->map[(int)floor(new_y)][(int)floor(new_x)] == '1')
		return ;
	info->map[info->y][info->x] = '0';
	info->user_x = new_x;
	info->user_y = new_y;
	info->x = floor(new_x);
	info->y = floor(new_y);
	info->map[info->y][info->x] = 'P';
	info->move = 1;
	return ;
}
