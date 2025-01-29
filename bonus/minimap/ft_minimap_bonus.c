/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/29 11:48:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_color(t_info *info, char *line)
 * </summary>
 *
 * <description>
 * 	ft_set_color set all color for a line.
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
static void	ft_set_color(t_info *info, char *line)
{
	int	index;

	index = -1;
	while (line[++index])
	{
		if (line[index] == '1')
			info->colors[index] = WALL;
		else if (line[index] == '0' || \
			line[index] == 'P' || \
			line[index] == 'I' || \
			line[index] == 'D')
			info->colors[index] = FLOOR;
		else
			info->colors[index] = EMPTY;
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
	int	h;
	int	w;
	int	x;
	int	y;
	int	index_pxl;

	index_pxl = 0;
	y = -1;
	while (++y < info->mini_h)
	{
		ft_set_color(info, map[y]);
		h = -1;
		while (++h < (int)info->heights[y])
		{
			x = -1;
			while (++x < info->mini_w)
			{
				w = -1;
				while (++w < (int)info->widths[x])
				{
					if (map[y][x] == 'D' && \
						((x > 0 && map[y][x - 1] == '1') || \
						(x < info->mini_w && map[y][x + 1] == '1')) && \
						h > ((info->heights[y] / 2) - 2) && h < ((info->heights[y] / 2) + 2))
						*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)DOOR;
					else if (map[y][x] == 'D' && \
						((y > 0 && map[y - 1][x] == '1') || \
						(y < info->mini_h - 1 && map[y + 1][x] == '1')) && \
						w > ((info->widths[x] / 2) - 2) && w < ((info->widths[x] / 2) + 2))
						*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)DOOR;
					else if (map[y][x] == 'I' && \
						h > ((info->heights[y] / 2) - 4) && h < ((info->heights[y] / 2) + 4) && \
						w > ((info->widths[x] / 2) - 4) && w < ((info->widths[x] / 2) + 4))
						*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)ITEM;
					else
						*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)info->colors[x];
					index_pxl += 4;
				}
			}
		}
	}
	return ;
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
static void	ft_draw_ray(t_info *info, double angle, double x, double y, char **map)
{
	int		grid_x;
	int		grid_y;
	double	dx;
	double	dy;

	dx = cos(angle);
	dy = sin(angle);
	while (x >= 0 && y >= 0 && x < MINI_W && y < MINI_H)
	{
		grid_x = ft_get_map_case((int)x, info->widths, info->mini_w);
		grid_y = ft_get_map_case((int)y, info->heights, info->mini_h);
		if (grid_x < 0 || grid_x >= info->mini_w || \
			grid_y < 0 || grid_y >= info->mini_h)
			return ;
		if (map[grid_y][grid_x] == '1' || \
			map[grid_y][grid_x] == 'D' || \
			map[grid_y][grid_x] == ' ')
			return ;
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
int	ft_minimap(t_info *info)
{
	char	**map;

	mlx_clear_window(info->mlx, info->mini->win);
	map = ft_get_minimap(info);
	ft_get_widths(info);
	ft_get_heights(info);
	ft_print_minimap(info, map);
	ft_set_img(info, map);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	//ft_put_player(info, info->player, MINI_W / 2, MINI_H / 2);
	ft_draw_ray(info, info->user_deg - (M_PI / 6), MINI_W / 2, MINI_H / 2, map);
	ft_draw_ray(info, info->user_deg, MINI_W / 2, MINI_H / 2, map);
	ft_draw_ray(info, info->user_deg + (M_PI / 6), MINI_W / 2, MINI_H / 2, map);
	//mlx_do_sync(info->mlx);
	ft_free_array(map);
	return (0);
}
