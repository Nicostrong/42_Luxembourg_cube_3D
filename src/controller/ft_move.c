/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/06 11:54:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_adjust_pads(t_info * info, double *new_padx, double *new_pady, int dirx, int diry)
 * </summary>
 *
 * <description>
 * 	ft_adjust_pads limite the value of pad near a wall.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_padx">new padx of the player</param>
 * <param type="double" name="new_pady">new pady of the player</param>
 * <param type="int" name="dir_x">direction in x</param>
 * <param type="int" name="dir_y">direction in y</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_adjust_pads(t_info * info, double *new_padx, double *new_pady, int dirx, int diry)
{
	if (round(fabs(*new_padx)) > D_WALL && \
		info->map[info->user_y][info->user_x + dirx] == '1')
	{
		if (round(*new_padx) < -D_WALL)
			*new_padx = -D_WALL;
		else if (round(*new_padx) > D_WALL)
			*new_padx = D_WALL;
	}
	if (round(fabs(*new_pady)) > D_WALL && \
		info->map[info->user_y + diry][info->user_x] == '1')
	{
		if (round(*new_pady) < -D_WALL)
			*new_pady = -D_WALL;
		else if (round(*new_pady) > D_WALL)
			*new_pady = D_WALL;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_diag_move(t_info *info, double *new_padx, double *new_pady, int next_x, int next_y)
 * </summary>
 *
 * <description>
 * 	ft_diag_move make a diagonal move of the player on the map.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_padx">new padx of the player</param>
 * <param type="double" name="new_pady">new pady of the player</param>
 * <param type="int" name="next_x">next case index on the map in x</param>
 * <param type="int" name="next_y">next case index on the map in y</param>
 *
 * <return>
 * 	1 if diagonal movement or 0.
 * </return>
 *
 */
static int	ft_diag_move(t_info *info, double *new_padx, double *new_pady, int next_x, int next_y)
{
	if (round(fabs(*new_padx)) > 10 && round(fabs(*new_pady)) >= 10)
	{
		if (info->map[next_y][next_x] != '1')
		{
			info->map[info->user_y][info->user_x] = '0';
			info->user_x = next_x;
			info->user_y = next_y;
			info->map[info->user_y][info->user_x] = 'P';
			info->pad_x = *new_padx - 20.0;
			if (*new_padx < 0.0)
				info->pad_x = *new_padx + 20.0;
			info->pad_y = *new_pady - 20.0;
			if (*new_pady < 0.0)
				info->pad_y = *new_pady + 20.0;
			return (1);
		}
	}
	return (0);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_axis_move(t_info *info, double *new_pad, int next, int axis)
 * </summary>
 *
 * <description>
 * 	ft_axis_move change the position of the player on x or y. Make some check 
 * 	before to change the position of the player or limit the value of move if 
 * 	near a wall.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_pad">new pad of the player</param>
 * <param type="int" name="next">next case index on the map</param>
 * <param type="int" name="axis">boolean value for axis x or y</param>
 *
 * <return>
 * 	1 if axis movement or 0.
 * </return>
 *
 */
static int	ft_axis_move(t_info *info, double *new_pad, int next, int axis)
{
	if (round(fabs(*new_pad)) > 10 && !axis)
	{
		if (info->map[info->user_y][next] != '1')
		{
			info->map[info->user_y][info->user_x] = '0';
			info->user_x = next;
			info->map[info->user_y][info->user_x] = 'P';
			if (*new_pad > 0.0)
				info->pad_x = *new_pad - 20.0;
			else
				info->pad_x = *new_pad + 20.0;
			return (1);
		}
	}
	else if (round(fabs(*new_pad)) > 10 && axis)
	{
		if (info->map[next][info->user_x] != '1')
		{
			info->map[info->user_y][info->user_x] = '0';
			info->user_y = next;
			info->map[info->user_y][info->user_x] = 'P';
			if (*new_pad > 0.0)
				info->pad_y = *new_pad - 20.0;
			else
				info->pad_y = *new_pad + 20.0;
			return (1);
		}
	}
	return (0);
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
void	ft_move(t_info *info, double new_padx, double new_pady)
{
	int		next_x;
	int		next_y;
	int		dirx;
	int		diry;

	dirx = (round(new_padx) > 0) - (round(new_padx) < 0);
	diry = (round(new_pady) > 0) - (round(new_pady) < 0);
	next_x = info->user_x + dirx;
	next_y = info->user_y + diry;
	if (next_x < 0 || next_x >= info->w || next_y < 0 || next_y > info->h)
		return ;
	/*printf("Debug\tpadx: %.2f\tpady: %.2f\n", info->pad_x, info->pad_y);
	printf("\tnew_padx: %.2f\tnew_pady: %.2f\n", new_padx, new_pady);
	printf("\tdirx: %d\tdiry: %d\n", dirx, diry);
	if (dirx == 0.0)
		printf("\tdirection X : %s\n", "Axe X");
	else
		printf("\tdirection X : %s\n", dirx > 0 ? "droite" : "gauche");
	if (diry == 0.0)
		printf("\tdirection Y : %s\n", "Axe Y");
	else
		printf("\tdirection Y : %s\n", diry > 0 ? "bas" : "haut");
	printf("\tnow (X.Y) (%d.%d)\n", info->user_x, info->user_y);
	printf("\tnew (X.Y) (%d.%d)\n", next_x, next_y);
	printf("\n******************************\n");*/
	ft_adjust_pads(info, &new_padx, &new_pady, dirx, diry);
	if (ft_diag_move(info, &new_padx, &new_pady, next_x, next_y))
		return ;
	if (ft_axis_move(info, &new_padx, next_x, 0))
		return ;
	if (ft_axis_move(info, &new_pady, next_y, 1))
		return ;
	info->pad_x = new_padx;
	info->pad_y = new_pady;
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

	if (x < info->mouse_x)
		info->user_deg -= ROTATE;
	else if (x > info->mouse_x)
		info->user_deg += ROTATE;
	(void)y;
	/*if (y < info->mouse_y)
	{
		//new_padx = info->pad_x + (STEP * cos(info->user_deg));
		new_pady = info->pad_y + (STEP * sin(info->user_deg));
		ft_move(info, info->pad_x, new_pady);
	}
	else if (y > info->mouse_y)
	{
		//new_padx = info->pad_x - (STEP * cos(info->user_deg));
		new_pady = info->pad_y - (STEP * sin(info->user_deg));
		ft_move(info, info->pad_x, new_pady);
	}*/
	info->mouse_x = x;
	info->mouse_y = y;
	ft_minimap(info);
	return (0);
}