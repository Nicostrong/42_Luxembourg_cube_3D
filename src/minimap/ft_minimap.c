/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/19 19:33:39 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/structures.h"
#include "../../includes/error.h"

static char	**ft_create_map(t_info *info)
{
	char	**map;
	char	*s;
	int		height;
	int		width;
	int		i;

	height = 6;
	if (info->pad_y == 0)
		height = 5;
	width = 8;
	if (info->pad_x == 0)
		width = 7;
	//printf("Dim minimap = %d*%d\n", width, height);
	map = ft_calloc(height + 1, sizeof(char *));
	if (!map)
		ft_perror_exit(E_MALLOC, info);
	i = -1;
	while (++i < height)
	{
		if (info->user_y - 2 + i >= 0 && info->user_y - 2 + i < info->h)
			s = info->map[info->user_y - 2 + i];
		else
			s = NULL;
		if (info->pad_y < 0 && info->pad_x < 0)
			map[i] = ft_formatsubstr(s, info->user_x - 4, width, '$');
		else if (info->pad_y < 0 && info->pad_x >= 0)
			map[i] = ft_formatsubstr(s, info->user_x - 3, width, '$');
		else if (info->pad_y == 0 && info->pad_x < 0)
			map[i] = ft_formatsubstr(s, info->user_x - 4, width, '$');
		else
			map[i] = ft_formatsubstr(s, info->user_x - 3, width, '$');
	}
	map[i] = NULL;
	printf("\nINFO USER\n");
	printf("user_x: %d\n", info->user_x);
	printf("user_y: %d\n", info->user_y);
	printf("pad_x: %d\n", info->pad_x);
	printf("pad_y: %d\n\n", info->pad_y);
	ft_putstrarray(map);
	printf("update reusis\n");
	return (map);
}

static void	ft_set_color(t_info *info, int color, int pos_y, int pos_x)
{
	int	x;
	int	y;
	int	index;

	y = pos_y * 21;
	while (y < ((pos_y + 1) * 21))
	{
		x = 0;
		while (x < ((pos_x + 1) * 21))
		{
			index = (y * info->mini->size) + (x * (info->mini->bpp / 8));
			info->mini->addr[index] = color & 0xFF;
			info->mini->addr[index + 1] = (color >> 8) & 0xFF;
			info->mini->addr[index + 2] = (color >> 16) & 0xFF;
			info->mini->addr[index + 3] = 0xFF;
			x++;
		}
		y++;
	}
	//printf("index: %d couleur => %.6X\n", index, color);
}

static void	ft_char_to_color(char **map, t_info *info)
{
	int	color;
	int	row;
	int	col;

	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			//printf("row: %d, col: %d, map: %c\n", row, col, map[row][col]);
			color = 0x000000;
			//if (map[row][col] == 'P')
			//	color = 0x0000FF;
			if (map[row][col] == '1')
				color = 0xFF0000;	// red
			else if (map[row][col] == ' ')
				color = 0xFFFF00;	// yellow
			else if (map[row][col] == '0' || map[row][col] == 'P')
				color = 0x00FF00;	// green
			else
				color = 0x0000FF;	// blue
			//printf("color a afficher: %.6X\n", color);
			ft_set_color(info, color, row, col);
		}
	}
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
	char	**map;

	map = ft_create_map(info);
	mlx_clear_window(info->mlx, info->mini->win);
	ft_char_to_color(map, info);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	mlx_do_sync(info->mlx);
	if (info->player)
		mlx_put_image_to_window(info->mlx, info->mini->win, info->player->img, \
			(MINI_W / 2) - 10, (MINI_H / 2) - 10);
	else
		ft_put_circle(info, MINI_W / 2, MINI_H / 2);
}