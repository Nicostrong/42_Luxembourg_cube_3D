/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:44:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/22 10:30:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"

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
	printf("\tfd of the map: %d\n", info->fd);
	printf("\theight of the map: %d\n", info->h);
	printf("\twidth of the map: %d\n", info->w);
	printf("\tposition user_y: %.2f\n", info->user_y);
	printf("\tposition user_x: %.2f\n", info->user_x);
	printf("\trotation user_deg: %.2f\n", info->user_deg);
	/*if (info->c_fund >= 0)
		printf("\tc_fund: %d\n", info->c_fund);
	if (info->move_nbr >= 0)
		printf("\tmove_nbr: %d\n", info->move_nbr);*/
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
	if (info->w_n_img)
	{
		printf(BBLUE"w_n_img:\n"RESET);
		printf("\tpath: %s\n", info->w_n_img->img_path);
		printf("\th: %d\n", info->w_n_img->h);
		printf("\tw: %d\n", info->w_n_img->w);
		printf("\timg: %p\n", info->w_n_img->img);
		printf("\taddr: %p\n", info->w_n_img->addr);
	}
	if (info->w_e_img)
	{
		printf(BBLUE"w_e_img:\n"RESET);
		printf("\tpath: %s\n", info->w_e_img->img_path);
		printf("\th: %d\n", info->w_e_img->h);
		printf("\tw: %d\n", info->w_e_img->w);
		printf("\timg: %p\n", info->w_e_img->img);
		printf("\taddr: %p\n", info->w_e_img->addr);
	}
	if (info->w_s_img)
	{
		printf(BBLUE"w_s_img:\n"RESET);
		printf("\tpath: %s\n", info->w_s_img->img_path);
		printf("\th: %d\n", info->w_s_img->h);
		printf("\tw: %d\n", info->w_s_img->w);
		printf("\timg: %p\n", info->w_s_img->img);
		printf("\taddr: %p\n", info->w_s_img->addr);
	}
	if (info->w_w_img)
	{
		printf(BBLUE"w_w_img:\n"RESET);
		printf("\tpath: %s\n", info->w_w_img->img_path);
		printf("\th: %d\n", info->w_w_img->h);
		printf("\tw: %d\n", info->w_w_img->w);
		printf("\timg: %p\n", info->w_w_img->img);
		printf("\taddr: %p\n", info->w_w_img->addr);
	}
	if (info->s_img)
	{
		printf(BBLUE"s_img:\n"RESET);
		printf("\tpath: %s\n", info->s_img->img_path);
		printf("\th: %d\n", info->s_img->h);
		printf("\tw: %d\n", info->s_img->w);
		printf("\timg: %p\n", info->s_img->img);
		printf("\taddr: %p\n", info->s_img->addr);
	}
	if (info->f_img)
	{
		printf(BBLUE"f_img:\n"RESET);
		printf("\tpath: %s\n", info->f_img->img_path);
		printf("\th: %d\n", info->f_img->h);
		printf("\tw: %d\n", info->f_img->w);
		printf("\timg: %p\n", info->f_img->img);
		printf("\taddr: %p\n", info->f_img->addr);
	}
	if (info->floor_color)
	{
		printf(BBLUE"floor_color:\n"RESET);
		printf("\tt: %d\n", info->floor_color->t);
		printf("\tr: %d\n", info->floor_color->r);
		printf("\tg: %d\n", info->floor_color->g);
		printf("\tb: %d\n", info->floor_color->b);
		printf("\tcolor: %x\n", info->floor_color->color);
	}
	if (info->sky_color)
	{
		printf(BBLUE"sky_color:\n"RESET);
		printf("\tt: %d\n", info->sky_color->t);
		printf("\tr: %d\n", info->sky_color->r);
		printf("\tg: %d\n", info->sky_color->g);
		printf("\tb: %d\n", info->sky_color->b);
		printf("\tcolor: %x\n", info->sky_color->color);
	}
	if (info->player)
	{
		printf(BBLUE"player_img:\n"RESET);
		printf("\tpath: %s\n", info->player->img_path);
		printf("\th: %d\n", info->player->h);
		printf("\tw: %d\n", info->player->w);
		printf("\timg: %p\n", info->player->img);
		printf("\taddr: %p\n", info->player->addr);
	}
}

void	ft_print_map(t_info *info)
{
	if (info->map)
		ft_putstrarray(info->map);
	else
		printf(REDC"\tmap is NULL\n"RESET);
}

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
}

void	ft_print_minimap(t_info *info, char **map)
{
	printf("***************\n");
	printf(BRED"MINIMAP DEBUG\n"RESET);
	printf("***************\n");
	if (map)
	{
		printf("minimap\n");
		ft_putstrarray(map);
	}
	printf("position user_x: %.2f\n", info->user_x);
	printf("position user_y: %.2f\n", info->user_y);
	/*printf("Dim minimap:\n");
	for (int y = 0; y < 6; y++)
		printf("\theights [%d]: %d\n", y, info->heights[y]);
	for (int x = 0; x < 8; x++)
		printf("\t\twidths [%d]: %d\n", x, info->widths[x]);
	printf("color line:\n");
	for (int c = 0; c < 8; c++)
		printf("\tcolors: %d\n", info->colors[c]);*/
}
