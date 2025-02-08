/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:01:52 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/08 13:57:31 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_x(t_info *info, int dirx, double *new_x)
 * </summary>
 *
 * <description>
 * 	ft_check_x check if the player go to a wall or a forbidden zone in axis x.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="dirx">direction of the player in x</param>
 * <param type="double" name="new_x">new position x of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_x(t_info *info, int dirx, double *new_x)
{
	(void)dirx;
	if (info->map[info->y][info->x] == 'F')
	{
		printf(REDC"\tDOOR in X detected\n"RESET);
		if (dirx < 0 && \
			*new_x < (info->x + 1 - D_DOOR) && \
			info->user_x >= (info->x + 1 - D_DOOR))
		{
			printf(REDC"\tDOOR in left detected\n"RESET);
			*new_x = ceil(*new_x) - D_DOOR;
		}
		else if (dirx > 0 && \
			*new_x > (info->x + D_DOOR) && \
			info->user_x <= (info->x + D_DOOR))
		{
			printf(REDC"\tDOOR in right detected\n"RESET);
			*new_x = floor(*new_x) + D_DOOR;
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_y(t_info *info, int diry, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_check_y check if the player go to a wall or a forbidden zone in axis y.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="diry">direction of the player in y</param>
 * <param type="double" name="new_y">new position y of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_y(t_info *info, int diry, double *new_y)
{
	if (info->map[info->y][info->x] == 'F')
	{
		printf(REDC"\tDOOR in Y detected\n"RESET);
		if (diry < 0 && \
			*new_y < (info->y + 1 - D_DOOR) && \
			info->user_y >= (info->y + 1 - D_DOOR))
		{
			printf(REDC"\tDOOR in up detected\n"RESET);
			*new_y = ceil(*new_y) - D_DOOR;
		}
		else if (diry > 0 && \
			*new_y > (info->y + D_DOOR) && \
			info->user_y <= (info->y + D_DOOR))
		{
			printf(REDC"\tDOOR in down detected\n"RESET);
			*new_y = floor(*new_y) + D_DOOR;
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_wall(t_info *info, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_check_wall check if the player go to a wall or a forbidden zone.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_padx">new padx of the player</param>
 * <param type="double" name="new_pady">new pady of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_check_door(t_info *info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	if (diry && dirx)
	{
		ft_check_x(info, dirx, new_x);
		ft_check_y(info, diry, new_y);
	}
	else if (dirx != 0 && !diry)
		ft_check_x(info, dirx, new_x);
	else if (diry != 0 && !dirx)
		ft_check_y(info, diry, new_y);
	return ;
}
