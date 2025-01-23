/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:57:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/23 09:13:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

int	ft_put_wall(t_img *wall, int y_start, int y_end, int y, int tex_x)
{
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
