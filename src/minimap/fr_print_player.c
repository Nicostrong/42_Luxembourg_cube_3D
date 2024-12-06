/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_print_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:15:41 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:28:49 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Affiche le joueur sous forme de cercle au centre de la zone donnée.
 * 
 * Cette fonction utilise `ft_put_circle` pour dessiner le joueur comme un
 * cercle centré dans la zone définie par `sx` et `sy`, en partant des 
 * coordonnées (WIDTH - (sx / 2), HEIGHT - (sy / 2)).
 * 
 * @param f Structure des données contenant les informations d'affichage.
 * @param sx Largeur de la zone de rendu.
 * @param sy Hauteur de la zone de rendu.
 */
void	ft_print_player(t_data *f, int sx, int sy)
{
	ft_put_circle(f, WIDTH - (sx / 2), HEIGHT - (sy /2));
}