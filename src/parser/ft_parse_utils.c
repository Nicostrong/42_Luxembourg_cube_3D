/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:33:30 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/06 13:24:36 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/error.h"
#include "../../includes/structures.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	int	ft_ismap(char *line)
 * </summary>
 *
 * <description>
 * 	ft_ismap check if the line is a map.
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

	printf("ft_ismap\n");
	i = -1;
	while (line[++i])
		if (!ft_strchr(" 01NSEW", line[i]))
			return (0);
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
	int		i;

	printf("ft_get_map\n");
	map = ft_calloc(1, sizeof(char *));
	if (!map)
		ft_perror_exit(E_MALLOC, info);
	i = -1;
	while (info->line)
	{
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
			ft_perror_exit(E_PARAM, info);
	}
	
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
static t_color	*ft_extract_color(char *str, t_color *color)
{
	char	**array;

	printf("ft_extract_color\n");
	array = ft_split(str, ',');
	color->r = ft_atoi(array[0]);
	color->g = ft_atoi(array[1]);
	color->b = ft_atoi(array[2]);
	ft_free_array(array);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 \
		|| color->b < 0 || color->b > 255)
		return (ft_free(color), NULL);
	return (color);
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
	int i;

	i = -1;
	while (info->info_map[++i].key)
	{
		if (ft_strequal(array[0], info->info_map[i].key))
		{
			printf("path dans array[1] = %s\n", array[1]);
			if (info->info_map[i].path && !*(info->info_map[i].path))
				*(info->info_map[i].path) = ft_strdup(array[1]);
			else if (info->info_map[i].color)
				ft_extract_color(array[1], *info->info_map[i].color);
			return (ft_free_array(array), 0);
		}
	}
	ft_free_array(array);
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

	printf("ft_read_file\n");
	error = 0;
	info->line = get_next_line(info->fd);
	info->line[ft_strlen(info->line) - 1] = '\0';
	while (info->line && !error)
	{
		if (ft_strlen(info->line) > 0)
		{
			array = ft_split(info->line, ' ');
			printf("DEBUG array lecture fichier\n");
			ft_putstrarray(array);
			if (array[0] && array[1])
				error = ft_extract_info(info, array);
			else if (ft_strequal(array[0], "MAP") || ft_ismap(info->line))
			{
				if (ft_strequal(array[0], "MAP"))
				{
					ft_free_array(array);
					ft_free(info->line);
					info->line = get_next_line(info->fd);
					info->line[ft_strlen(info->line) - 1] = '\0';
				}
				ft_get_map(info);
			}
			else
				printf("No thing to do\n");
		}
		ft_free(info->line);
		info->line = NULL;
		if (!error)
			info->line = get_next_line(info->fd);
	}
	if (error)
		ft_perror_exit(E_PARAM, info);
}