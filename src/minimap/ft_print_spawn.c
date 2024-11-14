/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spawn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:13:45 by phkevin           #+#    #+#             */
/*   Updated: 2024/11/11 13:30:18 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

/**
 * @brief Affiche le spawn du joueur en dessinant un cercle à sa position.
 * 
 * Cette fonction itère dans la zone spécifiée par `sx` et `sy` pour dessiner
 * le spawn du joueur en utilisant `ft_put_circle` aux coordonnées de 
 * spawn (f->spposx, f->spposy).
 * 
 * @param f Structure des données contenant les informations d'affichage.
 * @param sx Limite en x pour dessiner le spawn.
 * @param sy Limite en y pour dessiner le spawn.
 */
void	ft_print_spawn(t_data *f, int sx, int sy)
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
			ft_put_circle(f, (HEIGHT - f->spposx), (WIDTH - f->spposy));
			pix.x--;
		}
		pix.y--;
	}



	/*x_stop = 0 + sx;
	y_stop = 0 + sy;
	pix.y = 0;
	while (pix.y != y_stop)
	{
		pix.x = 0;
		while (pix.x != x_stop)
		{
			ft_put_circle(f, f->spposx, f->spposy);
			pix.x++;
		}
		pix.y++;
	}*/
}
