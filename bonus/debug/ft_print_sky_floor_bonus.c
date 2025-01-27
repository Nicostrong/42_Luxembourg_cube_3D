/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sky_floor_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:20:39 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 13:03:44 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_sky(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_sky print all information about the sky.
 * 	It prints the sky images and the sky colors.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_print_sky(t_info *info)
{
	if (info->s_img)
	{
		printf(BBLUE"s_img:\n"RESET);
		ft_print_img(info->s_img);
	}
	if (info->use_s_img)
		printf(GREENC"\tuse Sky texture\n"RESET);
	if (info->sky_color)
	{
		printf(BBLUE"sky_color:\n"RESET);
		ft_print_color(info->sky_color);
	}
	if (!info->use_s_img)
		printf(GREENC"\tuse Sky color\n"RESET);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_print_floor(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_floor print all information about the floor.
 * 	It prints the floor images and the floor colors.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_print_floor(t_info *info)
{
	if (info->f_img)
	{
		printf(BBLUE"f_img:\n"RESET);
		ft_print_img(info->f_img);
	}
	if (info->use_f_img)
		printf(GREENC"\tuse Floor texture\n"RESET);
	if (info->floor_color)
	{
		printf(BBLUE"floorcolor:\n"RESET);
		ft_print_color(info->floor_color);
	}
	if (!info->use_f_img)
		printf(GREENC"\tuse Floor color\n"RESET);
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
 * 	It prints the sky and the floor images and the sky and the floor colors.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_print_sky_floor(t_info *info)
{
	printf("***************\n");
	printf(BGREEN"SKY\n"RESET);
	printf("***************\n");
	ft_print_sky(info);
	printf("***************\n");
	printf(BGREEN"FLOOR\n"RESET);
	printf("***************\n");
	ft_print_floor(info);
	return ;
}

