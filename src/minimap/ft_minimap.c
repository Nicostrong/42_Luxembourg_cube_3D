/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/17 14:01:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/minimap.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_color(t_info *info, char *line)
 * </summary>
 *
 * <description>
 * 	ft_get_color set all color for a line.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="char *" name="line">line of minimap</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_color(t_info *info, char *line)
{
	int	index;

	index = -1;
	while (line[++index])
	{
		if (line[index] == '1')
			info->colors[index] = 0xFF0000;
		else if (line[index] == '0' || line[index] == 'P')
			info->colors[index] = 0xFFFF00;
		else
			info->colors[index] = 0x0000FF;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_img(t_info *info, char **map)
 * </summary>
 *
 * <description>
 * 	ft_set_img set all pixel of the image.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="char **" name="map">minimap array</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_set_img(t_info *info, char **map)
{
	int	m;
	int	w;
	int	x;
	int	y;
	int	index_pxl;

	index_pxl = 0;
	m = -1;
	while (map[++m])
	{
		ft_get_color(info, map[m]);
		y = -1;
		while (++y < (int)info->heights[m])
		{
			w = -1;
			while (++w < info->mini_w)
			{
				x = -1;
				while (++x < (int)info->widths[w])
				{
					info->mini->addr[index_pxl++] = info->colors[w] & 0xFF;
					info->mini->addr[index_pxl++] = (info->colors[w] >> 8) & 0xFF;
					info->mini->addr[index_pxl++] = (info->colors[w] >> 16) & 0xFF;
					info->mini->addr[index_pxl++] = (info->colors[w] >> 24) &0xFF;
				}
			}
		}
	}
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_get_map_case(int coord, int *sizes, int max_value)
 * </summary>
 *
 * <description>
 * 	ft_get_map_case return the position of pixel on the map.
 * </description>
 *
 * <param type="int" name="coord">coordonnee of the point</param>
 * <param type="int *" name="sizes">array of sizes</param>
 * <param type="int" name="max_value">lenght of size array</param>
 *
 * <return>
 * 	the position in the array or -1 if out of array.
 * </return>
 *
 */
static int	ft_get_map_case(int coord, int *sizes, int max_value)
{
	int	i;
	int	cumulative_size;

	i = -1;
	cumulative_size = 0;
	while (++i < max_value)
	{
		cumulative_size += sizes[i];
		if (coord < cumulative_size)
			return (i);
	}
	return (-1);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_draw_ray(t_info *info, double x, double y, char **map)
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
static double	ft_draw_ray(t_info *info, double x, double y, char **map)
{
	int		grid_x;
	int		grid_y;
	double	dx;
	double	dy;
	double	distance;

	dx = cos(info->user_deg);
	dy = sin(info->user_deg);
	while (x >= 0 && y >= 0 && x < MINI_W && y < MINI_H)
	{
		grid_x = ft_get_map_case((int)x, info->widths, info->mini_w);
		grid_y = ft_get_map_case((int)y, info->heights, info->mini_h);
		distance = sqrt(pow(x - (MINI_W / 2), 2) + pow(y - (MINI_H / 2), 2));
		if (grid_x < 0 || grid_x >= info->mini_w || grid_y < 0 || grid_y >= info->mini_h)
			return (distance);
		if (map[grid_y][grid_x] == '1' || map[grid_y][grid_x] ==  ' ')
			return (distance);
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, 0x000000);
		x += dx;
		y += dy;
	}
	return (distance);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_minimap(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_minimap draw the minimap om the window minimap. The player is in the 
 *  center of the window. The function draw the ray of the vision.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_minimap(t_info *info)
{
	char	**map;

	mlx_clear_window(info->mlx, info->mini->win);
	map = ft_get_minimap(info);
	ft_get_widths(info);
	ft_get_heights(info);
	/*if (DEBUG)
		ft_print_minimap(info, map);*/
	ft_set_img(info, map);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	mlx_do_sync(info->mlx);
	ft_put_player(info, info->player, MINI_W / 2, MINI_H / 2);
	//mlx_string_put(info->mlx, info->mini->win,  MINI_W / 2, MINI_H / 2, 0xFF0000, "X");
	info->len_ray = ft_draw_ray(info, MINI_W / 2, MINI_H / 2, map);
	//if (DEBUG)
	//	printf(BYELLOW"Len of ray from plyer to wall: %.2f\n"RESET, info->len_ray);
	//ft_print_user_data(info);
	ft_free_array(map);
	ft_raycasting(info);
}
