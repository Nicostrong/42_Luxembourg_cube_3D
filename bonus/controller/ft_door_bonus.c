/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:27:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/31 15:13:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"

void	ft_open_door(t_info *info)
{
	printf("\n******************************\n");
	printf(GREENC"\tDOOR OPEN\n"RESET);
	printf("******************************\n");
	if (info->map[(int)info->user_y][(int)info->user_x + 1] == 'C')
		info->map[(int)info->user_y][(int)info->user_x + 1] = 'O';
	else if (info->map[(int)info->user_y][(int)info->user_x - 1] == 'C')
		info->map[(int)info->user_y][(int)info->user_x - 1] = 'O';
	else if (info->map[(int)info->user_y + 1][(int)info->user_x] == 'C')
		info->map[(int)info->user_y + 1][(int)info->user_x] = 'O';
	else if (info->map[(int)info->user_y - 1][(int)info->user_x] == 'C')
		info->map[(int)info->user_y - 1][(int)info->user_x] = 'O';
	return ;
}
