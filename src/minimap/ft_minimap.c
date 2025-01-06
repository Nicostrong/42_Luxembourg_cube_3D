/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/06 12:06:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/structures.h"
#include "../../includes/error.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	char	**ft_get_minimap(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_minimap create the array for the minimap with the player in center of
 *  the map.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	the minimap array.
 * </return>
 *
 */
static char	**ft_get_minimap(t_info *info)
{
	char	**map;
	char	*s;
	int		i;

	info->mini_h = 5;
	if (info->pad_y != 0.0)
		info->mini_h = 6;
	info->mini_w = 7;
	if (info->pad_x != 0.0)
		info->mini_w = 8;
	map = ft_calloc(info->mini_h + 1, sizeof(char *));
	if (!map)
		ft_perror_exit(E_MALLOC, info);
	i = -1;
	while (++i < info->mini_h)
	{
		if (info->pad_y >= 0.0 && info->user_y - 2 + i >= 0 && info->user_y - 2 + i < info->h)
			s = info->map[info->user_y - 2 + i];
		else if (info->pad_y < 0.0 && info->user_y - 3 + i >= 0 && info->user_y - 3 + i < info->h)
			s = info->map[info->user_y - 3 + i];
		else
			s = NULL;
		if (info->pad_x < 0.0)
			map[i] = ft_formatsubstr(s, info->user_x - 4, info->mini_w, '*');
		else
			map[i] = ft_formatsubstr(s, info->user_x - 3, info->mini_w, '*');
	}
	return (map);
}

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
 * 	void	ft_get_heights(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_heights set an int array with all value of height.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_heights(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 6)
		info->heights[i] = MINI_S_BLOC;
	if (info->pad_y < 0)
	{
		info->heights[0] = (int)(STEP * fabs(info->pad_y));
		info->heights[5] = MINI_S_BLOC - (int)(STEP * fabs(info->pad_y));
	}
	else if (info->pad_y > 0)
	{
		info->heights[0] = MINI_S_BLOC - (int)(STEP * info->pad_y);
		info->heights[5] = (int)(STEP * info->pad_y);
	}
	else
		info->heights[5] = 0;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_widths(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_widths set an int array with all value of width.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_widths(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 8)
		info->widths[i] = MINI_S_BLOC;
	if (info->pad_x < 0)
	{
		info->widths[0] = (int)(STEP * fabs(info->pad_x));
		info->widths[7] = MINI_S_BLOC - (int)(STEP * fabs(info->pad_x));
	}
	else if (info->pad_x > 0)
	{
		info->widths[0] = MINI_S_BLOC - (int)(STEP * info->pad_x);
		info->widths[7] = (int)(STEP * info->pad_x);
	}
	else 
		info->widths[7] = 0;
	return ;
}

/*static int	ft_is_wall(char **map, int x, int y)
{
	if (x < 0 || x >= 7 || y < 0 || y >= 5)
		return (1);
	return (map[y][x] == '1');
}*/

/*static void	ft_draw_ray(t_info *info, double x, double y, char **map)
{
	int		color;
	double	dx;
	double	dy;

	(void)map;
	color = 0x000000;
	dx = cos(info->user_deg);
	dy = sin(info->user_deg);
	while (x > 0 && y > 0 && x < MINI_W && y < MINI_H)
	{
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, color);
		x += dx;
		y += dy;
	}
}*/

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
static void	ft_draw_ray(t_info *info, double x, double y, char **map)
{
	int		grid_x;
	int		grid_y;
	double	dx;
	double	dy;

	dx = cos(info->user_deg);
	dy = sin(info->user_deg);
	/*printf("***********************\n");
	printf("center of RAY (%.2f, %.2f)\n", x, y);
	printf("delta x: %.2f\tdelta y: %.2f\n", dx, dy);*/
	while (x >= 0 && y >= 0 && x < MINI_W && y < MINI_H)
	{
		grid_x = ft_get_map_case((int)x, info->widths, info->mini_w);
		grid_y = ft_get_map_case((int)y, info->heights, info->mini_h);
		if (grid_x < 0 || grid_x >= info->mini_w || grid_y < 0 || grid_y >= info->mini_h)
			return ;
		if (map[grid_y][grid_x] == '1' || map[grid_y][grid_x] ==  ' ')
			return ;
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, 0xF0F0F0);
		x += dx;
		y += dy;
	}
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
	//ft_putstrarray(map);
	ft_get_widths(info);
	ft_get_heights(info);
	ft_set_img(info, map);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	mlx_do_sync(info->mlx);
	if (info->player)
		mlx_put_image_to_window(info->mlx, info->mini->win, info->player->img, \
			(MINI_W / 2) - 5, (MINI_H / 2) - 5);
	else
		ft_put_circle(info, MINI_W / 2, MINI_H / 2);
	ft_draw_ray(info, MINI_W / 2, MINI_H / 2, map);
	ft_free_array(map);
}