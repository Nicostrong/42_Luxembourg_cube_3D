/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:36:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:30:46 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_window(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_window destroy the image of the windows game and free the windows 
 * 	pointer and the mlx pointer.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_free_window(t_info *info)
{
	if (info->game)
	{
		mlx_destroy_image(info->mlx, info->game->img);
		mlx_clear_window(info->mlx, info->game->win);
		mlx_destroy_window(info->mlx, info->game->win);
		info->game->win = NULL;
		ft_free((void **)&info->game);
	}
	if (info->mlx)
	{
		DESTROY(info->mlx);
		ft_free((void **)&info->mlx);
		//info->mlx = NULL;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_img_struct(t_img *img, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_all_images free all images on the structure.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_free_img_struct(t_img *img, t_info *info)
{
	if (img)
	{
		if (img->img_path)
		{
			ft_free((void **)&img->img_path);
			//img->img_path = NULL;
		}
		if (img->img)
		{
			mlx_destroy_image(info->mlx, img->img);
			img->img = NULL;
		}
		ft_free((void **)&img);
		//img = NULL;
		return ;
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_all_images(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_all_images free all images on the structure.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_free_all_images(t_info *info)
{
	if (info->s_img)
		ft_free_img_struct(info->s_img, info);
	if (info->f_img)
		ft_free_img_struct(info->f_img, info);
	if (info->w_n_img)
		ft_free_img_struct(info->w_n_img, info);
	if (info->w_e_img)
		ft_free_img_struct(info->w_e_img, info);
	if (info->w_s_img)
		ft_free_img_struct(info->w_s_img, info);
	if (info->w_w_img)
		ft_free_img_struct(info->w_w_img, info);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_simple_pointer(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_simple_pointer free the the simple pointer on the info structure.
 * </description>
 *
 * <param type="t_info *" name="info">structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_free_simple_pointer(t_info *info)
{
	if (!info)
		return ;
	if (info->map_path)
		ft_free((void **)&info->map_path);
	if (info->map)
		ft_free_array(info->map);
	if (info->floor_color)
		ft_free((void **)&info->floor_color);
	if (info->sky_color)
		ft_free((void **)&info->sky_color);
	if (info->info_map)
		ft_free((void **)&info->info_map);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_info(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_info free the structure if it's allocated and call other 
 * 	function to free all part of the structure.
 * </description>
 *
 * <param type="t_info *" name="info">structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_free_info(t_info *info)
{
	if (!info)
		return ;
	if (info->fd > 2)
		close(info->fd);
	if (info->line)
	{
		ft_free((void **)&info->line);
		get_next_line(-1);
	}
	ft_free_simple_pointer(info);
	ft_free_all_images(info);
	ft_free_window(info);
	ft_free((void **)&info);
	return ;
}
