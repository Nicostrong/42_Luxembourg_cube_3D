/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:36:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/06 12:05:00 by nfordoxc         ###   Luxembourg.lu     */
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
	if (info->win)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
		info->win = NULL;
	}
	if (info->mlx)
	{
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
 * 	void	ft_free_images(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_images free all images on the structure.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_free_images(t_info *info)
{
	if (info->s_img)
	{
		ft_free(info->s_img->img_path);
		mlx_destroy_image(info->mlx, info->s_img->img);
		ft_free(info->s_img);
	}
	if (info->f_img)
	{
		ft_free(info->f_img->img_path);
		mlx_destroy_image(info->mlx, info->f_img->img);
		ft_free(info->f_img);
	}
	if (info->w_n_img)
	{
		ft_free(info->w_n_img->img_path);
		mlx_destroy_image(info->mlx, info->w_n_img);
		ft_free(info->w_n_img);
	}
	if (info->w_e_img)
	{
		ft_free(info->w_e_img->img_path);
		mlx_destroy_image(info->mlx, info->w_e_img);
		ft_free(info->w_e_img);
	}
	if (info->w_s_img)
	{
		ft_free(info->w_s_img->img_path);
		mlx_destroy_image(info->mlx, info->w_s_img);
		ft_free(info->w_s_img);
	}
	if (info->w_w_img)
	{
		ft_free(info->w_w_img->img_path);
		mlx_destroy_image(info->mlx, info->w_w_img);
		ft_free(info->w_w_img);
	}
	if (info->floor_color)
		ft_free(info->floor_color);
	if (info->sky_color)
		ft_free(info->sky_color);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_free_path(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_free_path free all path in the structure.
 * </description>
 *
 * <param type="t_info *" name="info">pointer to the structure to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_free_path(t_info *info)
{
	if (info->map_path)
		ft_free(info->map_path);
	if (info->line)
		ft_free(info->line);
	if (info->s_img && info->s_img->img_path)
		ft_free(info->s_img->img_path);
	if (info->f_img && info->f_img->img_path)
		ft_free(info->f_img->img_path);
	if (info->w_n_img && info->w_n_img->img_path)
		ft_free(info->w_n_img->img_path);
	if (info->w_e_img && info->w_e_img->img_path)
		ft_free(info->w_e_img->img_path);
	if (info->w_s_img && info->w_s_img->img_path)
		ft_free(info->w_s_img->img_path);
	if (info->w_w_img && info->w_w_img->img_path)
		ft_free(info->w_w_img->img_path);
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
	if (info->map)
		ft_free_array(info->map);
	if (info->floor_color)
		ft_free(info->floor_color);
	if (info->sky_color)
		ft_free(info->sky_color);
	ft_free_path(info);
	if (info->info_map)
		ft_free(info->info_map);
	ft_free_images(info);
	//ft_free_anim(info->c_anim, info);
	ft_free_window(info);
	ft_free(info);
}