/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:15:40 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/24 14:39:14 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_d_r(t_info *info, double x, double y, char **map)
 * </summary>
 *
 * <description>
 * 	ft_dray_ray draw the ray from the player to the limit of the window or the 
 *  first wall.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="x">position of the player in x</param>
 * <param type="double" name="y">position of the player in y</param>
 * <param type="char **" name="map">minimap array</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_d_rma(t_info *info, double x, double y, char **map)
{
	int		grid_x;
	int		grid_y;
	int		i;
	double	dx;
	double	dy;

	i = 0;
	dx = cos(info->user_deg + (M_PI / 6));
	dy = sin(info->user_deg + (M_PI / 6));
	while (x >= 0 && y >= 0 && x < MINI_W && y < MINI_H && i < 18)
	{
		grid_x = ft_get_map_case((int)x, info->widths, info->mini_w);
		grid_y = ft_get_map_case((int)y, info->heights, info->mini_h);
		if (grid_x < 0 || grid_x >= info->mini_w || \
			grid_y < 0 || grid_y >= info->mini_h)
			return ;
		if (map[grid_y][grid_x] == '1' || map[grid_y][grid_x] == ' ')
			return ;
		if (map[grid_y][grid_x] == 'D' || map[grid_y][grid_x] == 'F')
			i++;
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, BLUE);
		x += dx;
		y += dy;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_d_r(t_info *info, double x, double y, char **map)
 * </summary>
 *
 * <description>
 * 	ft_dray_ray draw the ray from the player to the limit of the window or the 
 *  first wall.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="x">position of the player in x</param>
 * <param type="double" name="y">position of the player in y</param>
 * <param type="char **" name="map">minimap array</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_d_rmi(t_info *info, double x, double y, char **map)
{
	int		grid_x;
	int		grid_y;
	int		i;
	double	dx;
	double	dy;

	i = 0;
	dx = cos(info->user_deg - (M_PI / 6));
	dy = sin(info->user_deg - (M_PI / 6));
	while (x >= 0 && y >= 0 && x < MINI_W && y < MINI_H && i < 18)
	{
		grid_x = ft_get_map_case((int)x, info->widths, info->mini_w);
		grid_y = ft_get_map_case((int)y, info->heights, info->mini_h);
		if (grid_x < 0 || grid_x >= info->mini_w || \
			grid_y < 0 || grid_y >= info->mini_h)
			return ;
		if (map[grid_y][grid_x] == '1' || map[grid_y][grid_x] == ' ')
			return ;
		if (map[grid_y][grid_x] == 'D' || map[grid_y][grid_x] == 'F')
			i++;
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, BLUE);
		x += dx;
		y += dy;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_d_r(t_info *info, double x, double y, char **map)
 * </summary>
 *
 * <description>
 * 	ft_dray_ray draw the ray from the player to the limit of the window or the 
 *  first wall.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="x">position of the player in x</param>
 * <param type="double" name="y">position of the player in y</param>
 * <param type="char **" name="map">minimap array</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_d_r(t_info *info, double x, double y, char **map)
{
	int		grid_x;
	int		grid_y;
	int		i;
	double	dx;
	double	dy;

	i = 0;
	dx = cos(info->user_deg);
	dy = sin(info->user_deg);
	while (x >= 0 && y >= 0 && x < MINI_W && y < MINI_H && i < 18)
	{
		grid_x = ft_get_map_case((int)x, info->widths, info->mini_w);
		grid_y = ft_get_map_case((int)y, info->heights, info->mini_h);
		if (grid_x < 0 || grid_x >= info->mini_w || \
			grid_y < 0 || grid_y >= info->mini_h)
			return ;
		if (map[grid_y][grid_x] == '1' || map[grid_y][grid_x] == ' ')
			return ;
		if (map[grid_y][grid_x] == 'D' || map[grid_y][grid_x] == 'F')
			i++;
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, BLUE);
		x += dx;
		y += dy;
	}
	return ;
}
