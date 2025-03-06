/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:56:01 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/17 13:08:44 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_flood_fill(char **map, int x, int y, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_flood_fill replace all char 'O' on the map by the char '2' to simulate 
 * 	all path who the player can use on the map, and check if the map is 
 * 	correctely closed.
 * </description>
 *
 * <param type="char **" name="map">map to check</param>
 * <param type="int" name="x">position on x</param>
 * <param type="int" name="y">position on y</param>
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_flood_fill(char **map, int x, int y, t_info *info)
{
	if (x < 0 || y < 0 || x >= info->w || y >= info->h)
		return ;
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	if (map[y][x] == ' ')
	{
		info->is_valid = 0;
		return ;
	}
	map[y][x] = '2';
	ft_flood_fill(map, x, y - 1, info);
	ft_flood_fill(map, x + 1, y, info);
	ft_flood_fill(map, x, y + 1, info);
	ft_flood_fill(map, x - 1, y, info);
	return ;
}

/*
 * <cat>cube_3D</cat>
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
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_set_direction(char c, t_info *info)
{
	if (c == 'N')
		info->user_deg = -M_PI_2;
	else if (c == 'E')
		info->user_deg = 0.0;
	else if (c == 'S')
		info->user_deg = M_PI_2;
	else if (c == 'W')
		info->user_deg = M_PI;
	return ;
}

/*
 * <cat>cube_3D</cat>
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
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_pos_player(char **map, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				info->user_x = j + 0.5;
				info->x = j;
				info->user_y = i + 0.5;
				info->y = i;
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
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_door_items(t_info *info, char **map)
 * </summary>
 *
 * <description>
 * 	ft_door_items replace all char 'D' by 'C' and count the number of items.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="char**" name="map">map array</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_door_items(t_info *info, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'D')
				map[i][j] = 'C';
			if (map[i][j] == 'I')
				info->i_nbr++;
		}
	}
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_check_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_check_map check if the map is valid.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_check_map(t_info *info)
{
	char	**map_cpy;

	if (!info->map)
		ft_perror_exit(E_MAP, info);
	ft_get_pos_player(info->map, info);
	map_cpy = ft_strarraycpy(info->map);
	if (!map_cpy)
		ft_perror_exit(E_MALLOC, info);
	info->is_valid = 1;
	ft_flood_fill(map_cpy, info->user_x, info->user_y, info);
	ft_free_array(map_cpy);
	if (!info->is_valid)
		ft_perror_exit(E_CLOSE, info);
	ft_door_items(info, info->map);
	return ;
}
