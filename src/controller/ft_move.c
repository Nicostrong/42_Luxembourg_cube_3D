/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:13:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/16 12:51:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_update_position(t_info *info, int new_y, int new_x)
 * </summary>
 *
 * <description>
 * 	ft_update_position update the position of the player on the map array.
 * 	print the count of move made by the player.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 * <param type="int" name="new_y">new position in y</param>
 * <param type="int" name="new_x">new position in x</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

/*static void	ft_update_position(t_info *info, int new_y, int new_x)
{
	if (info->on_exit)
		info->map[info->y][info->x] = 'E';
	else
		info->map[info->y][info->x] = '0';
	info->on_exit = (info->map[new_y][new_x] == 'E');
	if (info->map[new_y][new_x] == 'C')
		info->c_nbr--;
	if (info->x < new_x)
		info->map[new_y][new_x] = 'P';
	else
		info->map[new_y][new_x] = 'L';
	info->y = new_y;
	info->x = new_x;
	info->move_cnt++;
	ft_putstr_fd("Move count : ", 1);
	ft_putnbr_fd(info->move_cnt, 1);
	ft_putchar_fd('\n', 1);
	ft_draw_map(info);
}*/

static void	ft_move(t_info *info, int dx, int dy)
{
	char	box_l;
	char	box;
	char	box_r;

	box_l = info->map[info->user_y - 1][info->user_x - 1];
	box = info->map[info->user_y - 1][info->user_x];
	box_r = info->map[info->user_y - 1][info->user_x + 1];
	if (info->pad_y < 5)
		info->pad_y++;
	else if (box_l == '0' && box == '0' && box_r == '0')
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
	else if (box_l == '0' && box == '0' && box_r == '1')
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
	else if (box_l == '1' && box == '0' && box_r == '0')
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
	else if (box_l == '1' && box == '0' && box_r == '1')
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
	ft_render(info);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_key_press(int key, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_key_press catch the key pressed by the player and call the function 
 * 	ft_move to change the position of the player on the map.
 * 	after each move, it call ft_draw_map to print the new map on the screen.
 * </description>
 *
 * <param type="int" name="key">value of the key pressed on the keyboard</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	1 if the map is updated or 0.
 * </return>
 *
 */

int	ft_press_key(int key, t_info *info)
{
	if (key == XK_Up || key == XK_w)
		ft_move(info, -1, 0);
	else if (key == XK_Left || key == XK_a)
		ft_move(info, 0, -1);
	else if (key == XK_Down || key == XK_s)
		ft_move(info, 1, 0);
	else if (key == XK_Right || key == XK_d)
		ft_move(info, 0, 1);
	/*else if (key == XK_q)
		ft_rotate(info, -5);
	else if (key == XK_e)
		ft_rotate(info, 5);
	*/else if (key == XK_Escape)
		ft_exit(info);
	else
		return (0);
	ft_print_user_data(info);
	return (1);
}