/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:45:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/17 12:00:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/raycasting.h"
#include "../../includes/structures.h"

static void	ft_set_pixel(t_win *win, int x, int y_start, int y_end, int color)
{
	char	*pixel;
	int		y;

	if (x < 0 || x >= WIDTH || y_end < 0 || y_start >= HEIGHT)
		return ;
	if (y_start < 0)
		y_start = 0;
	if (y_end >= HEIGHT)
		y_end = HEIGHT - 1;
	y = 0;
	while (y < y_start)
	{
		pixel = win->addr + (y * win->size + x * (win->bpp / 8));
		*(unsigned int *)pixel = 0x0000FF;
		y++;
	}
	while (y < y_end)
	{
		pixel = win->addr + (y * win->size + x * (win->bpp / 8));
		*(unsigned int *)pixel = color;
		y++;
	}
	while (y < HEIGHT)
	{
		pixel = win->addr + (y * win->size + x * (win->bpp / 8));
		*(unsigned int *)pixel = 0x00FFFF;;
		y++;
	}
}

/*static void	ft_draw_diag(t_win *win, int x_start, int x_end, int draw_start, int draw_end, int next_draw_start, int next_draw_end, int color)
{
	int	band_width;
	int	x;
	int	y_start;
	int	y_end;

	band_width = x_end - x_start;
	x = x_start;
	while (x < x_end)
	{
		y_start = draw_start + (x - x_start) * (next_draw_start - draw_start) / band_width;
		y_end = draw_end + (x - x_start) * (next_draw_end - draw_end) / band_width;
		ft_set_pixel(win, x, y_start, y_end, color);
		x++;
	}
}*/

/*
Plan détaillé :
1 Récupérer les informations nécessaires :
	Position du joueur (player_x, player_y)
	Direction de la vue du joueur (dir_x, dir_y)
	Plan de la caméra (plane_x, plane_y)
	La carte 2D qui contient les informations des murs (map[x][y]).
2 Tracer les rayons :
	Diviser la fenêtre en "colonnes" correspondant à chaque pixel horizontal.
	Pour chaque colonne, calculer la direction du rayon.
	Calculer l'intersection du rayon avec les murs en utilisant l'algorithme DDA (Digital Differential Analyzer).
3 Calculer la hauteur des murs :
	Utiliser la distance entre le joueur et le mur pour calculer la hauteur à afficher.
	Plus la distance est grande, plus le mur semble petit.
4 Dessiner la scène 3D :
	Pour chaque colonne, dessiner un segment vertical correspondant à la hauteur du mur.
	Ajouter des textures si nécessaire.
*/
void	ft_raycasting(t_info *info)
{
	double	camera_x, ray_dir_x, ray_dir_y;
	double	dir_x, dir_y, plane_x, plane_y;
	double	delta_dist_x, delta_dist_y, side_dist_x, side_dist_y, perp_wall_dist;
	int		map_x, map_y, step_x, step_y, hit, side;
	int		line_height, draw_start, draw_end;
	int		prev_draw_end; // next_draw_start, next_draw_end; // prev_draw_start,
	//int		section_width = WIDTH / NBRAY; // Largeur d'une section (par exemple, 100 pixels)
	int		x, color;  //i

	// Direction et plan de la caméra
	dir_x = cos(info->user_deg);
	dir_y = sin(info->user_deg);
	plane_x = -dir_y * tan(FOV / 2.0);
	plane_y = dir_x * tan(FOV / 2.0);

	prev_draw_end = HEIGHT / 2; // Point de départ pour le sol (base du mur précédent)

	// Parcourir chaque colonne de l'écran
	for (x = 0; x < WIDTH; x++)
	{
		// Calcul de la direction du rayon
		camera_x = 2 * x / (double)(WIDTH - 1) - 1;
		ray_dir_x = dir_x + plane_x * camera_x;
		ray_dir_y = dir_y + plane_y * camera_x;

		// Initialisation de DDA
		map_x = (int)info->user_x;
		map_y = (int)info->user_y;

		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (info->user_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - info->user_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (info->user_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - info->user_y) * delta_dist_y;
		}

		// Boucle DDA
		hit = 0;
		while (!hit)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			hit = info->map[map_y][map_x] == '1';
		}

		// Calcul de la distance perpendiculaire
		if (side == 0)
			perp_wall_dist = (map_x - info->user_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - info->user_y + (1 - step_y) / 2) / ray_dir_y;

		// Calcul de la hauteur du mur
		line_height = (int)(HEIGHT / perp_wall_dist);

		// Limites de dessin
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0) draw_start = 0;

		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT) draw_end = HEIGHT - 1;

		// Déterminer la couleur du mur
		color = (side == 0) ? 0xFF0000 : 0xAAAAAA;

		// Dessiner le mur
		ft_set_pixel(info->game, x, draw_start, draw_end, color);

		// Ajouter une ligne horizontale si une discontinuité est détectée
		if (draw_start > prev_draw_end)
		{
			// Ligne horizontale pour délimiter le sol
			ft_set_pixel(info->game, x, prev_draw_end, draw_start, 0x000000); // Noir
		}
		// Mettre à jour la base du mur précédent
		prev_draw_end = draw_end;
	}
	// Afficher l'image mise à jour
	mlx_put_image_to_window(info->mlx, info->game->win, info->game->img, 0, 0);
}

