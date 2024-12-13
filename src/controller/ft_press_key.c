/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/13 13:34:40 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

static void	ft_render(t_info *info)
{
	int	x, xx, y, yy, color;
	int	ox = info->pad_x * 2;
	int oy = info->pad_y * 2;

	y = (info->user_y - 3);
	yy = 0;
	while (++y <= (info->user_y + 2))
	{
		x = (info->user_x - 4);
		xx = 0;
		while (++x <= (info->user_x + 3))
		{
			if (!info->map[y][x] || info->map[y][x] == '0' )
				color = 0x7F7F7F;	//	Gray
			else if (info->map[y][x] == '1')
				color = 0xFF0000;	//	Red
			/*else if (info->map[y][x] == 'P')
				color = 0x7F0000FF;	//	Blue
			*/else
				color = 0xFFFFFF;	//	White
			for (int dy = 0; dy < 42; ++dy)
			{
				for (int dx = 0; dx < 42; ++dx)
				{
					int pixel_index = ((yy * 42 + dy + oy) * info->win_m->size_line) \
						+ ((xx * 42 + dx + ox) * (info->win_m->bpp / 8));
					info->win_m->addr[pixel_index] = color & 0xFF;
					info->win_m->addr[pixel_index + 1] = (color >> 8) & 0xFF;
					info->win_m->addr[pixel_index + 2] = (color >> 16) & 0xFF;
				}
			}
			xx++;
		}
		yy++;
	}
	ft_put_circle(info, 42 * 3 + info->pad_x * 2, 42 * 3 + info->pad_y * 2);
	mlx_put_image_to_window(info->mlx, info->win_m->win, info->win_m->img, 0, 0);
}

int	ft_press_key(int keysym, t_info *info)
{
	if (keysym == XK_Escape)
		ft_exit(info);
	else if (keysym == XK_Up || keysym == XK_w)
	{
		if (!ft_strcmp(&info->map[info->user_y - 1][info->user_x], "1"))
		{
			if (info->pad_y < 5)
				info->pad_y++;
			else
				return (0);
		}
		else if (info->pad_y == 10)
		{
			info->pad_y = -10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_y--;
			info->map[info->user_y][info->user_x] = 'P';
		}
		else
			info->pad_y++;
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		if (!ft_strcmp(&info->map[info->user_y + 1][info->user_x], "1"))
		{
			if (info->pad_y > -5)
				info->pad_y--;
			else
				return (0);
		}
		else if (info->pad_y == -10)
		{
			info->pad_y = 10;

			info->map[info->user_y][info->user_x] = '0';
			info->user_y++;
			info->map[info->user_y][info->user_x] = 'P';
		}
		else
			info->pad_y--;
	}
	else if (keysym == XK_Left || keysym == XK_a)
	{
		if (!ft_strcmp(&info->map[info->user_y][info->user_x - 1], "1"))
		{
			if (info->pad_x > -5)
				info->pad_x--;
			else
				return (0);
		}
		else if (info->pad_x == -10)
		{
			info->pad_x = 10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_x--;
			info->map[info->user_y][info->user_x] = 'P';
		}
		else
			info->pad_x--;
	}
	else if (keysym == XK_Right || keysym == XK_d)
	{
		if (!ft_strcmp(&info->map[info->user_y][info->user_x + 1], "1"))
		{
			if (info->pad_x < 5)
				info->pad_x++;
			else
				return (0);
		}
		else if (info->pad_x == 10)
		{
			info->pad_x = -10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_x++;
			info->map[info->user_y][info->user_x] = 'P';
		}
		else
			info->pad_x++;
	}
	else if (keysym == XK_q)
		info->user_deg -= 5;
	else if (keysym == XK_e)
		info->user_deg += 5;
	else if (keysym == XK_space)
		printf("jump\n");
	if (info->user_deg < 0)
		info->user_deg += 360;
	else if (info->user_deg >= 360)
		info->user_deg -= 360;
	ft_print_user_data(info);
	ft_render(info);
	return (0);
}