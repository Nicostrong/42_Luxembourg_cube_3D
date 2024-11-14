/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:18:50 by phkevin           #+#    #+#             */
/*   Updated: 2024/11/11 13:27:56 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

/**
 * @brief Affiche les rayons émis par le joueur dans une zone définie.
 * 
 * Cette fonction dessine des rayons autour de la position du joueur, 
 * en partant du centre de la zone `(WIDTH - (sx / 2), HEIGHT - (sy / 2))`. 
 * Elle utilise `ft_pixel_put` pour dessiner chaque point des rayons si
 * ceux-ci se trouvent dans les limites de la zone de rendu.
 * 
 * @param f Structure des données contenant les informations d'affichage.
 * @param sx Largeur de la zone de rendu.
 * @param sy Hauteur de la zone de rendu.
 */
void	fr_print_ray(t_data *f, int sx, int sy)
{
	t_pixel		pix;
	int i;
	int ii;
	float baseangle;
	float currangle;

	baseangle = (f->userd.dir) * (PI / 180.0);
	i = 0;
	while (i < NBRAY)
	{
		currangle = baseangle + (i - NBRAY / 2) * (RAYECART *  (PI / 180.0));
		ii = 0;
		while (ii < LENRAY)
		{	
			pix.x = (WIDTH - (sx / 2)) + (ii * cos(currangle));
			pix.y = (HEIGHT - (sy /2)) + (ii * sin(currangle));
			if (pix.x > 0 && pix.x < WIDTH && pix.y > 0 && pix.y < HEIGHT)
				if ((pix.x > (WIDTH - sx)) && (pix.y > (HEIGHT - sy)))
					ft_pixel_put(f, pix.x , pix.y, ft_get_color(255, 255, 255));
			ii++;
		}
		i++;
	}
}