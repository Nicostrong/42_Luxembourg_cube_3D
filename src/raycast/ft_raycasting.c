/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:45:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/20 11:21:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/raycasting.h"
#include "../../includes/structures.h"

static void	ft_set_pixel(t_win *win, int x, int y_start, int y_end, int color)
{
	char	*pixel;
	int		y;

	if (x < 0 || x >= WIDTH || y_end < 0 || y_start >= HEIGHT)
		return ;
	if (y_start < 0)
		y_start = 0;
	if (y_end >= HEIGHT)
		y_end = HEIGHT - 1;
	y = 0;
	//	print sky
	while (y < y_start)
	{
		pixel = win->addr + (y * win->size + x * (win->bpp / 8));
		*(unsigned int *)pixel = 0x0000FF;
		y++;
	}
	//	print wall
	while (y < y_end)
	{
		pixel = win->addr + (y * win->size + x * (win->bpp / 8));
		*(unsigned int *)pixel = color;
		y++;
	}
	//	print floor
	while (y < HEIGHT)
	{
		pixel = win->addr + (y * win->size + x * (win->bpp / 8));
		*(unsigned int *)pixel = 0x00FFFF;;
		y++;
	}
}

void	ft_set_dir_and_plan(t_info *info, t_raycast *ray)
{
	ray->dir_x = cos(info->user_deg);
	ray->dir_y = sin(info->user_deg);
	ray->plane_x = -ray->dir_y * tan(FOV / 2.0);
	ray->plane_y = ray->dir_x * tan(FOV / 2.0);
	ray->prev_draw_end = HEIGHT / 2;
}

void	ft_cal_ray_dir(t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (double)(WIDTH - 1) - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
}

void	ft_init_dda(t_info *info, t_raycast *ray)
{
	ray->map_x = (int)info->user_x;
	ray->map_y = (int)info->user_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (info->user_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - info->user_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (info->user_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - info->user_y) * ray->delta_dist_y;
	}
}

void	ft_hit_wall(t_info *info, t_raycast *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
			ray->wall = (ray->step_x == -1) ? 0 : 2;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
			ray->wall = (ray->step_y == -1) ? 1 : 3;
		}
		hit = info->map[ray->map_y][ray->map_x] == '1';
	}
}

void	ft_set_limit_wall(t_info *info, t_raycast *ray)
{
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
}


/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_raycasting(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_raycasting display the map on the screan with a 3D view.
 * </description>
 *
 * <param type="t_info *" name="info">general structure/param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_raycasting(t_info *info)
{
	t_raycast	ray;
	int			x;

	ft_set_dir_and_plan(info, &ray);
	x = -1;
	while (++x < WIDTH)
	{
		ft_cal_ray_dir(&ray, x);
		ft_init_dda(info, &ray);
		ft_hit_wall(info, &ray);
		ft_set_limit_wall(info, &ray);
		ray.color = 0x000000;	//	color black
		if (ray.wall == 1)
			ray.color = 0xFFFF00;	//	color yellow
		else if (ray.wall == 2)
			ray.color = 0x00AFAF;	//	color cyan
		else if (ray.wall == 3)
			ray.color = 0xFF00FF;	//	color magenta
		ft_set_pixel(info->game, x, ray.draw_start, ray.draw_end, ray.color);
		ray.prev_draw_end = ray.draw_end;
	}
	mlx_put_image_to_window(info->mlx, info->game->win, info->game->img, 0, 0);
}

