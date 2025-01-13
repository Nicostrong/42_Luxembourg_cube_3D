/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/13 09:55:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"
#include "../../includes/minimap.h"

/*int	ft_isforbidden_zone(t_info *info, double newx, double newy)
{
	int		x;
	int		y;
	double	padx;
	double	pady;

	x = (int)newx;
	y = (int)newy;
	padx = newx - x;
	pady = newy - y;
	// Vérifier HG
	if (padx < D_WALL && pady < D_WALL)
		if (x > 0 && y > 0 && info->map[y][x - 1] == '0' && \
			info->map[y - 1][x] == '0' && info->map[y - 1][x - 1] == '1')
			return (1);
	// Vérifier HD
	if (padx > 1 - D_WALL && pady < D_WALL)
		if (x < info->w - 1 && y > 0 &&	info->map[y][x + 1] == '0' && \
			info->map[y - 1][x] == '0' && info->map[y - 1][x + 1] == '1')
			return (1);
	// Vérifier BG
	if (padx < D_WALL && pady > 1 - D_WALL)
		if (x > 0 && y < info->h - 1 &&	info->map[y][x - 1] == '0' && \
			info->map[y + 1][x] == '0' &&	info->map[y + 1][x - 1] == '1')
			return (1);
	// Vérifier BD
	if (x > 1 - D_WALL && y > 1 - D_WALL)
		if (x < info->w - 1 && y < info->h - 1 && info->map[y][x + 1] == '0' \
			&& info->map[y + 1][x] == '0' && info->map[y + 1][x + 1] == '1')
			return (1);
	return (0); // Pas dans une zone interdite
}*/

/*static int	ft_isforbidden_zone(t_info *info, int dirx, int diry)
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
}*/

static void	ft_check_x(t_info *info, int dirx, double *new_x, double *new_y)
{
	int		x;
	int		y;

	x = info->x;
	y = info->y;
	if (info->map[y][x + dirx] == '1')
	{
		if (dirx < 0 && *new_x - x < D_WALL)
			*new_x = floor(*new_x) + D_WALL;
		else if (dirx > 0 && *new_x - x > 1 - D_WALL)
			*new_x = ceil(*new_x) - D_WALL;
	}
	else if (info->map[y + dirx][x + dirx] == '1' && \
			info->map[y + dirx][x] == '0')
	{
		if (dirx < 0 && *new_x - x < D_WALL && (*new_y - y < D_WALL || *new_y - y > 1 - D_WALL))
			*new_x = x + D_WALL;
		else if (dirx > 0 && *new_x - x > 1 - D_WALL && (*new_y - y < D_WALL || *new_y - y > 1 - D_WALL))
			*new_x = x + 1 - D_WALL;
	}
}

static void	ft_check_y(t_info *info, int diry, double *new_y, double *new_x)
{
	int		x;
	int		y;

	x = info->x;
	y = info->y;
	if (info->map[y + diry][x] == '1')
	{
		if (diry < 0 && *new_y < floor(*new_y) + D_WALL)
			*new_y = floor(*new_y) + D_WALL;
		else if (diry > 0 && *new_y > ceil(*new_y) - D_WALL)
			*new_y = ceil(*new_y) - D_WALL;
	}
	else if (info->map[info->y + diry][x] == '0' && \
			info->map[y + diry][x + diry] == '1' && \
			info->map[y][x + diry] == '0')
	{
		if (diry < 0 && *new_y - y < D_WALL && (*new_x - x < D_WALL || *new_x - x > 1 - D_WALL))
			*new_y = y + D_WALL;
		else if (diry > 0 && *new_y - y > 1 - D_WALL && (*new_x - x < D_WALL || *new_x - x > 1 - D_WALL))
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
static void	ft_check_wall(t_info * info, double *new_x, double *new_y)
{
	int	dirx;
	int	diry;

	dirx = (*new_x > info->user_x) - (*new_x < info->user_x);
	diry = (*new_y > info->user_y) - (*new_y < info->user_y);
	printf("\t\tCHECK WALLL\n");
	printf("\t\t\tdirx: %d\tdiry: %d\n", dirx, diry);
	if (dirx != 0 && !diry)
	{
		printf("\t\t\tAXE X\n");
		ft_check_x(info, dirx, new_x, new_y);
	}
	if (diry != 0 && !dirx)
	{
		printf("\t\t\tAXE Y\n");
		ft_check_y(info, diry, new_y, new_x);
	}
	if (diry && dirx)
	{
		printf("\t\t\tAXE X et Y\n");
		ft_check_x(info, dirx, new_x, new_y);
		ft_check_y(info, diry, new_y, new_x);
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
	if ((new_x - info->x) < D_WALL || (new_x - info->x) > 1 - D_WALL || \
		(new_y - info->y) < D_WALL || (new_y - info->y) > 1 - D_WALL)
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
	if (x < (WIDTH / 2) - 100)
		info->user_deg -= ROTATE;
	else if (x > (WIDTH / 2) + 100)
		info->user_deg += ROTATE;
	else
		info->mouse_rot = 0;
	if (y < (HEIGHT / 2) - 100)
		ft_move(info, 0, 1);
	else if (y > (HEIGHT / 2) + 100)
		ft_move(info, 0, -1);
	else
		info->mouse_dir = 0;
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
