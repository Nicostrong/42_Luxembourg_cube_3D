/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:07:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/10 11:03:00 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/structures.h"

static void	ft_get_size_xpm(t_info *info, char *path,int i)
{
	char	*line;
	char	*sub_line;
	char	**array;
	int 	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_perror_exit(E_XPM, info);
	line = get_next_line(fd);
	while (line && line[0] != '"')
	{
		ft_free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	if (!line)
		ft_perror_exit(E_READ, info);
	sub_line = ft_strremoveset(line, "\"");
	array = ft_split(sub_line, ' ');
	if (array && array[0] && array[1])
	{
		(*info->info_map[i].t_img)->w = ft_atoi(array[0]);
		(*info->info_map[i].t_img)->h = ft_atoi(array[1]);
	}
	else
		ft_perror_exit(E_XPM, info);
	ft_free_array(array);
	ft_free(sub_line);
	ft_free(line);
}

static void	ft_set_all_xpm(t_info *info)
{
	int i;

	i = -1;
	while (info->info_map[++i].t_img)
	{
		if (info->info_map[i].t_img && (*info->info_map[i].t_img)->img_path)
		{
			ft_get_size_xpm(info, (*info->info_map[i].t_img)->img_path, i);
			(*info->info_map[i].t_img)->img = mlx_xpm_file_to_image(info->mlx, \
				(*info->info_map[i].t_img)->img_path, \
				&(*info->info_map[i].t_img)->w, &(*info->info_map[i].t_img)->h);
			if (!(*info->info_map[i].t_img)->img)
				ft_perror_exit(E_IMG, info);
			(*info->info_map[i].t_img)->addr = mlx_get_data_addr(info->mlx, \
				&info->bpp, &info->w, &info->endian);
			if (!(*info->info_map[i].t_img)->addr)
				ft_perror_exit(E_ADR, info);
		}
	}
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
static void	ft_flood_fill(char **map, int x, int y, t_info *info, int *is_valid)
{
	if (x < 0 || y < 0 || x >= info->w || y >= info->h)
		return ;
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	if (map[y][x] == ' ')
	{
		*is_valid = 0;
		return ;
	}
	map[y][x] = '2';
	ft_flood_fill(map, x, y - 1, info, is_valid);
	ft_flood_fill(map, x + 1, y, info, is_valid);
	ft_flood_fill(map, x, y + 1, info, is_valid);
	ft_flood_fill(map, x - 1, y, info, is_valid);
	return ;
}

/*
 * <cat>scube_3D</cat>
 *
 * <summary>
 * 	void	ft_set_direction(char c, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_set_direction set the direction of the player.
 * </description>
 *
 * <param type="char" name="c">char of direction</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_set_direction(char c, t_info *info)
{
	if (c == 'N')
		info->user_deg = 270;
	else if (c == 'E')
		info->user_deg = 0;
	else if (c == 'S')
		info->user_deg = 90;
	else if (c == 'W')
		info->user_deg = 180;
	return ;
}

/*
 * <cat>scube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_pos_player(char **map, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_pos_player get the position of the player on the map and count the
 * 	number of player on the map.
 * </description>
 *
 * <param type="char **" name="map">map array</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_pos_player(char **map, t_info *info)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW",map[i][j]))
			{
				info->user_x = j;
				info->user_y = i;
				info->p_nbr++;
				ft_set_direction(map[i][j], info);
			}
		}
	}
	if (info->p_nbr != 1)
		ft_perror_exit(E_SPAWN, info);
	return ;
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
	int		is_valid;

	if (!info->map)
		ft_perror_exit(E_MAP, info);
	ft_get_pos_player(info->map, info);
	map_cpy = ft_strarraycpy(info->map);
	if (!map_cpy)
		ft_perror_exit(E_MALLOC, info);
	is_valid = 1;
	ft_flood_fill(map_cpy, info->user_x, info->user_y, info, &is_valid);
	ft_free_array(map_cpy);
	if (!is_valid)
		ft_perror_exit(E_CLOSE, info);
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
		error |= F_IMG_E;
	if (info->s_img->img_path && access(info->s_img->img_path, F_OK) == -1)
		error |= S_IMG_E;
	if (error)
		ft_error_msg(error, 1, info);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_sky_floor(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_sky_floor check if the sky and the floor are valid.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_check_sky_floor(t_info *info)
{
	if (!info->sky_color)
		ft_perror_exit(E_SKY, info);
	if (!info->floor_color)
		ft_perror_exit(E_FLOOR, info);
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
	ft_check_sky_floor(info);
	ft_check_path(info);
	//ft_print_map(info);
	ft_check_map(info);
	ft_set_all_xpm(info);
	//ft_print_info(info);
	return (info);
}