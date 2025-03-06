/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:43:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/24 14:53:11 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/raycasting_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_pixel(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_set_pixel set all pixel color of the image in y.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_set_pixel(t_info *info, t_raycast *ray)
{
	char	*base_pixel;
	char	*pixel;
	int		y;
	t_win	*win;

	if (ray->x < 0 || ray->x >= WIDTH || \
		ray->draw_end < 0 || ray->draw_start >= HEIGHT)
		return ;
	win = info->game;
	ray->draw_start = fmax(0, ray->draw_start);
	ray->draw_end = fmin(HEIGHT - 1, ray->draw_end);
	base_pixel = win->addr + ray->x * (win->bpp / 8);
	y = -1;
	while (++y < HEIGHT)
	{
		pixel = base_pixel + y * win->size;
		if (y < ray->draw_start)
			*(unsigned int *)pixel = info->sky_color->color;
		else if (y < ray->draw_end)
			*(unsigned int *)pixel = ray->color;
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
 * 	For that we make some calculs :
 * 	1)	perpendicular distance to the wall.
 * 	2)	height of the wall.
 * 	3)	position in y to start to draw the wall.
 * 	4)	position in y to end to draw the wall.
 * 	5)	correction of both point to draw
 * 	6)	position of the		tex_y = ((int)ray->tex_pos) % ray->texture->h;
		ray->tex_pos += ray->step;
		color = ft_get_pixel_color(ray->texture, ray->text_x, tex_y);
		ft_put_pixel_color(info->game, ray->x, y, color); texture
 * 	7)	coordonne X of the texture to print
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
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
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	ray->text_y_offset = 0;
	if (ray->line_height > HEIGHT)
		ray->text_y_offset = ((ray->line_height - HEIGHT) / 2.0) * \
			ray->texture->h / ray->line_height;
	ray->draw_start = fmax(0, HEIGHT / 2 - ray->line_height / 2);
	ray->draw_end = fmin(HEIGHT - 1, HEIGHT / 2 + ray->line_height / 2);
	wall_x = info->user_x + ray->perp_wall_dist * ray->ray_dir_x;
	if (ray->side == 0)
		wall_x = info->user_y + ray->perp_wall_dist * ray->ray_dir_y;
	wall_x -= floor(wall_x);
	ray->text_x = (int)(wall_x * (double)ray->texture->w);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || \
		(ray->side == 1 && ray->ray_dir_y < 0))
		ray->text_x = ray->texture->w - ray->text_x - 1;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_hit_wall_x(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_hit_wall_x set all information when the ray move in x.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_hit_wall_x(t_info *info, t_raycast *ray)
{
	ray->side_dist_x += ray->delta_dist_x;
	ray->map_x += ray->step_x;
	ray->side = 0;
	ray->wall = 2;
	if (ray->step_x == -1)
		ray->wall = 0;
	ray->texture = info->w_e_img;
	if (ray->step_x == -1)
		ray->texture = info->w_w_img;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_hit_wall_y(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_hit_wall_y set all information when the ray move in y.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_hit_wall_y(t_info *info, t_raycast *ray)
{
	ray->side_dist_y += ray->delta_dist_y;
	ray->map_y += ray->step_y;
	ray->side = 1;
	ray->wall = 3;
	if (ray->step_y == -1)
		ray->wall = 1;
	ray->texture = info->w_s_img;
	if (ray->step_y == -1)
		ray->texture = info->w_n_img;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_hit_wall(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_hit_wall check if the ray hit a wall. It call a function to move in x or 
 * 	in y in regarding to the difference of distance betwenn the both axis.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_hit_wall(t_info *info, t_raycast *ray)
{
	while (info->map[ray->map_y][ray->map_x] != '1')
	{
		if (info->map[ray->map_y][ray->map_x] == 'C')
		{
			ft_hit_door(info, ray);
			ray->door = 1;
			break ;
		}
		if (ray->side_dist_x < ray->side_dist_y)
			ft_hit_wall_x(info, ray);
		else
			ft_hit_wall_y(info, ray);
	}
	return ;
}
