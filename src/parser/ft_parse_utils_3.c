/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:39:23 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 17:53:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_color	*ft_set_color_struct(t_info *info, char **a_color)
 * </summary>
 *
 * <description>
 * 	ft_set_color_struct create a new struct color and set each element with the 
 * 	correct value.
 * </description>
 *
 * <param type="t_info *" name="info">main structure/param>
 * <param type="char **" name="a_color">array of color value</param>
 *
 * <return>
 * 	a pointer to a structure t_color with all value.
 * </return>
 *
 */
t_color	*ft_set_color_struct(t_info *info, char **a_color)
{
	t_color	*color;

	color = (t_color *)ft_calloc(1, sizeof(t_color));
	if (!color)
		ft_perror_exit(E_MALLOC, info);
	if (a_color[3])
	{
		color->r = ft_atoi(a_color[0]);
		color->g = ft_atoi(a_color[1]);
		color->b = ft_atoi(a_color[2]);
		color->t = ft_atoi(a_color[3]);
		color->color = ft_get_color(color->t, color->r, color->g, color->b);
	}
	else
	{
		color->r = ft_atoi(a_color[0]);
		color->g = ft_atoi(a_color[1]);
		color->b = ft_atoi(a_color[2]);
		color->t = 0;
		color->color = ft_get_color(color->t, color->r, color->g, color->b);
	}
	return (color);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	char	*ft_get_line_size(char *path, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_get_line_size read the file .xpm and return the line with all size of the
 * 	image xpm.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="char *" name="path">path of xpm file</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static char	*ft_get_line_size(t_info *info, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_perror_exit(E_XPM, info);
	line = get_next_line(fd);
	while (line && line[0] != '"')
	{
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	return (line);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_get_size_xpm(t_info *info, char *path, int i)
 * </summary>
 *
 * <description>
 * 	ft_get_size_xpm get the size of the xpm file.
 * </description>
 *
 * <param type="t_info *" name="info">main structure</param>
 * <param type="char *" name="path">path of xpm file</param>
 * <param type="int" name="i">index of the texture</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_get_size_xpm(t_info *info, char *path, int i)
{
	char	*line;
	char	*sub_line;
	char	**array;

	line = ft_get_line_size(info, path);
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
	ft_free((void **)&sub_line);
	ft_free((void **)&line);
	return ;
}
