/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:45:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 08:02:20 by nfordoxc         ###   Luxembourg.lu     */
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
static void	ft_set_pixel(t_info *info, int x, int y_start, int y_end, int color)
{
	char	*base_pixel;
	char	*pixel;
	int		y;
	t_win	*win;

	if (x < 0 || x >= WIDTH || y_end < 0 || y_start >= HEIGHT)
		return ;
	win = info->game;
	if (y_start < 0)
		y_start = 0;
	if (y_end >= HEIGHT)
		y_end = HEIGHT - 1;
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
}


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
void	ft_set_dir_and_plan(t_info *info, t_raycast *ray)
{
	ray->dir_x = cos(info->user_deg);
	ray->dir_y = sin(info->user_deg);
	ray->plane_x = -ray->dir_y * tan(FOV / 2.0);
	ray->plane_y = ray->dir_x * tan(FOV / 2.0);
	ray->prev_draw_end = HEIGHT / 2;
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
void	ft_cal_ray_dir(t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (double)(WIDTH - 1) - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
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
			ray->texture = (ray->step_x == -1) ? info->w_w_img : info->w_e_img;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
			ray->wall = (ray->step_y == -1) ? 1 : 3;
			ray->texture = (ray->step_y == -1) ? info->w_n_img : info->w_s_img;
		}
		hit = info->map[ray->map_y][ray->map_x] == '1';
	}
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
void	ft_raycasting(t_info *info)
{
	t_raycast	ray;
	int			x;

	if (!info->move)
		return (0);
	ft_set_dir_and_plan(info, &ray);
	x = -1;
	while (++x < WIDTH)
	{
		ft_cal_ray_dir(&ray, x);
		ft_init_dda(info, &ray);
		ft_hit_wall(info, &ray);
		ft_set_limit_wall(info, &ray);
		ray.color = 0x1D1430;		//	OUEST
		if (ray.wall == 1)
			ray.color = 0xFFFF00;	//	NORD
		else if (ray.wall == 2)
			ray.color = 0x00AFAF;	//	SUD
		else if (ray.wall == 3)
			ray.color = 0xFF00FF;	//	EST
		//ft_draw_texture(info, &ray, x);
		ft_set_pixel(info, x, ray.draw_start, ray.draw_end, ray.color);
		ray.prev_draw_end = ray.draw_end;
		//x += (int)RAY_STEP;
	}
	mlx_put_image_to_window(info->mlx, info->game->win, info->game->img, 0, 0);
	info->move = 0;
}

