/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structure_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:57:09 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 14:49:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/error_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_arrays(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_arrays alloc and initialise all arrays for the minimap.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_init_arrays(t_info *info)
{
	info->colors = ft_calloc(8, sizeof(int));
	info->widths = ft_calloc(8, sizeof(double));
	info->heights = ft_calloc(6, sizeof(double));
	if (!info->colors || !info->widths || !info->heights)
		ft_perror_exit(E_MALLOC, info);
	return ;
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

	info_map = ft_calloc(11, sizeof(t_info_map));
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
	info_map[6].key = "P";
	info_map[6].t_img = &info->player;
	info_map[7].key = "D";
	info_map[7].t_img = &info->door;
	info_map[8].key = "F";
	info_map[8].color = &info->floor_color;
	info_map[9].key = "C";
	info_map[9].color = &info->sky_color;
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
	ft_init_arrays(info);
	ft_init_mlx(info);
	ft_init_img(info);
	ft_init_color(info);
	info->c_anim = ft_init_anim(info);
	info->thread = ft_init_thread(info);
	info->info_map = ft_init_info_path(info);
	info->move = 1;
	return (info);
}

/*
if (info->player)
{
	info->player->img_path = ft_strdup(MINI_I_PL);
	info->player->w = MINI_S_PL;
	info->player->h = MINI_S_PL;
	info->player->img = mlx_xpm_file_to_image(info->mlx, \
		info->player->img_path, &info->player->w, &info->player->h);
	info->player->addr = mlx_get_data_addr(info->player->img, \
		&info->player->bpp, &info->player->size, &info->player->endian);
}*/
