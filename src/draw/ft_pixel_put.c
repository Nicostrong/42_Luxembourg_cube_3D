/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:54:20 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:28:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Place un pixel de couleur donnée à des coordonnées spécifiques.
 *
 * Calcule l'adresse de la position en fonction des coordonnées (x, y) et y 
 * place la couleur spécifiée. La couleur est stockée sous forme de valeur 
 * entière dans `dst`.
 *
 * @param data Pointeur vers la structure de données contenant l'image.
 * @param x Coordonnée x du pixel à colorier.
 * @param y Coordonnée y du pixel à colorier.
 * @param color Couleur du pixel au format entier.
 */
void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}