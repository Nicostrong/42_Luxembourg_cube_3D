/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:57:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/19 16:53:52 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_img(t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_init_img initialise the first part of all image variables on the 
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
		ft_perror_exit(E_XPM, *info);
	(*info)->f_img = mlx_xpm_file_to_image((*info)->mlx, \
		(*info)->f_img->img_path, &(*info)->f_img->h, &(*info)->f_img->w);
	if (!(*info)->f_img)
		ft_perror_exit(E_XPM, *info);
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
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_win	*ft_init_info_win(t_info *info, int w, int h, char *title)
 * </summary>
 *
 * <description>
 * 	ft_init_info_win create a windows structure
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static t_win	*ft_init_info_win(t_info *info, int w, int h, char *title)
{
	t_win	*windows;

	windows = (t_win *)ft_calloc(1, sizeof(t_win));
	if (!windows)
		ft_perror_exit(E_MALLOC, info);
	windows->win = mlx_new_window(info->mlx, w, h, title);
	if (!windows->win)
		ft_perror_exit(E_WIN, info);
	windows->img = mlx_new_image(info->mlx, w, h);
	if (!windows->img)
		ft_perror_exit(E_IMG, info);
	windows->addr = mlx_get_data_addr(windows->img, &windows->bpp, \
		&windows->size, &windows->endian);
	if (!windows->addr)
		ft_perror_exit(E_ADR, info);
	return (windows);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_img_color(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_img_color initialise all img and color structure.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_init_img_color(t_info *info)
{
	info->s_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->s_img)
		ft_perror_exit(E_MALLOC, info);
	info->f_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->f_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_n_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_n_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_e_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_e_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_s_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_s_img)
		ft_perror_exit(E_MALLOC, info);
	info->w_w_img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!info->w_w_img)
		ft_perror_exit(E_MALLOC, info);
	info->player = (t_img *)ft_calloc(1, sizeof(t_img));
	if (info->player)
	{
		info->player->img_path = ft_strdup(MINI_I_PL);
		info->player->w = MINI_S_PL;
		info->player->h = MINI_S_PL;
		info->player->img = mlx_xpm_file_to_image(info->mlx, \
			info->player->img_path, &info->player->w, &info->player->h);
		info->player->addr = mlx_get_data_addr(info->player->img, \
			&info->player->bpp, &info->player->size, &info->player->endian);
	}
	/*info->floor_color = (t_color *)ft_calloc(1, sizeof(t_color));
	if (!info->floor_color)
		ft_perror_exit(E_MALLOC, info);
	info->sky_color = (t_color *)ft_calloc(1, sizeof(t_color));
	if (!info->sky_color)
		ft_perror_exit(E_MALLOC, info);
	*/
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
	info_map[0].t_img = &info->w_n_img;
	info_map[1].key = "SO";
	info_map[1].t_img = &info->w_s_img;
	info_map[2].key = "WE";
	info_map[2].t_img = &info->w_w_img;
	info_map[3].key = "EA";
	info_map[3].t_img = &info->w_e_img;
	info_map[4].key = "FT";
	info_map[4].t_img = &info->f_img;
	info_map[5].key = "CT";
	info_map[5].t_img = &info->s_img;
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
	if (info->fd < 0)
		ft_perror_exit(E_OPEN, info);
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_perror_exit(E_MLX, info);
	info->game = ft_init_info_win(info, WIDTH, HEIGHT, TITLE);
	info->mini = ft_init_info_win(info, MINI_W, MINI_H, MINI_TITRE);
	ft_init_img_color(info);
	info->info_map = ft_init_info_path(info);
	return (info);
}