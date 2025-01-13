/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:57:24 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/13 13:04:53 by nfordoxc         ###   Luxembourg.lu     */
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
static int	ft_isforbidden_zone(t_info *info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	if (dirx > 0 && diry > 0)
		return (info->map[info->y + 1][info->x] == '0' && \
			info->map[info->y][info->x + 1] == '0' && \
			info->map[info->y + 1][info->x + 1] == '1');
	if (dirx > 0 && diry < 0)
		return (info->map[info->y - 1][info->x] == '0' && \
			info->map[info->y][info->x + 1] == '0' && \
			info->map[info->y - 1][info->x + 1] == '1');
	if (dirx < 0 && diry > 0)
		return (info->map[info->y + 1][info->x] == '0' && \
			info->map[info->y][info->x - 1] == '0' && \
			info->map[info->y + 1][info->x - 1] == '1');
	if (dirx < 0 && diry < 0)
		return (info->map[info->y - 1][info->x] == '0' && \
			info->map[info->y][info->x - 1] == '0' && \
			info->map[info->y - 1][info->x - 1] == '1');
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
	int		x;
	int		y;

	x = info->x;
	y = info->y;
	printf("\t\t\tAXE X\n");
	if (info->map[y][x + dirx] == '1')
	{
		printf("\t\t\tDIRECT WALL X we limits.\n");
		if (dirx < 0 && *new_x - x < D_WALL)
			*new_x = floor(*new_x) + D_WALL;
		else if (dirx > 0 && *new_x - x > 1 - D_WALL)
			*new_x = ceil(*new_x) - D_WALL;
	}
	else if (ft_isforbidden_zone(info, new_x, new_y))
	{
		printf("\t\t\tFORBIDDEN ZONE X we limit.\n");
		if (dirx < 0 && *new_x - x < D_WALL && \
			(*new_y - y < D_WALL || *new_y - y > 1 - D_WALL))
			*new_x = x + D_WALL;
		else if (dirx > 0 && *new_x - x > 1 - D_WALL && \
			(*new_y - y < D_WALL || *new_y - y > 1 - D_WALL))
			*new_x = x + 1 - D_WALL;
	}
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
	int		x;
	int		y;

	x = info->x;
	y = info->y;
	printf("\t\t\tAXE Y\n");
	if (info->map[y + diry][x] == '1')
	{
		printf("\t\t\tWALL DIRECT in Y we limit.\n");
		if (diry < 0 && *new_y < floor(*new_y) + D_WALL)
			*new_y = floor(*new_y) + D_WALL;
		else if (diry > 0 && *new_y > ceil(*new_y) - D_WALL)
			*new_y = ceil(*new_y) - D_WALL;
	}
	else if (ft_isforbidden_zone(info, new_x, new_y))
	{
		printf("\t\t\tFORBIDDEN ZONE Y we limit.\n");
		if (diry < 0 && *new_y - y < D_WALL && \
			(*new_x - x < D_WALL || *new_x - x > 1 - D_WALL))
			*new_y = y + D_WALL;
		else if (diry > 0 && *new_y - y > 1 - D_WALL && \
			(*new_x - x < D_WALL || *new_x - x > 1 - D_WALL))
			*new_y = y + 1 - D_WALL;
	}
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_limit_pos(t_info * info, double *new_x, double *new_y)
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
void	ft_check_wall(t_info * info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	printf("\t\tCHECK WALLL\t\tBEFORE\n");
	printf("\t\t\tdirx: %d\tdiry: %d\n\t\t\n", dirx, diry);
	printf("\t\t\tnew_x: %.2f\tnew_y: %.2f\n\t\tAFTER\n", *new_x, *new_y);
	if (dirx != 0 && !diry)
		ft_check_x(info, dirx, new_x, new_y);
	if (diry != 0 && !dirx)
		ft_check_y(info, diry, new_y, new_x);
	if (diry && dirx)
	{
		ft_check_x(info, dirx, new_x, new_y);
		ft_check_y(info, diry, new_y, new_x);
	}
	printf("\t\t\tnew_x: %.2f\tnew_y: %.2f\n", *new_x, *new_y);
}
