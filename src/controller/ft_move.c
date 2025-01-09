/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/09 19:19:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

static int	ft_isforbidden_zone(t_info *info, int dirx, int diry)
{
	int	x;
	int	y;

	x = info->x;
	y = info->y;
	if (dirx > 0 && diry > 0)
		return info->map[y + 1][x] == '1' && info->map[y][x + 1] == '1';
	if (dirx > 0 && diry < 0)
		return info->map[y - 1][x] == '1' && info->map[y][x + 1] == '1';
	if (dirx < 0 && diry > 0)
		return info->map[y + 1][x] == '1' && info->map[y][x - 1] == '1';
	if (dirx < 0 && diry < 0)
		return info->map[y - 1][x] == '1' && info->map[y][x - 1] == '1';
	return (0);
}

static void	ft_check_x(t_info *info, int dirx, int diry, double *new_x)
{
	int	next_x;
	int	x;

	x = info->x;
	next_x = x + dirx;
	if (*new_x - x > D_WALL && *new_x - x < 1 - D_WALL)
		return ;
	if (dirx && info->map[info->y][next_x] == '1')
	{
		if (dirx < 0 && *new_x < floor(*new_x) + D_WALL)
			*new_x = floor(*new_x) + D_WALL;
		else if (dirx > 0 && *new_x > ceil(*new_x) - D_WALL)
			*new_x = ceil(*new_x) - D_WALL;
	}
	if (ft_isforbidden_zone(info, dirx, diry))
	{
		if (*new_x > info->user_x)
			*new_x = info->x + (1 - D_WALL);
		else if (*new_x < info->user_x )
			*new_x = info->x + D_WALL;
	}
}

static void	ft_check_y(t_info *info, int diry, int dirx, double *new_y)
{
	int	next_y;
	int	y;

	y = info->y;
	next_y = y + diry;
	if (*new_y - y > D_WALL && *new_y - y < 1 - D_WALL)
		return ;
	if (diry)
	{
		if (info->map[next_y][info->x] == '1')
		{
			if (diry < 0 && *new_y < floor(*new_y) + D_WALL)
				*new_y = floor(*new_y) + D_WALL;
			else if (diry > 0 && *new_y > ceil(*new_y) - D_WALL)
				*new_y = ceil(*new_y) - D_WALL;
		}
	}
	if (ft_isforbidden_zone(info, dirx, diry))
	{
		if (*new_y > info->user_y)
			*new_y = info->y + (1 - D_WALL);
		else if (*new_y < info->user_y)
			*new_y = info->y + D_WALL;
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
static void	ft_check_wall(t_info * info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	if (dirx && !diry)
		ft_check_x(info, dirx, diry, new_x);
	if (diry && !dirx)
		ft_check_y(info, diry, dirx, new_y);
	if (dirx && diry)
	{
		if (info->map[info->x + dirx][info->y + diry] == '1')
		{
			ft_check_x(info, dirx, diry, new_x);
			ft_check_y(info, diry, dirx, new_y);
		}
		else
		{
			ft_check_x(info, dirx, diry, new_x);
			ft_check_y(info, diry, dirx, new_y);
		}
	}
}

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
	printf("******************************\n");
	printf("new_x: %.2f\tnew_y: %.2f\n", new_x, new_y);
	printf("******************************\n");
	ft_check_wall(info, &new_x, &new_y);
	printf("new_x: %.2f\tnew_y: %.2f\n", new_x, new_y);
	printf("******************************\n");
	info->map[info->y][info->x] = '0';
	info->user_x = new_x;
	info->user_y = new_y;
	info->x = floor(new_x);
	info->y = floor(new_y);
	info->map[info->y][info->x] = 'P';
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_mouse_move(int x, int y, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_mouse_move change the direction of the player.
 * </description>
 *
 * <param type="int" name="x">position of the mouse</param>
 * <param type="int" name="y">position of the mouse</param>
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	0.
 * </return>
 *
 */
int	ft_mouse_move(int x, int y, t_info *info)
{
	//double	new_padx;
	//double	new_pady;

	(void)y;
	if (x < info->mouse_x)
		info->user_deg -= ROTATE;
	else if (x > info->mouse_x)
		info->user_deg += ROTATE;
	info->user_deg = ft_normalize_rot(info->user_deg);
	info->mouse_x = x;
	info->mouse_y = y;
	ft_minimap(info);
	return (0);
}

double	ft_normalize_rot(double angle)
{
	while (angle > M_PI)
		angle -= 2 * M_PI;
	while (angle < -M_PI)
		angle += 2 * M_PI;
	return (angle);
}
