/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:42 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/03 07:36:26 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_door_is_close(t_info *info, t_mini *mini)
 * </summary>
 *
 * <description>
 * 	ft_door_is_close check if the case of the minimap is a close door and set a 
 * 	pixel to draw a closed door.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_mini *" name="mini">minimap structure</param>
 *
 * <return>
 * 	1 if the case is a door, 0 otherwise.
 * </return>
 *
 */
int	ft_door_is_close(t_info *info, t_mini *mini)
{
	if ((mini->map[mini->y][mini->x] == 'C' || \
		mini->map[mini->y][mini->x] == 'F') && \
		((mini->x > 0 && mini->map[mini->y][mini->x - 1] == '1') || \
		(mini->x < info->mini_w && mini->map[mini->y][mini->x + 1] == '1')) && \
		mini->h > ((info->heights[mini->y] / 2) - 2) && \
		mini->h < ((info->heights[mini->y] / 2) + 2))
	{
		*((unsigned int *)(info->mini->addr + mini->index_pxl)) = (unsigned int)DOOR;
		return (1);
	}
	else if ((mini->map[mini->y][mini->x] == 'C' || \
		mini->map[mini->y][mini->x] == 'F') && \
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

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_door_is_open(t_info *info, t_mini *mini)
 * </summary>
 *
 * <description>
 * 	ft_door_is_open check if the case of the minimap is a open door and set a 
 * 	pixel to draw a open door.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_mini *" name="mini">minimap structure</param>
 *
 * <return>
 * 	1 if the case is a door, 0 otherwise.
 * </return>
 *
 */
int	ft_door_is_open(t_info *info, t_mini *mini)
{
	if ((mini->map[mini->y][mini->x] == 'O' || \
		mini->map[mini->y][mini->x] == 'A') && \
		((mini->x > 0 && mini->map[mini->y][mini->x - 1] == '1') || \
		(mini->x < info->mini_w && mini->map[mini->y][mini->x + 1] == '1')) && \
		mini->w < 3)
	{
		*((unsigned int *)(info->mini->addr + mini->index_pxl)) = (unsigned int)DOOR;
		return (1);
	}
	else if ((mini->map[mini->y][mini->x] == 'O' || \
		mini->map[mini->y][mini->x] == 'A') && \
		((mini->y > 0 && mini->map[mini->y - 1][mini->x] == '1') || \
		(mini->y < info->mini_h - 1 && \
		mini->map[mini->y + 1][mini->x] == '1')) && mini->h < 3)
	{
		*((unsigned int *)(info->mini->addr + mini->index_pxl)) = (unsigned int)DOOR;
		return (1);
	}
	return (0);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_put_door(t_info *info, t_mini *mini)
 * </summary>
 *
 * <description>
 * 	ft_put_door check if the case of the minimap is a door and set a pixel to
 * 	draw a door open or closed.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="t_mini *" name="mini">minimap structure</param>
 *
 * <return>
 * 	1 if the case is a door, 0 otherwise.
 * </return>
 *
 */
int	ft_put_door(t_info *info, t_mini *mini)
{
	int	ret;

	ret = 0;
	ret = ft_door_is_close(info, mini);
	if (ret)
		return (ret);
	ret = ft_door_is_open(info, mini);
	return (ret);
}
