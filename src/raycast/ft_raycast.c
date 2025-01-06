/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:45:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/06 13:57:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/structures.h"
#include "../../includes/error.h"

static void	draw_column(void *mlx, void *win, int x, int height, int color)
{
	int	y;

	y = (HEIGHT - height) / 2;
	while (y < (HEIGHT + height) / 2)
	{
        mlx_pixel_put(mlx, win, x, y, color);
		y++;
    }
}

void	ft_raycast(t_info *info)
{
	int		x;
	int		hit;
	double	ray_x;
	double	ray_y;
	double	distance;

	x = -1;
	while (++x < WIDTH)
	{
		ray_x = cos(info->user_deg);
		ray_y = sin(info->user_deg);
		distance = 0;
		hit = 0;
		while (!hit && distance < 1000)
		{
			distance += 0.1;
			int map_x = (int)((info->user_y + ray_x * distance) / info->w_n_img->size);
			int map_y = (int)((info->user_y + ray_y * distance) / info->w_n_img->size);
			if (info->map[map_y][map_x] == 1)
				hit = 1;
		}

		int wall_height = (int)(info->w_n_img->size / distance * 300);
		draw_column(info->mlx, info->game->win, x, wall_height, 0xFFFFFF / (distance * 0.1));
	}
	return ;
}