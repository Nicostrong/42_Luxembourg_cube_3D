/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:30:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/20 16:03:00 by nfordoxc         ###   Luxembourg.lu     */
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
	printf("\nINFO USER\n");
	printf("user_x: %d\n", info->user_x);
	printf("user_y: %d\n", info->user_y);
	printf("pad_x: %d\n", info->pad_x);
	printf("pad_y: %d\n\n", info->pad_y);
	ft_putstrarray(map);
	return (map);
}

static int	ft_set_bloc(t_info *info, int color, int py, int px, int sy, int sx)
{
	int	x;
	int	y;
	int	index;

	/*printf("DEBUG SET BLOC");
	printf("\tpx: %d", px);
	printf("\tpy: %d", py);
	printf("\tsy: %d", sy);
	printf("\tsx: %d", sx);
	printf("\tcolor: %.6X\n", color);*/
	y = -1;
	while (++y < sy)
	{
		x = -1;
		while (++x < sx)
		{
			//printf("index = (%d * %d) + (%d * (%d / 8))\n", y, info->mini->size, x, info->mini->bpp);
			index = ((py + y) * info->mini->size) + ((px + x) * (info->mini->bpp / 8));
			if (index < (MINI_W * MINI_H * (info->mini->bpp / 8)))
			{
				info->mini->addr[index] = color & 0xFF;
				info->mini->addr[index + 1] = (color >> 8) & 0xFF;
				info->mini->addr[index + 2] = (color >> 16) & 0xFF;
				info->mini->addr[index + 3] = (color >> 24);
			}
			else
			{
				printf("ERROR : index: %d\n", index);
				printf("index = (%d * %d) + (%d * (%d / 8))\n", y, info->mini->size, x, info->mini->bpp);
			}
		}
		//printf("index: %d couleur => %.6X\n", index, color);
		y++;
	}
	printf("index: %d couleur => %.6X\n", index, color);
	return (index);
}

static void	ft_char_to_color(char **map, t_info *info, int pxs, int pys)
{
	int	color;
	int	row;
	int	col;
	int	sy;
	int	sx;
	int	height;
	int	width;
	int	px;
	int	py;
	int	last_index;

	height = 6;
	if (info->pad_y == 0)
		height = 5;
	width = 8;
	if (info->pad_x == 0)
		width = 7;
	/*printf("\tDEBUG\n");
	printf("\tpx: %d\n", px);
	printf("\tpy: %d\n", py);
	printf("\theight: %d\n", height);
	printf("\twidth: %d\n", width);*/
	row = -1;
	while (++row < height)
	{
		col = -1;
		while (++col < width)
		{
			px = pxs + col * MINI_S_BLOC;
			py = pys + row * MINI_S_BLOC;
			color = 0x88FF0000;
			if (map[row][col] == '1')
				color = 0x000000;
			else if (map[row][col] == ' ')
				color = 0xFFFF00;
			else if (map[row][col] == '0')
				color = 0x00FF00;
			else if (map[row][col] == 'P')
				color = 0x0000FF;
			sy = MINI_S_BLOC;
			sx = MINI_S_BLOC;
			if (row == 0 && py != 0)
			{
				sy = 2 * abs(info->pad_y);
				if (info->pad_y > 0)
					sy = MINI_S_BLOC - (2 * info->pad_y);
			}
			else if (row == height - 1 && info->pad_y != 0)
			{
				sy = MINI_S_BLOC - (2 * abs(info->pad_y));
				if (info->pad_y > 0)
					sy = 2 * info->pad_y;
			}
			if (col == 0 && info->pad_x != 0)
			{
				sx = 2 * abs(info->pad_x);
				if (info->pad_x > 0)
					sx = MINI_S_BLOC - (2 * info->pad_x);
			}
			else if (col == width - 1 && info->pad_x != 0)
			{
				sx = MINI_S_BLOC - (2 * abs(info->pad_x));
				if (info->pad_x > 0)
					sx = 2 * info->pad_x;
			}
			/*printf("DEBUG CTC");
			printf("\tcol: %d", col);
			printf("\trow: %d", row);
			printf("\tsy: %d", sy);
			printf("\tsx: %d\n", sx);*/
			last_index = ft_set_bloc(info, color, row, col, sy, sx, last_index);
		}
	}
	ft_free_array(map);
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

	map = ft_create_map(info);
	mlx_clear_window(info->mlx, info->mini->win);
	ft_char_to_color(map, info, 0, 0);
	mlx_put_image_to_window(info->mlx, info->mini->win, info->mini->img, 0, 0);
	mlx_do_sync(info->mlx);
	/*if (info->player)
		mlx_put_image_to_window(info->mlx, info->mini->win, info->player->img, \
			(MINI_W / 2) - 5, (MINI_H / 2) - 5);
	else
		ft_put_circle(info, MINI_W / 2, MINI_H / 2);*/
}

/*
y = -1;
	while (++y < ((py + 1) * sy) && y < MINI_H)
	{
		x = -1;
		while (++x < ((px + 1) * sx) && x < MINI_W)
		{
			//printf("index = (%d * %d) + (%d * (%d / 8))\n", y, info->mini->size, x, info->mini->bpp);
			index = (y * info->mini->size) + (x * (info->mini->bpp / 8));
			if (index < (MINI_W * MINI_H * (info->mini->bpp / 8)))
			{
				info->mini->addr[index] = color & 0xFF;
				info->mini->addr[index + 1] = (color >> 8) & 0xFF;
				info->mini->addr[index + 2] = (color >> 16) & 0xFF;
				info->mini->addr[index + 3] = (color >> 24);
			}
			else
			{
				printf("ERROR : index: %d\n", index);
				printf("index = (%d * %d) + (%d * (%d / 8))\n", y, info->mini->size, x, info->mini->bpp);
			}
		}
		//printf("index: %d couleur => %.6X\n", index, color);
		y++;
	}
	*/