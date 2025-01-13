/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:36:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/13 08:04:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_window(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_window free the both windows and the mlx pointer.
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
		ft_free(info->game);
	}
	if (info->mini)
	{
		mlx_destroy_image(info->mlx, info->mini->img);
		mlx_clear_window(info->mlx, info->mini->win);
		mlx_destroy_window(info->mlx, info->mini->win);
		info->mini->win = NULL;
		ft_free(info->mini);
	}
	if (info->mlx)
	{
		if (LINUX)
			mlx_destroy_display(info->mlx);
		ft_free(info->mlx);
		info->mlx = NULL;
	}
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_anim(t_anim *anim, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_anim free a structure t_anim.
 * </description>
 *
 * <param type="t_anim *" name="anim">anim struct to free</param>
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
/*
static void	ft_free_anim(t_anim *anim, t_info *info)
{
	int	index;

	index = 0;
	if (anim->array_img)
	{
		while (index < anim->nb_img && anim->array_img[index])
		{
			mlx_destroy_image(info->mlx, anim->array_img[index]);
			anim->array_img[index] = NULL;
			index++;
		}
		ft_free(anim->array_img);
		anim->array_img = NULL;
		ft_free(anim);
		anim = NULL;
	}
}*/

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
			ft_free(img->img_path);
			img->img_path = NULL;
		}
		if (img->img)
		{
			mlx_destroy_image(info->mlx, img->img);
			img->img = NULL;
		}
		ft_free(img);
		img = NULL;
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
	if (info->player)
		ft_free_img_struct(info->player, info);
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
 * <param type="t_info *" name="info">pointer to the structure to free</param>
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
		ft_free(info->line);
		get_next_line(-1);
	}
	if (info->colors)
		ft_free(info->colors);
	if (info->widths)
		ft_free(info->widths);
	if (info->heights)
		ft_free(info->heights);
	if (info->map_path)
		ft_free(info->map_path);
	if (info->map)
		ft_free_array(info->map);
	if (info->floor_color)
		ft_free(info->floor_color);
	if (info->sky_color)
		ft_free(info->sky_color);
	if (info->info_map)
		ft_free(info->info_map);
	ft_free_all_images(info);
	//ft_free_anim(info->c_anim, info);
	ft_free_window(info);
	ft_free(info);
}