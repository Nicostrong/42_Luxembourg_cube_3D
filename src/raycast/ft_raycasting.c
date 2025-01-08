/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:45:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/08 10:16:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/structures.h"

static double	ft_cast_ray(t_info *info, double ray_angle)
{
	double	distance;
	int		wall;
	int		x;
	int		y;

	wall = 0;
	distance = 0.0;
	while (!wall && distance < WIDTH)
	{
		distance += STEP_RAY;
		x = (int)(info->user_x + (distance * cos(ray_angle)) / info->w_n_img->size);
		y = (int)(info->user_y + (distance * sin(ray_angle)) / info->w_n_img->size);
		if (info->map[y][x] == '1' || info->map[y][x] == ' ')
			wall = 1;
	}
	return (distance);
}

static int	ft_cal_wall_height(t_info *info, double distance)
{
	int		h_wall;

	h_wall = (int)((info->w_n_img->size / distance) * D_SCREAN);
	return (h_wall);
}

static void	ft_cal_wall_pxl(int h_wall, int *start, int *end)
{
	*start = (HEIGHT / 2) - (h_wall / 2);
	*end = (HEIGHT / 2) + (h_wall / 2);
	if (*start < 0)
		*start = 0;
	if (*end > HEIGHT)
		*end = HEIGHT;
	return ;
}

/*static void	ft_draw(t_info *info, int *start, int *end, int x)
{
	int	wall;
	int	sky;
	int	floor;
	int	y;

	wall = 0xFF0000;
	sky = 0x0000FF;
	floor = 0xFFFF00;
	y = -1;
	while (++y < HEIGHT)
	{
		if (y < *start)
			mlx_pixel_put(info->mlx, info->game->win, x, y, sky);
		else if (y >= *start && y <= *end)
			mlx_pixel_put(info->mlx, info->game->win, x, y, wall);
		else
			mlx_pixel_put(info->mlx, info->game->win, x, y, floor);
	}

}*/

void	ft_raycasting(t_info *info)
{
	int		x;
	int		h_wall;
	int		start;
	int		end;
	double	ray_angle;
	double	distance;

	x = -1;
	while (++x < WIDTH)
	{
		ray_angle = info->user_deg - (FOV / 2) + ((double)x / WIDTH) * FOV;
		distance = ft_cast_ray(info, ray_angle);
		h_wall = ft_cal_wall_height(info, distance);
		//printf("ray_angle: %.2f\n", ray_angle);
		//printf("Distance: %.2f\n", distance);
		//printf("Wall height: %d\n", h_wall);
		ft_cal_wall_pxl(h_wall, &start, &end);
		//ft_draw(info, &start, &end, x);
		//printf("Column %d: Wall from pixel %d to %d\n", x, start, end);
	}
}