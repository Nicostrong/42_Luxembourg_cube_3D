/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:42 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/30 11:06:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"

int	ft_put_door(t_info *info, t_mini *mini)
{
	if (mini->map[mini->y][mini->x] == 'C' && \
		((mini->x > 0 && mini->map[mini->y][mini->x - 1] == '1') || \
		(mini->x < info->mini_w && mini->map[mini->y][mini->x + 1] == '1')) && \
		mini->h > ((info->heights[mini->y] / 2) - 2) && \
		mini->h < ((info->heights[mini->y] / 2) + 2))
	{
		*((unsigned int *)(info->mini->addr + mini->index_pxl)) = (unsigned int)DOOR;
		return (1);
	}
	else if (mini->map[mini->y][mini->x] == 'C' && \
		((mini->y > 0 && mini->map[mini->y - 1][mini->x] == '1') || \
		(mini->y < info->mini_h - 1 && \
		mini->map[mini->y + 1][mini->x] == '1')) && \
		mini->w > ((info->widths[mini->x] / 2) - 2) && \
		mini->w < ((info->widths[mini->x] / 2) + 2))
	{
		*((unsigned int *)(info->mini->addr + mini->index_pxl)) = (unsigned int)DOOR;
		return (1);
	}
	return (0);
}
