/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/16 12:36:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

void	ft_render(t_info *info)
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
			if (info->map[y][x] && (info->map[y][x] == '0' || info->map[y][x] == 'P'))
				color = 0x7F7F7F;	//	Gray
			else if (info->map[y][x] && info->map[y][x] == '1')
				color = 0xFF0000;	//	Red
			else
				color = 0xFFFFFF;	//	White
			for (int dy = 0; dy < 42; ++dy)
			{
				for (int dx = 0; dx < 42; ++dx)
				{
					int pixel_index = (((yy * 42) + dy + oy) * info->win_m->size_line) \
						+ (((xx * 42) + dx - ox) * (info->win_m->bpp / 8));
					info->win_m->addr[pixel_index] = color & 0xFF;
					info->win_m->addr[pixel_index + 1] = (color >> 8) & 0xFF;
					info->win_m->addr[pixel_index + 2] = (color >> 16) & 0xFF;
				}
			}
			xx++;
		}
		yy++;
	}
	ft_put_circle(info, MINI_W / 2, MINI_H / 2);
	mlx_put_image_to_window(info->mlx, info->win_m->win, info->win_m->img, 0, 0);
}

static void	ft_up(t_info *info)
{
	char	up_l;
	char	up;
	char	up_r;

	up_l = info->map[info->user_y - 1][info->user_x - 1];
	up = info->map[info->user_y - 1][info->user_x];
	up_r = info->map[info->user_y - 1][info->user_x + 1];
	if (info->pad_y < 5)
		info->pad_y++;
	else if (up_l == '0' && up == '0' && up_r == '0')
	{
		if (info->pad_y < 10)
			info->pad_y++;
		else
		{
			info->pad_y = -10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_y--;
			info->map[info->user_y][info->user_x] = 'P';
		}
	}
	else if (up_l == '0' && up == '0' && up_r == '1')
	{
		if (info->pad_x < 6)
		{
			if (info->pad_y < 10)
				info->pad_y++;
			else
			{
				info->pad_y = -10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y--;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (up_l == '1' && up == '0' && up_r == '0')
	{
		if (info->pad_x > -6)
		{
			if (info->pad_y < 10)
				info->pad_y++;
			else
			{
				info->pad_y = -10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y--;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (up_l == '1' && up == '0' && up_r == '1')
	{
		if (info->pad_x > -6 && info->pad_x < 6)
		{
			if (info->pad_y < 10)
				info->pad_y++;
			else
			{
				info->pad_y = -10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y--;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	return ;
}

static void	ft_down(t_info *info)
{
	char	down_l;
	char	down;
	char	down_r;

	down_l = info->map[info->user_y + 1][info->user_x - 1];
	down = info->map[info->user_y + 1][info->user_x];
	down_r = info->map[info->user_y + 1][info->user_x + 1];
	if (info->pad_y > -5)
		info->pad_y--;
	else if (down_l == '0' && down == '0' && down_r == '0')
	{
		if (info->pad_y > -10)
			info->pad_y--;
		else
		{
			info->pad_y = 10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_y++;
			info->map[info->user_y][info->user_x] = 'P';
		}
	}
	else if (down_l == '0' && down == '0' && down_r == '1')
	{
		if (info->pad_x < 6)
		{
			if (info->pad_y > -10)
				info->pad_y--;
			else
			{
				info->pad_y = 10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y++;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (down_l == '1' && down == '0' && down_r == '0')
	{
		if (info->pad_x > -6)
		{
			if (info->pad_y > -10)
				info->pad_y--;
			else
			{
				info->pad_y = 10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y++;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (down_l == '1' && down == '0' && down_r == '1')
	{
		if (info->pad_x > -6 && info->pad_x < 6)
		{
			if (info->pad_y > -10)
				info->pad_y--;
			else
			{
				info->pad_y = 10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y++;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	return ;
}

static void	ft_left(t_info *info)
{
	char	left_u;
	char	left;
	char	left_d;

	left_u = info->map[info->user_y - 1][info->user_x - 1];
	left = info->map[info->user_y][info->user_x - 1];
	left_d = info->map[info->user_y + 1][info->user_x - 1];
	if (info->pad_x > -5)
		info->pad_x--;
	else if (left_u == '0' && left == '0' && left_d == '0')
	{
		if (info->pad_x > -10)
			info->pad_x--;
		else
		{
			info->pad_x = 10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_x--;
			info->map[info->user_y][info->user_x] = 'P';
		}
	}
	else if (left_u == '0' && left == '0' && left_d == '1')
	{
		if (info->pad_y > -6)
		{
			if (info->pad_x > -10)
				info->pad_x--;
			else
			{
				info->pad_x = 10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_x--;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (left_u == '1' && left == '0' && left_d == '0')
	{
		if (info->pad_y < 6)
		{
			if (info->pad_x > -10)
				info->pad_x--;
			else
			{
				info->pad_x = 10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_x--;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (left_u == '1' && left == '0' && left_d == '1')
	{
		if (info->pad_y > -6 && info->pad_y < 6)
		{
			if (info->pad_x > -10)
				info->pad_x--;
			else
			{
				info->pad_x = 10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_x--;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	return ;
}

static void	ft_right(t_info *info)
{
	char	right_u;
	char	right;
	char	right_d;

	right_u = info->map[info->user_y - 1][info->user_x + 1];
	right = info->map[info->user_y][info->user_x + 1];
	right_d = info->map[info->user_y + 1][info->user_x + 1];
	if (info->pad_x < 5)
		info->pad_x++;
	else if (right_u == '0' && right == '0' && right_d == '0')
	{
		if (info->pad_x < 10)
			info->pad_x++;
		else
		{
			info->pad_x = -10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_x++;
			info->map[info->user_y][info->user_x] = 'P';
		}
	}
	else if (right_u == '0' && right == '0' && right_d == '1')
	{
		if (info->pad_y > -6)
		{
			if (info->pad_x < 10)
				info->pad_x++;
			else
			{
				info->pad_x = -10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_x++;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (right_u == '1' && right == '0' && right_d == '0')
	{
		if (info->pad_y < 6)
		{
			if (info->pad_x < 10)
				info->pad_x++;
			else
			{
				info->pad_x = -10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_x++;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	else if (right_u == '1' && right == '0' && right_d == '1')
	{
		if (info->pad_y > -6 && info->pad_y < 6)
		{
			if (info->pad_x < 10)
				info->pad_x++;
			else
			{
				info->pad_x = -10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_x++;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	return ;
}

int	ft_press_key(int keysym, t_info *info)
{
	if (keysym == XK_Escape)
		ft_exit(info);
	else if (keysym == XK_Up || keysym == XK_w)
		ft_up(info);
	else if (keysym == XK_Down || keysym == XK_s)
		ft_down(info);
	else if (keysym == XK_Left || keysym == XK_a)
		ft_left(info);
	else if (keysym == XK_Right || keysym == XK_d)
		ft_right(info);
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
	//ft_print_map(info);
	ft_render(info);
	return (0);
}