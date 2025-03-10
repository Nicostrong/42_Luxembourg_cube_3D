/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:20:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_map print the map.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_map(t_info *info)
{
	printf("******************************\n");
	printf(BBLUE"\tM A P\n"RESET);
	printf("******************************\n");
	if (info->map)
		ft_putstrarray(info->map);
	else
		printf(REDC"\tmap is NULL\n"RESET);
	return ;
}
