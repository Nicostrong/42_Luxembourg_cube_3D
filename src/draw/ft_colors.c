/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:23:06 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/13 13:25:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Crée une couleur en format entier à partir des valeurs T, R, G et B.
 *
 * La fonction utilise les décalages binaires pour combiner les valeurs de 
 * transparence (T), rouge (R), vert (G), et bleu (B) en une seule valeur 
 * entière. Cette valeur peut ensuite être utilisée pour représenter une 
 * couleur dans un format spécifique.
 *
 * @param t Valeur de transparence (0-255).
 * @param r Composante rouge (0-255).
 * @param g Composante verte (0-255).
 * @param b Composante bleue (0-255).
 * @return Couleur résultante en format entier (TRGB).
 */
static int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Génère une couleur en entier avec les composantes rouge, vert et bleu.
 *
 * Cette fonction crée une couleur en utilisant `trgb`, en fixant la 
 * transparence à 0 et en combinant les valeurs rouge, verte et bleue.
 *
 * @param t Composante transparence (0-255).
 * @param r Composante rouge de la couleur (0-255).
 * @param g Composante verte de la couleur (0-255).
 * @param b Composante bleue de la couleur (0-255).
 * @return Couleur en format entier (RGB).
 */
int	ft_get_color(int t,int r, int g, int b)
{
	return (trgb(t, r, g, b));
}
