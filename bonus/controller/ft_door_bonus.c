/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:27:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/02 16:59:59 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_open_door(t_info *info, int dirx, int diry, int *open)
 * </summary>
 *
 * <description>
 * 	ft_check_open_door check if the player is near a door and open it.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="dirx">direction in x</param>
 * <param type="int" name="diry">direction in y</param>
 * <param type="int *" name="open">pointer to open the door</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_open_door(t_info *info, int dirx, int diry, int *open)
{
	if (info->map[(int)info->user_y + diry][(int)info->user_x + dirx] == 'C')
	{
		*open = 1;
		info->map[(int)info->user_y + diry][(int)info->user_x + dirx] = 'O';
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_open_door(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_open_door open the door if the player is near or on it.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_padx">new pad x of the player</param>
 * <param type="double" name="new_pady">new pad y of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_open_door(t_info *info)
{
	int		open;

	open = 0;
	if (info->map[(int)info->user_y][(int)info->user_x] == 'F')
	{
		open = 1;
		info->map[(int)info->user_y][(int)info->user_x] = 'A';
	}
	ft_check_open_door(info, 1, 0, &open);
	ft_check_open_door(info, -1, 0, &open);
	ft_check_open_door(info, 0, 1, &open);
	ft_check_open_door(info, 0, -1, &open);
	if (open)
	{
		printf("\n******************************\n");
		printf(GREENC"\tDOOR OPEN\n"RESET);
		printf("******************************\n");
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_close_door(t_info *info, int dirx, int diry, int *close)
 * </summary>
 *
 * <description>
 * 	ft_check_close_door check if the player is far from a door and close it.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="int" name="dirx">direction in x</param>
 * <param type="int" name="diry">direction in y</param>
 * <param type="int *" name="close">pointer to close the door</param>
 * 
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_close_door(t_info *info, int dirx, int diry, int *close)
{
	int	door_x;
	int	door_y;

	door_x = info->user_x + dirx;
	door_y = info->user_y + diry;
	if (info->map[door_y][door_x] == 'O')
	{
		if ((dirx != 0 && fabs(info->user_x - (info->x + 0.5)) < 0.05) || \
			(diry != 0 && fabs(info->user_y - (info->y + 0.5)) < 0.05))
		{
			*close = 1;
			info->map[door_y][door_x] = 'C';
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_close_door(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_close_door close the door when the player is far from it.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="double" name="new_padx">new pad x of the player</param>
 * <param type="double" name="new_pady">new pad y of the player</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_close_door(t_info *info)
{
	int	close;

	close = 0;
	ft_check_close_door(info, 1, 0, &close);
	ft_check_close_door(info, -1, 0, &close);
	ft_check_close_door(info, 0, 1, &close);
	ft_check_close_door(info, 0, -1, &close);
	if (close)
	{
		printf("\n******************************\n");
		printf(GREENC"\tDOOR CLOSE\n"RESET);
		printf("******************************\n");
	}
	return ;
}
