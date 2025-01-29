/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:09:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/29 11:15:07 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

static void	ft_print_intarray(int *a_int, char *name)
{
	int	i;

	i = -1;
	while (a_int[++i])
		printf("%s[%d]: %d\n", name, i, a_int[i]);
	return ;

}

static void	ft_print_mini_info(t_info *info)
{
	if (!info)
		return ;
	printf("\nHeight of minimap : %d\n", info->mini_h);
	printf("Width of minimap : %d\n", info->mini_w);
	return ;
}

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
	printf("******************************\n");
	printf(BBLUE"\tM I N I M A P\n"RESET);
	printf("******************************\n\n");
	if (map)
		ft_putstrarray(map);
	else
		printf(REDC"\tminimap is NULL\n"RESET);
	ft_print_mini_info(info);
	if (info && info->heights)
	{
		printf("\n\tHeights of minimap:\n");
		ft_print_intarray(info->heights, "heights");	
	}
	if (info && info->widths)
	{
		printf("\n\twidhts of minimap:\n");
		ft_print_intarray(info->widths, "widths");	
	}
	return ;
}
