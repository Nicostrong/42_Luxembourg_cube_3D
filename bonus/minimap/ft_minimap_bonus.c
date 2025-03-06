/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/24 14:37:32 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_color(t_info *info, char *line)
 * </summary>
 *
 * <description>
 * 	ft_set_color set all color for a line.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="char *" name="line">line of minimap</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_set_color(t_info *info, char *line)
{
	int	index;

	index = -1;
	while (line[++index])
	{
		if (line[index] == '1')
			info->colors[index] = WALL;
		else if (ft_strchr("0PIJCOFA", line[index]))
			info->colors[index] = FLOOR;
		else
			info->colors[index] = EMPTY;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_img(t_info *info, char **map)
 * </summary>
 *
 * <description>
 * 	ft_set_img set all pixel of the image.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="char **" name="map">minimap array</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_set_img(t_info *info, t_mini *mini)
{
	mini->index_pxl = 0;
	mini->y = -1;
	while (++mini->y < info->mini_h)
	{
		ft_set_color(info, mini->map[mini->y]);
		mini->h = -1;
		while (++mini->h < (int)info->heights[mini->y])
		{
			mini->x = -1;
			while (++mini->x < info->mini_w)
			{
				mini->w = -1;
				while (++mini->w < (int)info->widths[mini->x])
				{
					if (!ft_put_door(info, mini))
						if (!ft_put_item(info, mini))
							*((unsigned int *) \
							(info->mini->addr + mini->index_pxl)) = \
							(unsigned int)info->colors[mini->x];
					mini->index_pxl += 4;
				}
			}
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_get_map_case(int coord, int *sizes, int max_value)
 * </summary>
 *
 * <description>
 * 	ft_get_map_case return the position of pixel on the map.
 * </description>
 *
 * <param type="int" name="coord">coordonnee of the point</param>
 * <param type="int *" name="sizes">array of sizes</param>
 * <param type="int" name="max_value">lenght of size array</param>
 *
 * <return>
 * 	the position in the array or -1 if out of array.
 * </return>
 *
 */
int	ft_get_map_case(int coord, int *sizes, int max_value)
{
	int	i;
	int	cumulative_size;

	i = -1;
	cumulative_size = 0;
	while (++i < max_value)
	{
		cumulative_size += sizes[i];
		if (coord < cumulative_size)
			return (i);
	}
	return (-1);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_minimap(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_minimap draw the minimap om the window minimap. The player is in the 
 *  center of the window. The function draw the ray of the vision.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
int	ft_minimap(t_info *info)
{
	t_mini	mini;

	if (!info->move)
		return (0);
	mlx_clear_window(info->mlx, info->mini->win);
	mini.map = ft_get_minimap(info);
	ft_get_widths(info);
	ft_get_heights(info);
	ft_set_img(info, &mini);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	if (MACOS && info->player->img)
		mlx_put_image_to_window(info->mlx, info->mini->win, \
			info->player->img, MINI_W / 2 - (MINI_S_PL / 2), \
			MINI_H / 2 - (MINI_S_PL / 2));
	else
		ft_put_player(info, info->player, MINI_W / 2, MINI_H / 2);
	ft_d_rmi(info, MINI_W / 2, MINI_H / 2, mini.map);
	ft_d_r(info, MINI_W / 2, MINI_H / 2, mini.map);
	ft_d_rma(info, MINI_W / 2, MINI_H / 2, mini.map);
	ft_free_array(mini.map);
	return (0);
}
