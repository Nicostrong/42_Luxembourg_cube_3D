/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/08 15:50:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_limit_pos(t_info * info, double *new_padx, double *new_pady, int dirx, int diry)
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
/*
 *	VERIFIER LA LOGIQUE POUR COLISION MUR
 *	PROBLEME LORSQUE LE RAYON CHANGE
 */
static void	ft_limit_pos(t_info * info, double *new_x, double *new_y, int *next_x, int *next_y)
{
	int		dirx;
	int		diry;

	//dirx = (fabs(new_x > info->user_x) > 1e-3) * ((new_x > info->user_x) - (new_x < info->user_x));
	//diry = (fabs(new_y > info->user_y) > 1e-3) * ((new_y > info->user_y) - (new_y < info->user_y));
	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	*next_x = info->x + dirx;
	*next_y = info->y + diry;
	if (info->map[*next_y][*next_x] == '1')
	{
		if (dirx < 0 && *new_x < floor(*new_x) + D_WALL)
			*new_x = floor(*new_x) + D_WALL;
		else if (dirx > 0 && *new_x > ceil(*new_x) - D_WALL)
			*new_x = ceil(*new_x) - D_WALL;
		if (diry < 0 && *new_y < floor(*new_y) + D_WALL)
			*new_y = floor(*new_y) + D_WALL;
		else if (diry > 0 && *new_y > ceil(*new_y) - D_WALL)
			*new_y = ceil(*new_y) - D_WALL;
	}
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
/*static int	ft_diag_move(t_info *info, double *new_x, double *new_y, int next_x, int next_y)
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
}*/

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
/*static int	ft_axis_move(t_info *info, double *new_pad, int next, int axis)
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
}*/

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
	int		next_x;
	int		next_y;
	double	new_x;
	double	new_y;

	new_x = info->user_x + (dir * STEP * cos(info->user_deg + angle_offset));
	new_y = info->user_y + (dir * STEP * sin(info->user_deg + angle_offset));
	next_x = 0;
	next_y = 0;
	printf("******************************\n");
	printf("new_x: %.2f\tnew_y: %.2f\n", new_x, new_y);
	printf("******************************\n");
	ft_limit_pos(info, &new_x, &new_y, &next_x, &next_y);
	printf("new_x: %.2f\tnew_y: %.2f\n", new_x, new_y);
	printf("******************************\n");
	info->user_x = new_x;
	info->user_y = new_y;
	info->x = floor(new_x);
	info->y = floor(new_y);
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