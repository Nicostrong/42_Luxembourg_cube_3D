/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:43:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/03 11:32:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/raycasting_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_pixel(t_win *win, int x, int y_start, int y_end, int color)
 * </summary>
 *
 * <description>
 * 	ft_set_pixel set all pixel color of the image in y.
 * </description>
 *
 * <param type="t_win *" name="win">windows of the image</param>
 * <param type="int" name="x">index x of the image</param>
 * <param type="int" name="y_start">start index y of the wall</param>
 * <param type="int" name="y_end">end index y of the wall</param>
 * <param type="int" name="color">color of the wall</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_set_pixel(t_info *info, int x, int y_start, int y_end, int color)
{
	char	*base_pixel;
	char	*pixel;
	int		y;
	t_win	*win;

	if (x < 0 || x >= WIDTH || y_end < 0 || y_start >= HEIGHT)
		return ;
	win = info->game;
	y_start = fmax(0, y_start);
	y_end = fmin(HEIGHT - 1, y_end);
	base_pixel = win->addr + x * (win->bpp / 8);
	y = -1;
	while (++y < HEIGHT)
	{
		pixel = base_pixel + y * win->size;
		if (y < y_start)
			*(unsigned int *)pixel = info->sky_color->color;
		else if (y < y_end)
			*(unsigned int *)pixel = color; //ft_put_wall(info->w_n_img, y_start, y_end, y, x);
		else
			*(unsigned int *)pixel = info->floor_color->color;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_limit_wall(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_set_limit_wall set the limit of the wall.
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_set_limit_wall(t_info *info, t_raycast *ray)
{
	double	wall_x;

	ray->perp_wall_dist = (ray->map_y - info->user_y + \
		(1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - info->user_x + \
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = fmax(0, -ray->line_height / 2 + HEIGHT / 2);
	ray->draw_end = fmin(HEIGHT - 1, ray->line_height / 2 + HEIGHT / 2);
	wall_x = info->user_x + ray->perp_wall_dist * ray->ray_dir_x;
	if (ray->side == 0)
		wall_x = info->user_y + ray->perp_wall_dist * ray->ray_dir_y;
	wall_x -= floor(wall_x);
	ray->text_x = (int)(wall_x * (double)info->w_n_img->w);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || \
		(ray->side == 1 && ray->ray_dir_y < 0))
		ray->text_x = info->w_n_img->w - ray->text_x - 1;
	return ;
}
