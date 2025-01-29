/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_item_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:28:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/29 11:33:22 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../includes/setting_game_bonus.h"

void	ft_put_item(t_info *info, int x, int y, char **map)
{
	if (map[y][x] == 'I' && \
		h > ((info->heights[y] / 2) - 4) && h < ((info->heights[y] / 2) + 4) && \
		w > ((info->widths[x] / 2) - 4) && w < ((info->widths[x] / 2) + 4))
		*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)ITEM;
		*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)DOOR;
	return ;
}
void	ft_put_door(t_info *info, int x, int y, char **map)
{
	if (map[y][x] == 'D' && \
		((x > 0 && map[y][x - 1] == '1') || \
		(x < info->mini_w && map[y][x + 1] == '1')) && \
		h > ((info->heights[y] / 2) - 2) && h < ((info->heights[y] / 2) + 2))
		*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)DOOR;
	else if (map[y][x] == 'D' && \
		((y > 0 && map[y - 1][x] == '1') || \
		(y < info->mini_h - 1 && map[y + 1][x] == '1')) && \
		w > ((info->widths[x] / 2) - 2) && w < ((info->widths[x] / 2) + 2))
		*((unsigned int *)(info->mini->addr + index_pxl)) = (unsigned int)DOOR;
	return ;
}