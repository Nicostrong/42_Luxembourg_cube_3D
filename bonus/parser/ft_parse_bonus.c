/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:07:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 18:06:07 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 *	<cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_texture_s_f(t_info *info)
 * </summary>
 * 
 * <description>
 * 	ft_check_texture_s_f check if the texture for the sky and the floor are
 * 	available and set a boolean to use it.
 * </description>
 * 
 * <param type="t_info *" name="info">main structure</param>
 * 
 * <return>
 * 	void.
 * </return>
 * 
 */
static void	ft_check_texture_s_f(t_info *info)
{
	if (info->s_img && info->s_img->img)
		info->use_s_img = 1;
	if (info->f_img && info->f_img->img)
		info->use_f_img = 1;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_all_xpm(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_set_all_xpm set all xpm in the structure info.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_set_all_xpm(t_info *info)
{
	int	i;

	i = -1;
	while (info->info_map[++i].t_img)
	{
		if (info->info_map[i].t_img && (*info->info_map[i].t_img)->img_path)
		{
			ft_get_size_xpm(info, (*info->info_map[i].t_img)->img_path, i);
			(*info->info_map[i].t_img)->img = mlx_xpm_file_to_image(info->mlx, \
				(*info->info_map[i].t_img)->img_path, \
				&(*info->info_map[i].t_img)->w, &(*info->info_map[i].t_img)->h);
			if (!(*info->info_map[i].t_img)->img && i < 4)
				ft_perror_exit(E_IMG, info);
			(*info->info_map[i].t_img)->addr = mlx_get_data_addr(\
				(*info->info_map[i].t_img)->img, \
				&(*info->info_map[i].t_img)->bpp, \
				&(*info->info_map[i].t_img)->size, \
				&(*info->info_map[i].t_img)->endian);
			if (!(*info->info_map[i].t_img)->addr && i < 4)
				ft_perror_exit(E_ADR, info);
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_path(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_path check if all path are valid.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_path(t_info *info)
{
	int	error;

	error = 0;
	if (!info->w_n_img->img_path || access(info->w_n_img->img_path, F_OK) == -1)
		error |= W_N_IMG_E;
	if (!info->w_s_img->img_path || access(info->w_s_img->img_path, F_OK) == -1)
		error |= W_S_IMG_E;
	if (!info->w_e_img->img_path || access(info->w_e_img->img_path, F_OK) == -1)
		error |= W_E_IMG_E;
	if (!info->w_w_img->img_path || access(info->w_w_img->img_path, F_OK) == -1)
		error |= W_W_IMG_E;
	if (info->f_img->img_path && access(info->f_img->img_path, F_OK) == -1)
		ft_free((void **)&info->f_img->img_path);
	if (info->s_img->img_path && access(info->s_img->img_path, F_OK) == -1)
		ft_free((void **)&info->s_img->img_path);
	if (info->player->img_path && access(info->player->img_path, F_OK) == -1)
		ft_free((void **)&info->player->img_path);
	if (info->door->img_path && access(info->door->img_path, F_OK) == -1)
		error |= D_IMG_E;
	if (error)
		ft_error_msg(error, 1, info);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_color_s_f(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_color_s_f check if the sky and the floor color are valid.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_color_s_f(t_info *info)
{
	int	error;

	error = 0;
	if (!info->sky_color)
		error |= E_COL_S;
	if (!info->floor_color)
		error |= E_COL_F;
	if (error)
		ft_error_msg(error, 1, info);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_info	*ft_get_all_info(char *path)
 * </summary>
 *
 * <description>
 * 	ft_get_all_info parse the file .cub and complet all elements of the 
 * 	structure info.
 * </description>
 *
 * <param type="char *" name="path">path of .cub file</param>
 *
 * <return>
 * 	a pointer to the structure info full initialised.
 * </return>
 *
 */
t_info	*ft_get_all_info(char *path)
{
	t_info	*info;
	int		error;

	error = 0;
	info = ft_init_info(path);
	ft_read_file(info, error);
	ft_check_color_s_f(info);
	ft_check_path(info);
	ft_check_map(info);
	ft_set_all_xpm(info);
	ft_check_texture_s_f(info);
	return (info);
}
