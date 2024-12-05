/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:57:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/05 18:53:52 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/structures.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_img(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_init_imag initialise the first part of all image variables on the 
 * 	structure.
 * </description>
 *
 * <param type="t_info **" name="info">pointer to the structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_init_img(t_info **info)
{
	(*info)->s_img->img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->s_img->img_path, &(*info)->s_img->h, &(*info)->s_img->w);
	if (!(*info)->s_img)
		ft_perror_exit_bonus(E_XPM, *info);
	(*info)->f_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->f_img->img_path, &(*info)->f_img->h, &(*info)->f_img->w);
	if (!(*info)->f_img)
		ft_perror_exit_bonus(E_XPM, *info);
	(*info)->w_n_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_n_img->img_path, &(*info)->w_n_img->h, &(*info)->w_n_img->w);
	if (!(*info)->w_n_img)
		ft_perror_exit_bonus(E_XPM, *info);
	(*info)->w_e_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_e_img->img_path, &(*info)->w_e_img->h, &(*info)->w_e_img->w);
	if (!(*info)->w_e_img)
		ft_perror_exit_bonus(E_XPM, *info);
	(*info)->w_s_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_s_img, &(*info)->w_s_img->h, &(*info)->w_s_img->w);
	if (!(*info)->w_s_img)
		ft_perror_exit_bonus(E_XPM, *info);
	(*info)->w_w_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->w_w_img->img_path, &(*info)->w_w_img->h, &(*info)->w_w_img->w);
	if (!(*info)->w_w_img)
		ft_perror_exit_bonus(E_XPM, *info);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_info_map	*ft_init_info_path(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_info_map allow to initialise the path and color of the structure.
 * 	Make the link between the key and the path or color.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	a pointer to the structure info_map full initialised.
 * </return>
 *
 */
static t_info_map	*ft_init_info_path(t_info *info)
{
	t_info_map	*info_map;

	info_map = ft_calloc(9, sizeof(t_info_map));
	if (!info_map)
		ft_perror_exit(E_MALLOC, info);
	info_map[0].key = "NO";
    info_map[0].path = &info->w_n_img->img_path;
    info_map[1].key = "SO";
    info_map[1].path = &info->w_s_img->img_path;
    info_map[2].key = "WE";
    info_map[2].path = &info->w_w_img->img_path;
    info_map[3].key = "EA";
    info_map[3].path = &info->w_e_img->img_path;
    info_map[4].key = "FT";
    info_map[4].path = &info->f_img->img_path;
    info_map[5].key = "CT";
    info_map[5].path = &info->s_img->img_path;
    info_map[6].key = "F";
    info_map[6].color = &info->floor_color;
    info_map[7].key = "C";
    info_map[7].color = &info->sky_color;
	return (info_map);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_info	*ft_init_info(char *path)
 * </summary>
 *
 * <description>
 * 	ft_init_info allow all memory for the structure and initialise somes 
 * 	variables, and call ft_init_info2 and ft_init_img, ft_init_img2 and 
 * 	ft_init_anim to initialise all variables of the structure.
 * </description>
 *
 * <param type="char *" name="path">path of the map</param>
 *
 * <return>
 * 	a pointer to the structure full initisalized.
 * </return>
 *
 */
t_info	*ft_init_info(char *path)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		ft_perror_exit(E_MALLOC, NULL);
	info->map_path = ft_strdup(path);
	info->fd = open(path, O_RDONLY);
	ft_init_info2(info);
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_perror_exit(E_MLX, info);
	info->info_map = ft_init_info_path(info);
	return (info);
}