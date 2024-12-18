/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/18 13:09:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/structures.h"
#include "../../includes/error.h"

static char	**ft_create_map(t_info *info)
{
	char	**map;
	int		height;
	int		width;
	int		i;

	height = 6;
	if (info->pad_y == 0)
		height = 5;
	width = 8;
	if (info->pad_x == 0)
		width = 7;
	map = ft_calloc(height, sizeof(char *));
	if (!map)
		ft_perror_exit(E_MALLOC, info);
	i = -1;
	while (++i < height)
	{
		if (info->pad_y < 0 && info->pad_x < 0)
			map[i] = ft_formatsubstr(info->map[info->user_y - 3 + i], info->user_x - 4, width, ' ');
		else if (info->pad_y < 0 && info->pad_x >= 0)
			map[i] = ft_formatsubstr(info->map[info->user_y - 3 + i], info->user_x - 3, width, ' ');
		else if (info->pad_y == 0 && info->pad_x < 0)
			map[i] = ft_formatsubstr(info->map[info->user_y - 2 + i], info->user_x - 4, width, ' ');
		else if (info->pad_y == 0 && info->pad_x >= 0)
			map[i] = ft_formatsubstr(info->map[info->user_y - 2 + i], info->user_x - 3, width, ' ');
		else if (info->pad_y > 0 && info->pad_x < 0)
			map[i] = ft_formatsubstr(info->map[info->user_y - 2 + i], info->user_x - 4, width, ' ');
		else if (info->pad_y > 0 && info->pad_x >= 0)
			map[i] = ft_formatsubstr(info->map[info->user_y - 2 + i], info->user_x - 3, width, ' ');
	}
	ft_putstrarray(map);
	return (map);
}

static char **ft_get_minimap(t_info *info)
{
	char	**map;

	map = ft_create_map(info);
	ft_free_array(map);
	return (map);
}

/*
 *	pour afficher la minimap :
 *	- on recupere la position du joueur
 *	- on recupere les valeur de pad_x et pad_y
 *	- on va construire un array qui representera la minimap
 *	- pour chaque case de la minimap on va afficher une box de couleur
 *	- on libere le tableau de la minimap
 *	- on va afficher le joueur
 */
void	ft_minimap(t_info *info)
{
	int		player_x;
	int		player_y;
	int		pad_x;
	int		pad_y;
	char	**map;

	player_x = info->user_x;
	player_y = info->user_y;
	pad_x = info->pad_x;
	pad_y = info->pad_y;
	map = ft_get_minimap(info);
}

/*
	while (++i < height)
	{
		if (info->pad_y < 0 && info->pad_x < 0)
		{
			if (info->user_y - 3 + i < 0)
				map[i] = ft_strdup("        ");
			else
				map[i] = ft_substr(info->map[info->user_y - 3 + i], info->user_x - 4, width);
		}
		else if (info->pad_y < 0 && info->pad_x >= 0)
		{
			if (info->user_y - 3 + i < 0)
				map[i] = ft_strdup("        ");
			else
				map[i] = ft_substr(info->map[info->user_y - 3 + i], info->user_x - 3, width);
		}
		else if (info->pad_y == 0 && info->pad_x < 0)
		{
			if (info->user_y - 2 + i < 0)
				map[i] = ft_strdup("        ");
			else
				map[i] = ft_substr(info->map[info->user_y - 2 + i], info->user_x - 4, width);
		}
		else if (info->pad_y == 0 && info->pad_x >= 0)
		{
			if (info->user_y - 2 + i < 0)
				map[i] = ft_strdup("        ");
			else
				map[i] = ft_substr(info->map[info->user_y - 2 + i], info->user_x - 3, width);
		}
		else if (info->pad_y > 0 && info->pad_x < 0)
		{
			if (info->user_y - 2 + i < 0)
				map[i] = ft_strdup("        ");
			else
				map[i] = ft_substr(info->map[info->user_y - 2 + i], info->user_x - 4, width);
		}
		else if (info->pad_y > 0 && info->pad_x >= 0)
		{
			if (info->user_y - 2 + i < 0)
				map[i] = ft_strdup("        ");
			else
				map[i] = ft_substr(info->map[info->user_y - 2 + i], info->user_x - 3, width);
		}
	}
*/