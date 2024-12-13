/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:56:01 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/13 12:51:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/structures.h"


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
		info->user_deg = 0;
	else if (c == 'E')
		info->user_deg = 90;
	else if (c == 'S')
		info->user_deg = 180;
	else if (c == 'W')
		info->user_deg = 270;
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
				map[i][j] = 'P';
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
void	ft_check_map(t_info *info)
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