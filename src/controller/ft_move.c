/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/15 11:30:50 by nfordoxc         ###   Luxembourg.lu     */
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
 * 	void	ft_move(t_info *info, double new_padx, double new_pady)
 * </summary>
 *
 * <description>
 * 	ft_move move the player on the map.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_padx">new pad x of the player</param>
 * <param type="double" name="new_pady">new pad y of the player</param>
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
	printf("adjustation:\nnew_x: %.2f\tnew_y: %.2f\n\t"BLUEC"MOVING\n"RESET, new_x, new_y);
	printf("***************************************************************\n");
	info->map[info->y][info->x] = '0';
	info->user_x = new_x;
	info->user_y = new_y;
	info->x = floor(new_x);
	info->y = floor(new_y);
	info->map[info->y][info->x] = 'P';
	return ;
}

double	ft_normalize_rot(double angle)
{
	while (angle > M_PI)
		angle -= 2 * M_PI;
	while (angle < -M_PI)
		angle += 2 * M_PI;
	return (angle);
}
