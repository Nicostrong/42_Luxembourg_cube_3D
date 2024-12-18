/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/18 11:47:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

void	ft_up(t_info *info)
{
	char	up_l;
	char	up;
	char	up_r;

	up_l = info->map[info->user_y - 1][info->user_x - 1];
	up = info->map[info->user_y - 1][info->user_x];
	up_r = info->map[info->user_y - 1][info->user_x + 1];
	if (info->pad_y > -5)
		info->pad_y--;
	else if (up_l == '0' && up == '0' && up_r == '0')
	{
		if (info->pad_y > -10)
			info->pad_y--;
		else
		{
			info->pad_y = 10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_y--;
			info->map[info->user_y][info->user_x] = 'P';
		}
	}
	else if (up_l == '0' && up == '0' && up_r == '1')
	{
		if (info->pad_x < 6)
		{
			if (info->pad_y > -10)
				info->pad_y--;
			else
			{
				info->pad_y = 10;
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
			if (info->pad_y > -10)
				info->pad_y--;
			else
			{
				info->pad_y = 10;
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
			if (info->pad_y > -10)
				info->pad_y--;
			else
			{
				info->pad_y = 10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y--;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	return ;
}

void	ft_down(t_info *info)
{
	char	down_l;
	char	down;
	char	down_r;

	down_l = info->map[info->user_y + 1][info->user_x - 1];
	down = info->map[info->user_y + 1][info->user_x];
	down_r = info->map[info->user_y + 1][info->user_x + 1];
	if (info->pad_y < 5)
		info->pad_y++;
	else if (down_l == '0' && down == '0' && down_r == '0')
	{
		if (info->pad_y < 10)
			info->pad_y++;
		else
		{
			info->pad_y = -10;
			info->map[info->user_y][info->user_x] = '0';
			info->user_y++;
			info->map[info->user_y][info->user_x] = 'P';
		}
	}
	else if (down_l == '0' && down == '0' && down_r == '1')
	{
		if (info->pad_x < 6)
		{
			if (info->pad_y < 10)
				info->pad_y++;
			else
			{
				info->pad_y = -10;
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
			if (info->pad_y < 10)
				info->pad_y++;
			else
			{
				info->pad_y = -10;
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
			if (info->pad_y < 10)
				info->pad_y++;
			else
			{
				info->pad_y = -10;
				info->map[info->user_y][info->user_x] = '0';
				info->user_y++;
				info->map[info->user_y][info->user_x] = 'P';
			}
		}
	}
	return ;
}

void	ft_left(t_info *info)
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

void	ft_right(t_info *info)
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