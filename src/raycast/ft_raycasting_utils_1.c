/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:52:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/07 15:17:40 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/raycasting.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_draw_column(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_init_draw_column initialise some variable for the raycasting.
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
static void	ft_init_draw_column(t_info *info, t_raycast *ray)
{
	ray->step = (double)ray->texture->h / ray->line_height;
	ray->tex_pos = 0.0;
	if (ray->line_height > HEIGHT)
		ray->tex_pos = (ray->text_y_offset + \
			(ray->line_height - HEIGHT) / 2.0) * ray->step;
	ray->base_pixel = info->game->addr + ray->x * (info->game->bpp / 8);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_pixel_color(t_info *info, t_raycast *ray, char *pixel, int y)
 * </summary>
 *
 * <description>
 * 	ft_set_pixel_color set the color of the pixel to print on the image.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_raycast *" name="ray">raycasting structure</param>
 * <param type="char *" name="pixel">value of the pixel</param>
 * <param type="int" name="y">position of pixel in y</param>
 * 
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_set_pixel_color(t_info *info, t_raycast *ray, char *pixel, int y)
{
	int	tex_y;
	int	color;

	if (y < ray->draw_start)
		*(unsigned int *)pixel = info->sky_color->color;
	else if (y < ray->draw_end)
	{
		tex_y = ((int)ray->tex_pos) % ray->texture->h;
		ray->tex_pos += ray->step;
		color = ft_get_pixel_color(ray->texture, ray->text_x, tex_y);
		ft_put_pixel_color(info->game, ray->x, y, color);
	}
	else
		*(unsigned int *)pixel = info->floor_color->color;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_draw_column(t_info *info, t_raycast *ray)
 * </summary>
 *
 * <description>
 * 	ft_draw_column set all pixel of a column pixel one by one.
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
static void	ft_draw_column(t_info *info, t_raycast *ray)
{
	int		y;
	char	*pixel;

	ft_init_draw_column(info, ray);
	y = -1;
	while (++y < HEIGHT)
	{
		pixel = ray->base_pixel + y * info->game->size;
		ft_set_pixel_color(info, ray, pixel, y);
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_draw_image(t_info *info, t_lst_ray *list)
 * </summary>
 *
 * <description>
 * 	ft_draw_image itere all structure of raycasting to set all pixel of the 
 * 	image.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_lst_ray *" name="lst_ray">linked list of ray struct</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_draw_image(t_info *info, t_lst_ray *lst_ray)
{
	t_lst_ray	*current;
	t_lst_ray	*next;

	current = lst_ray;
	while (current && current->next)
	{
		next = current->next;
		ft_draw_column(info, &current->ray);
		current = next;
	}
	return ;
}
