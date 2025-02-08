/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_item_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:28:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/08 14:35:11 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_put_item(t_info *info, t_mini *mini)
 * </summary>
 *
 * <description>
 * 	ft_put_item check if the case of the minimap is a item and set a pixel to
 * 	draw a item. It draw a square of 8x8 pixels in the center of the case.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_mini *" name="mini">minimap structure</param>
 *
 * <return>
 * 	1 if the case is a item, 0 otherwise.
 * </return>
 *
 */
int	ft_put_item(t_info *info, t_mini *mini)
{
	if ((mini->map[mini->y][mini->x] == 'I' || \
		mini->map[mini->y][mini->x] == 'J') && \
		mini->h > ((info->heights[mini->y] / 2) - 4) && \
		mini->h < ((info->heights[mini->y] / 2) + 4) && \
		mini->w > ((info->widths[mini->x] / 2) - 4) && \
		mini->w < ((info->widths[mini->x] / 2) + 4))
	{
		*((unsigned int *)(info->mini->addr + \
			mini->index_pxl)) = (unsigned int)ITEM;
		return (1);
	}
	return (0);
}
