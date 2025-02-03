/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:45:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/03 11:38:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/raycasting_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_dir_and_plan(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_set_dir_and_plan set the direction and the plan of the raycasting.
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
static void	ft_set_dir_and_plan(t_info *info, t_raycast *ray)
{
	ray->dir_x = cos(info->user_deg);
	ray->dir_y = sin(info->user_deg);
	ray->plane_x = -ray->dir_y * T_HALF_FOV;
	ray->plane_y = ray->dir_x * T_HALF_FOV;
	ray->prev_draw_end = HEIGHT / 2;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_cal_ray_dir(t_raycast *ray, int x)
 * </summary>
 *
 * <description>
 * 	ft_cal_ray_dir calculate the direction of the ray.
 * </description>
 *
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 * <param type="int" name="x">index x of the image</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_cal_ray_dir(t_raycast *ray, int x)
{
	double	camera_x;
	
	camera_x = 2 * x / (double)(WIDTH - 1) - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * camera_x;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_dda(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_init_dda initialize the DDA algorithm.
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
static void	ft_init_dda(t_info *info, t_raycast *ray)
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
 * 	ft_hit_wall check if the ray hit a wall.
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
static void	ft_hit_wall(t_info *info, t_raycast *ray)
{
	while (info->map[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
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
		}
		else
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
		}
	}
	return ;
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
 * <param type="t_info *" name="info">general structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
int	ft_raycasting(t_info *info)
{
	t_raycast	ray;
	int			x;

	if (!info->move)
		return (0);
	ft_set_dir_and_plan(info, &ray);
	x = -1;
	while ++(x < WIDTH)
	{
		ft_cal_ray_dir(&ray, x);
		ft_init_dda(info, &ray);
		ft_hit_wall(info, &ray);
		ft_set_limit_wall(info, &ray);
		ray.color = W_WALL;		//	OUEST
		if (ray.wall == 1)
			ray.color = N_WALL;	//	NORD
		else if (ray.wall == 2)
			ray.color = S_WALL;	//	SUD
		else if (ray.wall == 3)
			ray.color = E_WALL;	//	EST
		//ft_draw_texture(info, &ray, x);
		ft_set_pixel(info, x, ray.draw_start, ray.draw_end, ray.color);
		ray.prev_draw_end = ray.draw_end;
		//x += (int)RAY_STEP;
	}
	mlx_put_image_to_window(info->mlx, info->game->win, info->game->img, 0, 0);
	info->move = 0;
	return (0);
}
