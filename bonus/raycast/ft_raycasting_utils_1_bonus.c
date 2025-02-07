/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils_1_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:52:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/07 08:34:04 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/raycasting_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_ray_list(t_lst_ray *lst_ray);
 * </summary>
 *
 * <description>
 * 	ft_
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_free_ray_list(t_lst_ray *lst_ray)
{
	t_lst_ray	*tmp;

	while (lst_ray)
	{
		tmp = lst_ray;
		lst_ray = lst_ray->next;
		ft_free((void **)&tmp);
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	
 * </summary>
 *
 * <description>
 * 	ft_
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	add_ray_to_list(t_lst_ray **list, t_raycast ray)
{
	t_lst_ray	*new;
	t_lst_ray	*temp;

	new = ft_calloc(1, sizeof(t_lst_ray));
	if (!new)
		return ;
	new->ray = ray;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	
 * </summary>
 *
 * <description>
 * 	ft_
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_draw_column(t_info *info, t_raycast *ray)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	char	*base_pixel;
	char	*pixel;

	step = (double)ray->texture->h / ray->line_height;
	tex_pos = 0.0;
	if (ray->line_height > HEIGHT)
		tex_pos = (ray->text_y_offset + (ray->line_height - HEIGHT) / 2.0) * step;
	base_pixel = info->game->addr + ray->x * (info->game->bpp / 8);
	y = -1;
	while (++y < HEIGHT)
	{
		pixel = base_pixel + y * info->game->size;
		if (y < ray->draw_start)
			*(unsigned int *)pixel = info->sky_color->color;
		else if (y < ray->draw_end)
		{
			tex_y = ((int)tex_pos) % ray->texture->h;
			tex_pos += step;
			int color = ft_get_pixel_color(ray->texture, ray->text_x, tex_y);
			ft_put_pixel_color(info->game, ray->x, y, color);
		}
		else
			*(unsigned int *)pixel = info->floor_color->color;
	}
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_interpolate_rays(t_info *info, t_lst_ray *list)
 * </summary>
 *
 * <description>
 * 	ft_
 * </description>
 *
 * <param type="t_info *" name="info">general structure</param>
 *
 * <return>
 * 	void.
 * </return>
 * 
 */
void	ft_draw_image(t_info *info, t_lst_ray *list)
{
	t_lst_ray	*current;
	t_lst_ray	*next;

	current = list;
	while (current && current->next)
	{
		next = current->next;
		ft_draw_column(info, &current->ray);
		current = next;
	}
}
