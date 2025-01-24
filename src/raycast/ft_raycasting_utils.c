/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:36 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 13:18:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/raycasting.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_pixel(t_info *info, int x, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_set_pixel set all pixel color of the image in y.
 * </description>
 *
 * <param type="t_win *" name="win">windows of the image</param>
 * <param type="int" name="x">index x of the image</param>
 * <param type="t_raycast *" name="rayt">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_set_pixel(t_info *info, int x, t_raycast *ray)
{
	char	*base_pixel;
	char	*pixel;
	int		y;
	t_win	*win;

	if (x < 0 || x >= WIDTH || ray->draw_end < 0 || ray->draw_start >= HEIGHT)
		return ;
	win = info->game;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	base_pixel = win->addr + x * (win->bpp / 8);
	y = -1;
	while (++y < HEIGHT)
	{
		pixel = base_pixel + y * win->size;
		if (y < ray->draw_start)
			*(unsigned int *)pixel = info->sky_color->color;
		else if (y < ray->draw_end)
			*(unsigned int *)pixel = ray->color; //ft_put_wall(info->w_n_img, y_start, y_end, y, x);
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

	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - info->user_x + \
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - info->user_y + \
			(1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		wall_x = info->user_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = info->user_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->text_x = (int)(wall_x * (double)info->w_n_img->w);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->text_x = info->w_n_img->w - ray->text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->text_x = info->w_n_img->w - ray->text_x - 1;
}
