/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:12:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 18:02:48 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_ray_wall(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_print_ray_wall print the texture of the wall.
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
static void	ft_print_ray_wall(t_info *info, t_raycast *ray)
{
	if (ray->texture == info->w_n_img)
		printf("\ttexture: NORTH\n");
	else if (ray->texture == info->w_s_img)
		printf("\ttexture: SOUTH\n");
	else if (ray->texture == info->w_e_img)
		printf("\ttexture: EAST\n");
	else
		printf("\ttexture: WEST\n");
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_ray(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_print_ray print all information about the raycasting.
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
void	ft_print_ray(t_info *info, t_raycast *ray)
{
	printf("******************************\n");
	printf(BBLUE"\tR A Y C A S T I N G\n"RESET);
	printf("******************************\n\n");
	if (!ray)
		return ;
	printf("\tposition in x: %d\n", ray->x);
	printf("\tray->side = %d\n", ray->side);
	printf("\tray->wall = %d\n", ray->wall);
	printf("\tray->door	 = %d\n", ray->door);
	printf("\tray->dist_y = %.2f\n", ray->side_dist_y);
	printf("\tray->dist_x = %.2f\n", ray->side_dist_x);
	printf("\tray->map_x = %d\n", ray->map_x);
	printf("\tray->map_y = %d\n", ray->map_y);
	printf("\tmap = %c\n", info->map[ray->map_y][ray->map_x]);
	printf("\theight of wall: %d\n", ray->line_height);
	printf("\tindex start: %d", ray->draw_start);
	printf("\tindex end: %d\n", ray->draw_end);
	printf("\thorizontal dist: %.2f\n", ray->perp_wall_dist);
	ft_print_ray_wall(info, ray);
	return ;
}
