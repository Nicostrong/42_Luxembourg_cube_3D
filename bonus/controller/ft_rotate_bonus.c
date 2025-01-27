/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:36:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"

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
static double	ft_normalize_rot(double angle)
{
	if (angle > M_PI || angle < -M_PI)
	{
		while (angle > M_PI)
			angle -= 2 * M_PI;
		while (angle < -M_PI)
			angle += 2 * M_PI;
		printf(REDC"\t\tnormalize angle\n"RESET);
	}
	return (angle);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_rotate(t_info *info, double angle_rotation)
 * </summary>
 *
 * <description>
 * 	ft_rotate modify the angle of the player.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="angle_rotation">angle of rotation</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_rotate(t_info *info, double angle_rotation)
{
	printf("***************************************************************\n");
	printf(BYELLOW"\t\t\tROTATE of player\n"RESET);
	printf("***************************************************************\n");
	printf("current angle user:\t%.2f\n", info->user_deg);
	info->user_deg += angle_rotation;
	info->user_deg = ft_normalize_rot(info->user_deg);
	printf("new angle user:\t\t%.2f\n", info->user_deg);
	printf(BBLUE"\t\t\tROTATE\n"RESET);
	printf("***************************************************************\n");
	return ;
}
