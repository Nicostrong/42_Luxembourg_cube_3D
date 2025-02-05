/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:12:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/05 09:34:13 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_map(t_info *info, char **map)
 * </summary>
 *
 * <description>
 * 	ft_print_map print the map.
 * </description>
 *
 * <param type="t_info" name="info">the structure with all information</param>
 * <param type="char **" name="map">array of minimap</param>
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
	printf("\tray->dist_y = %.2f\n", ray->side_dist_y);
	printf("\tray->dist_x = %.2f\n", ray->side_dist_x);
	printf("\tray->map_x = %d\n", ray->map_x);
	printf("\tray->map_y = %d\n", ray->map_y);
	printf("\tmap = %c\n", info->map[ray->map_y][ray->map_x]);
	printf("\theight of wall: %d\n", ray->line_height);
	printf("\tindex start: %d\tindex end: %d\n", ray->draw_start, ray->draw_end);
	printf("\thorizontal dist: %.2f\n", ray->perp_wall_dist);
	printf("\ttexture: %s\n", ray->texture == info->w_n_img ? "NORD" : \
		ray->texture == info->w_s_img ? "SUD" : \
		ray->texture == info->w_e_img ? "EST" : "OUEST");
	return ;
}
