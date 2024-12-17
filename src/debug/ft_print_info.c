/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:44:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/17 15:46:58 by nfordoxc         ###   Luxembourg.lu     */
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
	printf("fd of the map: %d\n", info->fd);
	printf("height of the map: %d\n", info->h);
	printf("width of the map: %d\n", info->w);
	printf("position user_y: %d\n", info->user_y);
	printf("position user_x: %d\n", info->user_x);
	printf("rotation user_deg: %d\n", info->user_deg);
	printf("position on cell pad_x: %d\n", info->pad_x);
	printf("position on cell pad_y: %d\n", info->pad_y);
	/*if (info->c_fund >= 0)
		printf("c_fund: %d\n", info->c_fund);
	if (info->move_nbr >= 0)
		printf("move_nbr: %d\n", info->move_nbr);*/
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
		printf("img: %p\n", info->w_n_img->img);
		printf("addr: %p\n", info->w_n_img->addr);
	}
	if (info->w_e_img)
	{
		printf("w_e_img:\n");
		printf("path: %s\n", info->w_e_img->img_path);
		printf("h: %d\n", info->w_e_img->h);
		printf("w: %d\n", info->w_e_img->w);
		printf("img: %p\n", info->w_e_img->img);
		printf("addr: %p\n", info->w_e_img->addr);
	}
	if (info->w_s_img)
	{
		printf("w_s_img:\n");
		printf("path: %s\n", info->w_s_img->img_path);
		printf("h: %d\n", info->w_s_img->h);
		printf("w: %d\n", info->w_s_img->w);
		printf("img: %p\n", info->w_s_img->img);
		printf("addr: %p\n", info->w_s_img->addr);
	}
	if (info->w_w_img)
	{
		printf("w_w_img:\n");
		printf("path: %s\n", info->w_w_img->img_path);
		printf("h: %d\n", info->w_w_img->h);
		printf("w: %d\n", info->w_w_img->w);
		printf("img: %p\n", info->w_w_img->img);
		printf("addr: %p\n", info->w_w_img->addr);
	}
	if (info->s_img)
	{
		printf("s_img:\n");
		printf("path: %s\n", info->s_img->img_path);
		printf("h: %d\n", info->s_img->h);
		printf("w: %d\n", info->s_img->w);
		printf("img: %p\n", info->s_img->img);
		printf("addr: %p\n", info->s_img->addr);
	}
	if (info->f_img)
	{
		printf("f_img:\n");
		printf("path: %s\n", info->f_img->img_path);
		printf("h: %d\n", info->f_img->h);
		printf("w: %d\n", info->f_img->w);
		printf("img: %p\n", info->f_img->img);
		printf("addr: %p\n", info->f_img->addr);
	}
	if (info->floor_color)
	{
		printf("floor_color:\n");
		printf("r: %d\n", info->floor_color->r);
		printf("g: %d\n", info->floor_color->g);
		printf("b: %d\n", info->floor_color->b);
	}
	if (info->sky_color)
	{
		printf("sky_color:\n");
		printf("r: %d\n", info->sky_color->r);
		printf("g: %d\n", info->sky_color->g);
		printf("b: %d\n", info->sky_color->b);
	}
	if (info->player)
	{
		printf("player_img:\n");
		printf("path: %s\n", info->player->img_path);
		printf("h: %d\n", info->player->h);
		printf("w: %d\n", info->player->w);
		printf("img: %p\n", info->player->img);
		printf("addr: %p\n", info->player->addr);
	}
}

void	ft_print_map(t_info *info)
{
	if (info->map)
		ft_putstrarray(info->map);
	else
		printf("map is NULL\n");
}

void	ft_print_user_data(t_info *info)
{
	printf("USER DATA\n");
	printf("fd of the map: %d\n", info->fd);
	printf("height of the map: %d\n", info->h);
	printf("width of the map: %d\n", info->w);
	printf("position user_y: %d\n", info->user_y);
	printf("position user_x: %d\n", info->user_x);
	printf("rotation user_deg: %d\n", info->user_deg);
	printf("position on cell pad_x: %d\n", info->pad_x);
	printf("position on cell pad_y: %d\n", info->pad_y);
	if (info->pad_x == 10 || info->pad_x == -10)
		ft_print_map(info);
	else if (info->pad_y == 10 || info->pad_y == -10)
		ft_print_map(info);
}