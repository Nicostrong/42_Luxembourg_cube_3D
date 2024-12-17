/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:03:57 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/17 18:12:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

void	ft_print_box(t_info *info, int x, int y, int color)
{
	//int	ox;
	//int	oy;
	int	dx;
	int	dy;
	int	px;
	int	py;
	int	pixel_index;
	int	size;
	int	bpp;

	//ox = (info->pad_x * 2) + 21;
	//oy = (info->pad_y * 2) + 21;
	size = info->win_m->size_line;
	bpp = info->win_m->bpp / 8;
	dy = -1;
	while (++dy < 42)
	{
		py = (y * 42) + dy; // + oy;
		if (py < 0 || py >= MINI_H)
			continue ;
		dx = -1;
		while (++dx < 42)
		{
			px = (x * 42) + dx; // + ox;
			if (px < 0 || px >= MINI_W)
				continue ;
			pixel_index = (py * size) + (px  * bpp);
			info->win_m->addr[pixel_index] = color & 0xFF;
			info->win_m->addr[pixel_index + 1] = (color >> 8) & 0xFF;
			info->win_m->addr[pixel_index + 2] = (color >> 16) & 0xFF;
		}
	}
}

void	ft_render(t_info *info)
{
	int	x, xx, y, yy, color;

	y = (info->user_y - 2);
	yy = 0;
	while (y <= (info->user_y + 2))
	{
		xx = 0;
		x = (info->user_x - 3);
		while (x <= (info->user_x + 3))
		{
			if (x < 0 || y < 0 || x >= MINI_W || y >= MINI_H)
				color = 0xFF0000;	//	Red
			else if (info->map[y][x] && (info->map[y][x] == '0' || info->map[y][x] == 'P'))
				color = 0x7F7F7F;	//	Gray
			else if (info->map[y][x] && (info->map[y][x] == '1'))
				color = 0x0000FF;	//	Blue
			else
				color = 0x000000;	//	Black
			color = 0x0000FF;
			ft_print_box(info, xx, yy, color);
			xx++;
			x++;
		}
		yy++;
		y++;
	}
	//ft_print_box(info, 3, 4, 0xFF0000);
	mlx_put_image_to_window(info->mlx, info->win_m->win, info->win_m->img, 0, 0);
	if (info->player)
		mlx_put_image_to_window(info->mlx, info->win_m->win, info->player->img, (MINI_W / 2) - 21, (MINI_H / 2) - 21);
	else
		ft_put_circle(info, MINI_W / 2, MINI_H / 2);
}

				/*int pixel_index = (((yy * 42) + dy + oy) * info->win_m->size_line) \
					+ (((xx * 42) + dx - ox) * (info->win_m->bpp / 8));
				info->win_m->addr[pixel_index] = color & 0xFF;
				info->win_m->addr[pixel_index + 1] = (color >> 8) & 0xFF;
				info->win_m->addr[pixel_index + 2] = (color >> 16) & 0xFF;*/