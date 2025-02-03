/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_item_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:28:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/02 14:41:34 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"

int	ft_put_item(t_info *info, t_mini *mini)
{
	if ((mini->map[mini->y][mini->x] == 'I' || \
		mini->map[mini->y][mini->x] == 'J')  && \
		mini->h > ((info->heights[mini->y] / 2) - 4) && \
		mini->h < ((info->heights[mini->y] / 2) + 4) && \
		mini->w > ((info->widths[mini->x] / 2) - 4) && \
		mini->w < ((info->widths[mini->x] / 2) + 4))
	{
		*((unsigned int *)(info->mini->addr + mini->index_pxl)) = (unsigned int)ITEM;
		return (1);
	}
	return (0);
}
