/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:11:28 by phkevin           #+#    #+#             */
/*   Updated: 2024/11/18 14:19:43 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

/**
 * @brief Affiche un mur en noir dans une zone définie.
 * 
 * Cette fonction remplit de noir la zone située dans le coin inférieur
 * droit de l'affichage, délimitée par les paramètres `(sx, sy)`. Elle utilise
 * `ft_pixel_put` pour chaque pixel dans cette zone.
 * 
 * @param f Structure des données contenant les informations d'affichage.
 * @param sx Largeur de la zone mur.
 * @param sy Hauteur de la zone mur. 
 */
void	ft_print_wall(t_data *f, int sx, int sy)
{
	int x_center;
	int y_center;
	int x_start;
	int y_start;
	int			*col;
	int map_x;
	int map_y; // Coordonnées correspondantes dans la carte
	int wsize;
	//int hwsize;
	//int wwsize;

	// Epaisseur mûre
	wsize = 4;
	
	// Initialiser la couleur du mur
	col = ft_parse_col(CBLACK);

	// Calculer le centre de la minimap
	x_center = WIDTH - (sx / 2);
	y_center = HEIGHT - (sy / 2);

	printf("sx %d, sy %d", x_center, y_center);

	// Initialiser les coordonnées de départ
	y_start = y_center;
	while (y_start >= HEIGHT - sy && y_start <= HEIGHT)
	{
		x_start = x_center;
		while (x_start >= WIDTH - sx && x_start <= WIDTH)
		{
			// Calculer la position correspondante dans la carte
			map_x = (x_start - (WIDTH - sx)) / PRAY;
			map_y = (y_start - (HEIGHT - sy)) / PRAY;

			// Calculer la distance entre l'utilisateur et la position actuelle
			int distance = abs(f->userd.coox - map_x) + abs(f->userd.cooy - map_y);

			// Vérifier si la position dans la carte est un mur ('1')
			if (f->map[map_y][map_x] == '1' && distance <= 50)
			{
				// Dessiner le mur (couleur noire par exemple)
				ft_pixel_put(f, x_start + (sx / 4), y_start + (sy / 4), ft_get_color(col[0], col[1], col[2]));
			}

			// Déplacement vers la droite ou la gauche depuis le centre
			if (x_start <= x_center)
				x_start--;
			else
				x_start++;
		}

		// Déplacement vers le haut ou le bas depuis le centre
		if (y_start <= y_center)
			y_start--;
		else
			y_start++;
	}
	ft_put_circle(f, y_center, x_center);
	free(col);





	/*t_pixel		pix;
	int			y_stop;
	int			x_stop;
	int			*col;

	x_stop = WIDTH - sx;
	y_stop = HEIGHT - sy;
	pix.y = HEIGHT - 1;
	col = ft_parse_col(CBLACK);
	while (pix.y > y_stop)
	{
		pix.x = WIDTH - 1;
		while (pix.x > x_stop)
		{
			ft_pixel_put(f, pix.x , pix.y, ft_get_color(col[0], col[1], col[2]));
			pix.x--;
		}
		pix.y--;
	}
	free(col);*/
}
