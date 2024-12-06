/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:44:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/06 13:16:37 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"

void	ft_print_info(t_info *info)
{
	printf("INFO STRUCTURE\n");
	if (!info)
	{
		printf("info is NULL\n");
		return ;
	}
	if (info->fd > 0)
		printf("fd: %d\n", info->fd);
	if (info->h >= 0)
		printf("h: %d\n", info->h);
	if (info->w >= 0)
		printf("w: %d\n", info->w);
	if (info->user_y >= 0)
		printf("user_y: %d\n", info->user_y);
	if (info->user_x >= 0)
		printf("user_x: %d\n", info->user_x);
	if (info->user_deg >= 0)
		printf("user_deg: %d\n", info->user_deg);
	if (info->c_fund >= 0)
		printf("c_fund: %d\n", info->c_fund);
	if (info->move_nbr >= 0)
		printf("move_nbr: %d\n", info->move_nbr);
	if (info->p_nbr >= 0)
		printf("p_nbr: %d\n", info->p_nbr);
	if (info->map_path)
		printf("map_path: %s\n", info->map_path);
	if (info->line)
		printf("line: %s\n", info->line);
	if (info->map)
	{
		printf("map:\n");
		ft_putstrarray(info->map);
	}
	if (info->w_n_img)
	{
		printf("w_n_img:\n");
		printf("path: %s\n", info->w_n_img->img_path);
		printf("h: %d\n", info->w_n_img->h);
		printf("w: %d\n", info->w_n_img->w);
	}
	if (info->w_e_img)
	{
		printf("w_e_img:\n");
		printf("path: %s\n", info->w_e_img->img_path);
		printf("h: %d\n", info->w_e_img->h);
		printf("w: %d\n", info->w_e_img->w);
	}
	if (info->w_s_img)
	{
		printf("w_s_img:\n");
		printf("path: %s\n", info->w_s_img->img_path);
		printf("h: %d\n", info->w_s_img->h);
		printf("w: %d\n", info->w_s_img->w);
	}
	if (info->w_w_img)
	{
		printf("w_w_img:\n");
		printf("path: %s\n", info->w_w_img->img_path);
		printf("h: %d\n", info->w_w_img->h);
		printf("w: %d\n", info->w_w_img->w);
	}
	if (info->s_img)
	{
		printf("s_img:\n");
		printf("path: %s\n", info->s_img->img_path);
		printf("h: %d\n", info->s_img->h);
		printf("w: %d\n", info->s_img->w);
	}
	if (info->f_img)
	{
		printf("f_img:\n");
		printf("path: %s\n", info->f_img->img_path);
		printf("h: %d\n", info->f_img->h);
		printf("w: %d\n", info->f_img->w);
	}
	if (info->floor_color)
	{
		printf("floor_color:\n");
		printf("r: %d\n", info->floor_color->r);
		printf("g: %d\n", info->floor_color->g);
		printf("b: %d\n", info->floor_color->b);
		printf("path: %s\n", info->f_img->img_path);
	}
	if (info->sky_color)
	{
		printf("sky_color:\n");
		printf("r: %d\n", info->sky_color->r);
		printf("g: %d\n", info->sky_color->g);
		printf("b: %d\n", info->sky_color->b);
		printf("path: %s\n", info->s_img->img_path);
	}
	
}