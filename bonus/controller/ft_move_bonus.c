/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/25 13:51:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/minimap_bonus.h"

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

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	double	ft_normalize_rot(double angle)
 * </summary>
 *
 * <description>
 * 	ft_normalize_rot put the rotation radian on the range [0;PI] or [0;-PI].
 * </description>
 *
 * <param type="double" name="angle">angle to adjuste</param>
 *
 * <return>
 * 	the new value of the angle adjusted or not.
 * </return>
 *
 */
double	ft_normalize_rot(double angle)
{
	while (angle > M_PI)
		angle -= 2 * M_PI;
	while (angle < -M_PI)
		angle += 2 * M_PI;
	return (angle);
}
