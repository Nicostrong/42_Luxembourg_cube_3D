/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:11 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/structures.h"
#include "../../includes/error.h"

static char	**ft_get_minimap(t_info *info)
{
	char	**map;
	char	*s;
	int		height;
	int		width;
	int		i;

	height = 5;
	if (info->pad_y != 0.0)
		height = 6;
	width = 7;
	if (info->pad_x != 0.0)
		width = 8;
	map = ft_calloc(height + 1, sizeof(char *));
	if (!map)
		ft_perror_exit(E_MALLOC, info);
	i = -1;
	while (++i < height)
	{
		if (info->pad_y >= 0.0 && info->user_y - 2 + i >= 0 && info->user_y - 2 + i < info->h)
			s = info->map[info->user_y - 2 + i];
		else if (info->pad_y < 0.0 && info->user_y - 3 + i >= 0 && info->user_y - 3 + i < info->h)
			s = info->map[info->user_y - 3 + i];
		else
			s = NULL;
		if (info->pad_x < 0.0)
			map[i] = ft_formatsubstr(s, info->user_x - 4, width, '*');
		else
			map[i] = ft_formatsubstr(s, info->user_x - 3, width, '*');
	}
	return (map);
}

static void	ft_get_color(t_info *info, char *line)
{
	int	index;

	index = -1;
	while (line[++index])
	{
		if (line[index] == '1')
			info->colors[index] = 0xFF0000;
		else if (line[index] == '0' || line[index] == 'P')
			info->colors[index] = 0xFFFF00;
		else
			info->colors[index] = 0x0000FF;
	}
	return ;
}

static void	ft_set_img(t_info *info, char **map)
{
	int	m;
	int	w;
	int	x;
	int	y;
	int	index_pxl;
	int	nbr_bloc;

	nbr_bloc = 7;
	if (info->pad_x != 0.0)
		nbr_bloc = 8;
	index_pxl = 0;
	m = -1;
	while (map[++m])
	{
		ft_get_color(info, map[m]);
		y = -1;
		while (++y < (int)info->heights[m])
		{
			w = -1;
			while (++w < nbr_bloc)
			{
				x = -1;
				while (++x < (int)info->widths[w])
				{
					info->mini->addr[index_pxl++] = info->colors[w] & 0xFF;
					info->mini->addr[index_pxl++] = (info->colors[w] >> 8) & 0xFF;
					info->mini->addr[index_pxl++] = (info->colors[w] >> 16) & 0xFF;
					info->mini->addr[index_pxl++] = (info->colors[w] >> 24) &0xFF;
				}
			}
		}
	}
}

/*
 *	set la hauteur des blocs a dessiner
 */
static void	ft_get_heights(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 6)
		info->heights[i] = MINI_S_BLOC;
	if (info->pad_y < 0)
	{
		info->heights[0] = (int)(STEP * fabs(info->pad_y));
		info->heights[5] = MINI_S_BLOC - (int)(STEP * fabs(info->pad_y));
	}
	else if (info->pad_y > 0)
	{
		info->heights[0] = MINI_S_BLOC - (int)(STEP * info->pad_y);
		info->heights[5] = (int)(STEP * info->pad_y);
	}
	else
		info->heights[5] = 0;
	return ;
}

/*
 *	set la largueur des block a dessiner
 */
static void	ft_get_widths(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 8)
		info->widths[i] = MINI_S_BLOC;
	if (info->pad_x < 0)
	{
		info->widths[0] = (int)(STEP * fabs(info->pad_x));
		info->widths[7] = MINI_S_BLOC - (int)(STEP * fabs(info->pad_x));
	}
	else if (info->pad_x > 0)
	{
		info->widths[0] = MINI_S_BLOC - (int)(STEP * info->pad_x);
		info->widths[7] = (int)(STEP * info->pad_x);
	}
	else 
		info->widths[7] = 0;
	return ;
}

/*static int	ft_is_wall(char **map, int x, int y)
{
	if (x < 0 || x >= 7 || y < 0 || y >= 5)
		return (1);
	return (map[y][x] == '1');
}*/

/*static void	ft_draw_ray(t_info *info, double x, double y, char **map)
{
	int		color;
	double	dx;
	double	dy;

	(void)map;
	color = 0x000000;
	dx = cos(info->user_deg);
	dy = sin(info->user_deg);
	while (x > 0 && y > 0 && x < MINI_W && y < MINI_H)
	{
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, color);
		x += dx;
		y += dy;
	}
}*/

static int	ft_get_map_case(int coord, int *sizes, int max_value)
{
	int	i;
	int	cumulative_size;

	i = -1;
	cumulative_size = 0;
	while (++i < max_values)
	{
		cumulative_size += sizes[i];
		if (coord < cumulative_size)
			return (i);
	}
	return (-1);
}

static void	ft_draw_ray(t_info *info, double x, double y, char **map)
{
	int		height;
	int		width;
	int		grid_x;
	int		grid_y;
	double	dx;
	double	dy;

	height = 5;
	if (info->pad_y != 0.0)
		height = 6;
	width = 7;
	if (info->pad_x != 0.0)
		width = 8;
	dx = cos(info->user_deg);
	dy = sin(info->user_deg);
	printf("dx: %.2f\tdy: %.2f\n", dx, dy);
	printf("x: %.2f\ty: %.2f\n", x, y);
	while (x >= 0 && y >= 0 && x < MINI_W && y < MINI_H)
	{
		mlx_pixel_put(info->mlx, info->mini->win, (int)x, (int)y, 0x000000);
		grid_x = ft_get_map_case((int)x, info->widths, width);
		grid_y = ft_get_map_case((int)y, info->heights, height);
		if (grid_x < 0 || grid_x >= width || grid_y < 0 || grid_y >= height)
			break ;
		if (map[grid_y][grid_x] == '1')
			break ;
		printf("x : %f\ty: %f\n", x, y);
		x += dx;
		y += dy;
	}
}

/*
 *	pour afficher la minimap :
 *	1 - on cree un array de char pour representer la minimap
 *	2 - on parcourt chaque ligne de l array
 *	3 - on verifie la valeur de pad_x
 *	4 - on cree un array avec les len de chaque bloc d une ligne
 *	5 - on cree un array avec chaque couleur d une ligne
 *	6 - on verifie la valeur de pad_y et on defini (height_bloc)
 *	7 - on appel height_bloc la fonction pour imprimer une ligne 
 *	8 - on passe a la ligne suivante
 *	9 - on free tous les array cree
 */
void	ft_minimap(t_info *info)
{
	char	**map;

	mlx_clear_window(info->mlx, info->mini->win);
	map = ft_get_minimap(info);
	//ft_putstrarray(map);
	ft_get_widths(info);
	ft_get_heights(info);
	ft_set_img(info, map);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	mlx_do_sync(info->mlx);
	if (info->player)
		mlx_put_image_to_window(info->mlx, info->mini->win, info->player->img, \
			(MINI_W / 2) - 5, (MINI_H / 2) - 5);
	else
		ft_put_circle(info, MINI_W / 2, MINI_H / 2);
	ft_draw_ray(info, (MINI_W / 2) - (info->pad_x * MINI_S_BLOC), (MINI_H / 2) - (info->pad_y * MINI_S_BLOC), map);
	ft_free_array(map);
}