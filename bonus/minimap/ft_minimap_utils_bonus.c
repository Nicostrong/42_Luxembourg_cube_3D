/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:19:44 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 18:05:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	char	**ft_init_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_map create an array with the good dimmension.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	the map array empty.
 * </return>
 *
 */
static char	**ft_init_map(t_info *info)
{
	char	**map;

	info->mini_h = 5;
	if (fabs(info->user_y - info->y) != 0.5)
		info->mini_h = 6;
	info->mini_w = 7;
	if (fabs(info->user_x - info->x) != 0.5)
		info->mini_w = 8;
	map = ft_calloc(info->mini_h + 1, sizeof(char *));
	if (!map)
		ft_perror_exit(E_MALLOC, info);
	return (map);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	char	**ft_get_minimap(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_minimap create the array for the minimap with the player in center of
 *  the map.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	the minimap array with value.
 * </return>
 *
 */
char	**ft_get_minimap(t_info *info)
{
	char	**map;
	char	*s;
	int		i;

	map = ft_init_map(info);
	i = -1;
	while (++i < info->mini_h)
	{
		if ((info->user_y - info->y) >= 0.5 && \
			(info->y - 2 + i) >= 0 && \
			(info->y - 2 + i) < info->h)
			s = info->map[info->y - 2 + i];
		else if ((info->user_y - info->y) < 0.5 && \
			(info->y - 3 + i) >= 0 && \
			(info->y - 3 + i) < info->h)
			s = info->map[info->y - 3 + i];
		else
			s = NULL;
		if ((info->user_x - info->x) < 0.5)
			map[i] = ft_formatsubstr(s, info->x - 4, info->mini_w, '*');
		else
			map[i] = ft_formatsubstr(s, info->x - 3, info->mini_w, '*');
	}
	return (map);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_heights(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_heights set an int array with all value of height.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_get_heights(t_info *info)
{
	int		i;
	double	offset;

	if ((info->user_y - info->y) <= 0.5)
		offset = 20 + (int)(40 * (info->user_y - info->y));
	else
		offset = 60 - (int)(40 * (info->user_y - info->y));
	i = -1;
	while (++i < 6)
		info->heights[i] = MINI_S_BLOC;
	if ((info->user_y - info->y) > 0.5)
	{
		info->heights[0] = (int)offset;
		info->heights[5] = MINI_S_BLOC - (int)offset;
	}
	else if ((info->user_y - info->y) < 0.5)
	{
		info->heights[0] = MINI_S_BLOC - (int)offset;
		info->heights[5] = (int)offset;
	}
	else
		info->heights[5] = 0;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_widths(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_widths set an int array with all value of width.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_get_widths(t_info *info)
{
	int		i;
	double	offset;

	if ((info->user_x - info->x) <= 0.5)
		offset = 20 + (int)(40 * (info->user_x - info->x));
	else
		offset = 60 - (int)(40 * (info->user_x - info->x));
	i = -1;
	while (++i < 8)
		info->widths[i] = MINI_S_BLOC;
	if ((info->user_x - info->x) > 0.5)
	{
		info->widths[0] = (int)offset;
		info->widths[7] = MINI_S_BLOC - (int)offset;
	}
	else if ((info->user_x - info->x) < 0.5)
	{
		info->widths[0] = MINI_S_BLOC - (int)offset;
		info->widths[7] = (int)offset;
	}
	else
		info->widths[7] = 0;
	return ;
}
