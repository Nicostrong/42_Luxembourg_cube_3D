/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:04:52 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 18:10:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_f_and_s_img(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_get_f_and_s_img initialize the image structure with all values of the xpm
 *  file for sky and floor texture.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_f_and_s_img(t_info **info)
{
	(*info)->s_img->img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->s_img->img_path, &(*info)->s_img->h, &(*info)->s_img->w);
	if (!(*info)->s_img)
		ft_perror_exit(E_XPM, *info);
	(*info)->f_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->f_img->img_path, &(*info)->f_img->h, &(*info)->f_img->w);
	if (!(*info)->f_img)
		ft_perror_exit(E_XPM, *info);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_wall_img(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_get_wall_img initialize the image structure with all values of the xpm
 *  file.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_wall_img(t_info **info)
{
	(*info)->w_n_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_n_img->img_path, &(*info)->w_n_img->h, &(*info)->w_n_img->w);
	if (!(*info)->w_n_img)
		ft_perror_exit(E_XPM, *info);
	(*info)->w_e_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_e_img->img_path, &(*info)->w_e_img->h, &(*info)->w_e_img->w);
	if (!(*info)->w_e_img)
		ft_perror_exit(E_XPM, *info);
	(*info)->w_s_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_s_img->img_path, &(*info)->w_s_img->h, &(*info)->w_s_img->w);
	if (!(*info)->w_s_img)
		ft_perror_exit(E_XPM, *info);
	(*info)->w_w_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_w_img->img_path, &(*info)->w_w_img->h, &(*info)->w_w_img->w);
	if (!(*info)->w_w_img)
		ft_perror_exit(E_XPM, *info);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_img(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_get_img initialise all images on the structure.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_get_img(t_info **info)
{
	ft_get_wall_img(info);
	ft_get_f_and_s_img(info);
	return ;
}
