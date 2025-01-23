/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:33:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/23 15:56:14 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_ismap(char *line)
 * </summary>
 *
 * <description>
 * 	ft_ismap check if the line is a map.
 * 	A map contain only ' ', '0', '1', '2', 'N', 'S', 'E', 'W'.
 * </description>
 *
 * <param type="char *" name="line">line to check</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 * 
 */
static int	ft_ismap(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			return (0);
	}
	return (1);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_map(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_map get the map from the file and put it in the structure.
 * </description>
 *
 * <param type="t_info *" name="info">general structure/param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static void	ft_get_map(t_info *info)
{
	char	**map;

	map = ft_calloc(1, sizeof(char *));
	if (!map)
		ft_perror_exit(E_MALLOC, info);
	while (info && info->line && ft_strncmp(info->line, "\n", 1))
	{
		if (ft_strlen(info->line) < 3)
			ft_perror_exit(E_MAP, info);
		if (ft_ismap(info->line))
		{
			map = ft_append_str(map, info->line);
			if (!map)
				ft_perror_exit(E_MALLOC, info);
			if (info->w < (int)ft_strlen(info->line))
				info->w = ft_strlen(info->line);
			info->h++;
			ft_free(info->line);
			info->line = get_next_line(info->fd);
		}
		else
			ft_perror_exit(E_MAP, info);
	}
	info->map = map;
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_color	*ft_extract_color(char *str)
 * </summary>
 *
 * <description>
 * 	ft_extract_color extract the color from the string and put it in a
 * 	structure.
 * </description>
 *
 * <param type="char *" name="str">string to parse</param>
 *
 * <return>
 * 	a pointer to a structure t_color with all value.
 * </return>
 *
 */
static void	ft_extract_color(char *str, char *color, t_info *info)
{
	char	**array;
	t_color	*new;

	new = (t_color *)ft_calloc(1, sizeof(t_color));
	if (!new)
		ft_perror_exit(E_MALLOC, info);
	if (!str)
		return ;
	array = ft_split(color, ',');
	new->r = ft_atoi(array[0]);
	new->g = ft_atoi(array[1]);
	new->b = ft_atoi(array[2]);
	new->color = ft_get_color(new->t, new->r, new->g, new->b);
	ft_free_array(array);
	if (new->r < 0 || new->r > 255 || new->g < 0 || new->g > 255 \
		|| new->b < 0 || new->b > 255)
	{
		if (ft_strequal(str, "F"))
			ft_perror_exit(E_F_COLOR, info);
		else if (ft_strequal(str, "C"))
			ft_perror_exit(E_C_COLOR, info);
	}
	if (ft_strequal(str, "F"))
		info->floor_color = new;
	else if (ft_strequal(str, "C"))
		info->sky_color = new;
	else
		ft_free(new);
	return ;
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_extract_info(t_info *info, char **array)
 * </summary>
 *
 * <description>
 * 	ft_extract_info extract the information from the array and put it in the
 * 	structure info.
 * </description>
 *
 * <param type="t_info *" name="info">general structure/param>
 * <param type="char **" name="array">array of string</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static int	ft_extract_info(t_info *info, char **array)
{
	int	i;

	i = -1;
	while (info->info_map[++i].key)
	{
		if (ft_strequal(array[0], info->info_map[i].key))
		{
			if (info->info_map[i].t_img && \
				!(*(info->info_map[i].t_img))->img_path)
				(*(info->info_map[i].t_img))->img_path = ft_strdup(array[1]);
			else if (info->info_map[i].color)
				ft_extract_color(array[0], array[1], info);
			return (0);
		}
	}
	return (1);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_read_file(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_read_file parse the file .cub and complet all elements of the structure
 *  info.
 * </description>
 *
 * <param type="t_info *" name="info">general structure/param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_read_file(t_info *info)
{
	char	**array;
	int		error;

	error = 0;
	info->line = get_next_line(info->fd);
	while (info->line && !error)
	{
		if (ft_strlen(info->line) > 0)
		{
			array = ft_split(info->line, ' ');
			if (array[0] && array[1] && !ft_ismap(info->line))
				error = ft_extract_info(info, array);
			else if (ft_ismap(info->line))
				ft_get_map(info);
			ft_free_array(array);
		}
		ft_free(info->line);
		info->line = NULL;
		if (!error)
			info->line = get_next_line(info->fd);
	}
	if (error)
		ft_perror_exit(E_PARAM, info);
	return ;
}
