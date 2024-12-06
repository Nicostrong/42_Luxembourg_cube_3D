/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:07:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/06 13:45:32 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/structures.h"

static void	ft_get_size_xpm(t_info *info)
{
	(void)info;
	// pour chaque path de xpm
	// ouvrir le xpm  => test error lecture
	// rechercher la ligne qui commence par '"'
	// spliter la ligne  a la ' '
	// premiere valeur => width
	// seconde valeur => height
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_flood_fill(char **map, int x, int y, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_flood_fill replace all char 'O' on the map by the char '2' to simulate 
 * 	all path who the player can use on the map.
 * </description>
 *
 * <param type="char **" name="map"></param>
 * <param type="int" name="x">position on x</param>
 * <param type="int" name="y">position on y</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static int	ft_flood_fill(char **map, int x, int y, t_info *info)
{
	if (x < 0 || y < 0 || x >= info->w || y >= info->h)
		return (0);
	if (map[y][x] == '1' || map[y][x] == '2')
		return (1);
	if (map[y][x] == ' ')
		return (0);
	map[y][x] = '2';
	if (!ft_flood_fill(map, x, y - 1, info))
		return (0);
	if (!ft_flood_fill(map, x + 1, y, info))
		return (0);
	if (!ft_flood_fill(map, x, y + 1, info))
		return (0);
	if (!ft_flood_fill(map, x - 1, y, info))
		return (0);
	return (1);
}

/*
 * <cat>scube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_map check if the map is valid.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_map(t_info *info)
{
	char	**map_cpy;
	int	result;
	int	i;
	int	j;

	printf("ft_check_map\n");
	map_cpy = ft_strarraycpy(info->map);
	if (!map_cpy)
		ft_perror_exit(E_MALLOC, info);
	i = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' \
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
			{
				info->user_x = j;
				info->user_y = i;
				info->p_nbr++;
			}
		}
	}
	if (info->p_nbr != 1)
		ft_perror_exit(E_SPAWN, info);
	result = ft_flood_fill(map_cpy, info->user_x, info->user_y, info);
	ft_free_array(map_cpy);
	if (result)
		ft_perror_exit(E_CLOSE, info);
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
	printf("ft_check_path\n");
	if (!info->w_n_img->img_path || access(info->w_n_img->img_path, F_OK) == -1)
		error |= W_N_IMG_E;
	if (!info->w_s_img->img_path || access(info->w_s_img->img_path, F_OK) == -1)
		error |= W_S_IMG_E;
	if (!info->w_e_img->img_path || access(info->w_e_img->img_path, F_OK) == -1)
		error |= W_E_IMG_E;
	if (!info->w_w_img->img_path || access(info->w_w_img->img_path, F_OK) == -1)
		error |= W_W_IMG_E;
	if (!info->f_img->img_path || access(info->f_img->img_path, F_OK) == -1)
		error |= F_IMG_E;
	if (!info->s_img->img_path || access(info->s_img->img_path, F_OK) == -1)
		error |= S_IMG_E;
	if (error)
		ft_error_msg(error, 1, info);
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

	info = ft_init_info(path);
	ft_read_file(info);
	ft_check_path(info);
	ft_check_map(info);
	ft_get_size_xpm(info);
	return (info);
}