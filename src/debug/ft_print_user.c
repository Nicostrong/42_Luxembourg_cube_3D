/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_user.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:21:03 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/23 15:46:39 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_user_data(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_user_data print all information about the user.
 * </description>
 *
 * <param type="t_info" name="info">The structure with all information</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_user_data(t_info *info)
{
	printf("***************\n");
	printf(BGOLD"USER DATA\n"RESET);
	printf("***************\n");
	printf("\tfd of the map: %d\n", info->fd);
	printf("\theight of the map: %d\n", info->h);
	printf("\twidth of the map: %d\n", info->w);
	printf("\tcase user X: %d\n", info->x);
	printf("\tcase user Y: %d\n", info->y);
	printf("\tposition user_x: %.2f\n", info->user_x);
	printf("\tposition user_y: %.2f\n", info->user_y);
	printf("\trotation user_deg: %.2f\n", info->user_deg);
	return ;
}
