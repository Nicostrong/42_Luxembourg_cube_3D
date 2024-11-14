/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fond.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:08:45 by phkevin           #+#    #+#             */
/*   Updated: 2024/11/11 13:29:02 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

/**
 * @brief Remplit une zone de fond avec une couleur gris ardoise.
 * 
 * Cette fonction remplit la zone située dans le coin inférieur droit
 * de l'affichage avec une couleur gris ardoise, en fonction des
 * dimensions `(sx, sy)` fournies. Chaque pixel de cette zone est coloré
 * via `ft_pixel_put`.
 * 
 * @param f Structure contenant les données d'affichage.
 * @param sx Largeur de la zone de fond.
 * @param sy Hauteur de la zone de fond.
 */
void	ft_print_fond(t_data *f, int sx, int sy)
{
	t_pixel		pix;
	int			y_stop;
	int			x_stop;

	x_stop = WIDTH - sx;
	y_stop = HEIGHT - sy;
	pix.y = HEIGHT - 1;
	while (pix.y > y_stop)
	{
		pix.x = WIDTH - 1;
		while (pix.x > x_stop)
		{
			ft_pixel_put(f, pix.x , pix.y, ft_get_color(112, 128, 144));
			pix.x--;
		}
		pix.y--;
	}
}