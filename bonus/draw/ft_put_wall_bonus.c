/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:57:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/04 10:31:31 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"

int	ft_put_wall(t_raycast *ray, int y, int x)
{
	double			texture_pos;
	int				texture_y;
	unsigned int	*texture_pixel;
	unsigned int	color;

	texture_pos = (double)(y - (-ray->line_height / 2 + HEIGHT / 2)) * ray->texture->h /ray->line_height;
	texture_y = (int)texture_pos & (ray->texture->h - 1);
	texture_pixel = (unsigned int *)ray->texture->addr;
	color = texture_pixel[ray->texture->w * texture_y + ray->text_x];
	
	int			tex_y;
	char		*pixel_ptr;
	uint32_t	color;

	tex_y = (y - y_start) * wall->h / (y_end - y_start);
	(void)tex_x;
	if (tex_y < 0) tex_y = 0;
	if (tex_y >= wall->h) tex_y = wall->h - 1;
	pixel_ptr = wall->addr + (tex_y * wall->size + 2 * (wall->bpp / 8));
	color = *(uint32_t *)pixel_ptr;
	return (color);
}


double texture_pos = (double)(y - (-ray->line_height / 2 + HEIGHT / 2)) * ray->texture->h / ray->line_height;
int texture_y = (int)texture_pos & (ray->texture->h - 1);
unsigned int *texture_pixels = (unsigned int *)ray->texture->addr;
unsigned int color = texture_pixels[ray->texture->w * texture_y + ray->text_x];

pixel = base_pixel + y * win->size;
*(unsigned int *)pixel = color;
