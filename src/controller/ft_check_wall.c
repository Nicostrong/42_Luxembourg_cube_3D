/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:57:24 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/23 15:56:14 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_isforbidden_zone(t_info *info, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_isforbidden_zone check if the player go to a forbidden zone.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_x">new position x of the player</param>
 * <param type="double" name="new_y">new position y of the player</param>
 *
 * <return>
 * 	1 if in forbidden zone or 0 if not.
 * </return>
 *
 */
static int	ft_isforbidden_zone(t_info *info, double new_x, double new_y)
{
	int		x;
	int		y;

	x = info->x;
	y = info->y;
	if (info->map[y - 1][x - 1] == '1' && \
		(info->map[y][x - 1] == '0' && info->map[y - 1][x] == '0') && \
		new_x - x < D_WALL && new_y - y < D_WALL)
		return (1);
	else if (info->map[y - 1][x + 1] == '1' && \
		(info->map[y - 1][x] == '0' && info->map[y][x + 1] == '0') && \
		new_x - x > 1 - D_WALL && new_y - y < D_WALL)
		return (1);
	else if (info->map[y + 1][x + 1] == '1' && \
		(info->map[y][x + 1] == '0' && info->map[y + 1][x] == '0') && \
		new_x - x > 1 - D_WALL && new_y - y > 1 - D_WALL)
		return (1);
	else if (info->map[y + 1][x - 1] == '1' && \
		(info->map[y][x - 1] == '0' && info->map[y + 1][x] == '0') && \
		new_x - x < D_WALL && new_y - y > 1 - D_WALL)
		return (1);
	return (0);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_x(t_info *info, int dirx, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_check_x check if the player go to a wall or a forbidden zone in axis x.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="dirx">direction of the player in x</param>
 * <param type="double" name="new_x">new position x of the player</param>
 * <param type="double" name="new_y">new position y of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_x(t_info *info, int dirx, double *new_x, double *new_y)
{
	if (info->map[info->y][info->x + dirx] == '1')
	{
		printf(REDC"\tWALL in X + dirx\n"RESET);
		if (dirx < 0 && *new_x - info->x < D_WALL)
			*new_x = floor(*new_x) + D_WALL;
		else if (dirx > 0 && *new_x - info->x > 1 - D_WALL)
			*new_x = ceil(*new_x) - D_WALL;
	}
	else if (ft_isforbidden_zone(info, *new_x, *new_y))
	{
		printf(REDC"\tFORBIDDEN ZONE X\n"RESET);
		if (info->user_x - info->x >= D_WALL && \
			info->user_x - info->x <= 1 - D_WALL)
		{
			printf(REDC"\told pos.X allowed\n"RESET);
			if (dirx < 0 && *new_x - info->x < D_WALL && \
			(*new_y - info->y < D_WALL || *new_y - info->y > 1 - D_WALL))
				*new_x = info->x + D_WALL;
			else if (dirx > 0 && *new_x - info->x > 1 - D_WALL && \
				(*new_y - info->y < D_WALL || *new_y - info->y > 1 - D_WALL))
				*new_x = info->x + 1 - D_WALL;
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_y(t_info *info, int diry, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_check_y check if the player go to a wall or a forbidden zone in axis y.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="diry">direction of the player in y</param>
 * <param type="double" name="new_x">new position x of the player</param>
 * <param type="double" name="new_y">new position y of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_y(t_info *info, int diry, double *new_y, double *new_x)
{
	if (info->map[info->y + diry][info->x] == '1')
	{
		printf(REDC"\tWALL in Y + diry\n"RESET);
		if (diry < 0 && *new_y < floor(*new_y) + D_WALL)
			*new_y = floor(*new_y) + D_WALL;
		else if (diry > 0 && *new_y > ceil(*new_y) - D_WALL)
			*new_y = ceil(*new_y) - D_WALL;
	}
	else if (ft_isforbidden_zone(info, *new_x, *new_y))
	{
		printf(REDC"\tFORBIDDEN ZONE Y\n"RESET);
		if (info->user_y - info->y >= D_WALL && \
			info->user_y - info->y <= 1 - D_WALL)
		{
			printf(REDC"\told pos.Y allowed\n"RESET);
			if (diry < 0 && *new_y - info->y < D_WALL && \
				(*new_x - info->x < D_WALL || *new_x - info->x > 1 - D_WALL))
				*new_y = info->y + D_WALL;
			else if (diry > 0 && *new_y - info->y > 1 - D_WALL && \
				(*new_x - info->x < D_WALL || *new_x - info->x > 1 - D_WALL))
				*new_y = info->y + 1 - D_WALL;
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_limit_pos(t_info *info, double *new_x, double *new_y)
 * </summary>
 *
 * <description>
 * 	ft_adjust_pads limite the value of pad near a wall.
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
void	ft_check_wall(t_info *info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	if (diry && dirx)
	{
		ft_check_x(info, dirx, new_x, new_y);
		ft_check_y(info, diry, new_y, new_x);
	}
	else if (dirx != 0 && !diry)
		ft_check_x(info, dirx, new_x, new_y);
	else if (diry != 0 && !dirx)
		ft_check_y(info, diry, new_y, new_x);
	return ;
}
