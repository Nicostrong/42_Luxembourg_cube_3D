/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:43:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/03 10:53:58 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/raycasting_bonus.h"
typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

t_point	*ft_raycasting(t_info *info, int *num_points)
{
	t_raycast	ray;
	int			x;
	int			max_points;
	t_point		*points;

	max_points = WIDTH + 2;
	points = ft_calloc(max_points, sizeof(t_point));
	if (!info->move)
		return (NULL);
	*num_points = 0;
	ft_set_dir_and_plan(info, &ray);
	// Calcul du premier rayon
	x = 0;
	ft_cal_ray_dir(&ray, x);
	ft_init_dda(info, &ray);
	ft_hit_wall(info, &ray);
	ft_set_limit_wall(info, &ray);
	points[*num_points].x = ray.map_x;
	points[*num_points].y = ray.map_y;
	(*num_points)++;
	// Calcul des rayons intermédiaires 
	for (x = 1; x < WIDTH - 1; x++)
	{
		ft_cal_ray_dir(&ray, x);
		ft_init_dda(info, &ray);
		ft_hit_wall(info, &ray);
		ft_set_limit_wall(info, &ray);
		// Ajouter les points des extrémités des cases 
		if (ray.side == 0)
		{
			points[*num_points].x = ray.map_x;
			points[*num_points].y = ray.map_y + 0.5;
		}
		else
		{
			points[*num_points].x = ray.map_x + 0.5;
			points[*num_points].y = ray.map_y;
		}
		(*num_points)++;
	}
	// Calcul du dernier rayon 
	x = WIDTH - 1;
	ft_cal_ray_dir(&ray, x);
	ft_init_dda(info, &ray);
	ft_hit_wall(info, &ray);
	ft_set_limit_wall(info, &ray);
	points[*num_points].x = ray.map_x;
	points[*num_points].y = ray.map_y;
	(*num_points)++;
	// Ajouter un point pour indiquer la fin du tableau 
	points[*num_points].x = -1;
	points[*num_points].y = -1;
	return (points);
}
