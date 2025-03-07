/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:44:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 17:52:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_data(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_data print all simple data in the main structure.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_print_data(t_info *info)
{
	printf("\tfd of the map: %d\n", info->fd);
	printf("\theight of the map: %d\n", info->h);
	printf("\twidth of the map: %d\n", info->w);
	printf("\tposition user_y: %.2f\n", info->user_y);
	printf("\tposition user_x: %.2f\n", info->user_x);
	printf("\trotation user_deg: %.2f\n", info->user_deg);
	if (info->p_nbr >= 0)
		printf("\tp_nbr: %d\n", info->p_nbr);
	if (info->map_path)
		printf("\tmap_path: %s\n", info->map_path);
	if (info->line)
		printf("\tline: %s\n", info->line);
	if (info->map)
	{
		printf(BBLUE"map:\n"RESET);
		ft_putstrarray(info->map);
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_wall(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_wall print all information of all wall in the main structure.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_print_wall(t_info *info)
{
	printf("\n******************************\n");
	printf(BGREEN"\tWALL\n"RESET);
	printf("******************************\n");
	if (info->w_n_img)
	{
		printf(BBLUE"w_n_img:\n"RESET);
		ft_print_img(info->w_n_img);
	}
	if (info->w_e_img)
	{
		printf(BBLUE"w_e_img:\n"RESET);
		ft_print_img(info->w_e_img);
	}
	if (info->w_s_img)
	{
		printf(BBLUE"w_s_img:\n"RESET);
		ft_print_img(info->w_s_img);
	}
	if (info->w_w_img)
	{
		printf(BBLUE"w_w_img:\n"RESET);
		ft_print_img(info->w_w_img);
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_sky_floor(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_sky_floor print all information about the sky and the floor.
 * 	It prints the sky and floor images and the sky and floor colors.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_print_sky_floor(t_info *info)
{
	if (info->s_img)
	{
		printf(BBLUE"s_img:\n"RESET);
		ft_print_img(info->s_img);
	}
	if (info->f_img)
	{
		printf(BBLUE"f_img:\n"RESET);
		ft_print_img(info->f_img);
	}
	if (info->floor_color)
	{
		printf(BBLUE"floor_color:\n"RESET);
		ft_print_color(info->floor_color);
	}
	if (info->sky_color)
	{
		printf(BBLUE"sky_color:\n"RESET);
		ft_print_color(info->sky_color);
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_info(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_info print all information about the info structure.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_info(t_info *info)
{
	printf("***************\n");
	printf(BBLUE"INFO STRUCTURE\n"RESET);
	printf("***************\n");
	if (!info)
	{
		printf(REDC"\tinfo is NULL\n"RESET);
		return ;
	}
	ft_print_data(info);
	ft_print_wall(info);
	ft_print_sky_floor(info);
	return ;
}
