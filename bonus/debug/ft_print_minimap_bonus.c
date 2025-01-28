/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:09:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/28 09:46:15 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_map(t_info *info, char **map)
 * </summary>
 *
 * <description>
 * 	ft_print_map print the map.
 * </description>
 *
 * <param type="t_info" name="info">the structure with all information</param>
 * <param type="char **" name="map">array of minimap</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_minimap(t_info *info, char **map)
{
	int	i;

	printf("******************************\n");
	printf(BBLUE"\tM I N I M A P\n"RESET);
	printf("******************************\n");
	if (map)
		ft_putstrarray(map);
	else
		printf(REDC"\tminimap is NULL\n"RESET);
	if (info && info->heights)
	{
		printf("\tHeights of minimap:\n");
		i = -1;
		while (info->heights[++i])
			printf("heighs[%d]: %d\n", i, info->heights[i]);	
	}
	if (info && info->widths)
	{
		printf("\twidhts of minimap:\n");
		i = -1;
		while (info->widths[++i])
			printf("widths[%d]: %d\n", i, info->widths[i]);
	}
	return ;
}
