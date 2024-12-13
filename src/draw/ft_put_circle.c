/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:26:39 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/13 13:26:58 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"

/**
 * @brief Dessine des lignes verticales pour un cercle à partir du centre.
 * 
 * Cette fonction utilise les coordonnées fournies pour dessiner des pixels
 * aux positions verticales du cercle en fonction de l'axe y. Les pixels
 * sont colorés en vert et les positions sont vérifiées pour s'assurer
 * qu'elles restent dans les limites de la fenêtre.
 * 
 * @param f Structure des données contenant les informations d'affichage.
 * @param centx Coordonnée x du centre du cercle.
 * @param centy Coordonnée y du centre du cercle.
 * @param x Distance verticale par rapport au centre.
 * @param y Distance horizontale par rapport au centre.
 */
static void coloris_axe_2(t_data *f, int centx, int centy, int x, int y)
{
	int i;
	int px;
	int nx;
	int py;
	int ny;

	px = centx + y;
	nx = centx - y;
	py = centy + x;
	ny = centy - x;
	i = nx;
	while (i <= px)
	{
		if (py >= 0 && (py <= HEIGHT || py <= WIDTH ))
			ft_pixel_put(f, i, py, ft_get_color(0, 255, 0));
		if (ny >= 0 && (ny <= HEIGHT || ny <= WIDTH))
			ft_pixel_put(f, i, ny, ft_get_color(0, 255, 0));
		i++;
	}
}

/**
 * @brief Dessine des lignes horizontales pour un cercle à partir du centre.
 * 
 * Cette fonction utilise les coordonnées fournies pour dessiner des pixels
 * aux positions horizontales du cercle en fonction de l'axe x. Les pixels
 * sont colorés en vert et les positions sont vérifiées pour s'assurer
 * qu'elles restent dans les limites de la fenêtre.
 * 
 * @param f Structure des données contenant les informations d'affichage.
 * @param centx Coordonnée x du centre du cercle.
 * @param centy Coordonnée y du centre du cercle.
 * @param x Distance horizontale par rapport au centre.
 * @param y Distance verticale par rapport au centre.
 */
static void coloris_axe_1(t_data *f, int centx, int centy, int x, int y)
{
	int i;
	int px;
	int nx;
	int py;
	int ny;

	px = centx + x;
	nx = centx - x;
	py = centy + y;
	ny = centy - y;
	i = nx;
	while (i <= px)
	{
		if (py >= 0 && (py <= HEIGHT || py <= WIDTH))
			ft_pixel_put(f, i, py, ft_get_color(0, 255, 0));
		if (ny >= 0 && (ny <= HEIGHT || ny <= WIDTH))
			ft_pixel_put(f, i, ny, ft_get_color(0, 255, 0));
		i++;
	}
}

/**
 * @brief Dessine un cercle centré aux coordonnées spécifiées.
 * 
 * Cette fonction utilise l'algorithme de tracé de cercle pour dessiner
 * un cercle dans la structure de données fournie. Elle limite les
 * coordonnées de centre pour s'assurer que le cercle est dessiné dans
 * les limites de la fenêtre.
 * 
 * @param f Structure des données contenant les informations d'affichage.
 * @param centx Coordonnée x du centre du cercle.
 * @param centy Coordonnée y du centre du cercle.
 */
void	ft_put_circle(t_data *f, int centx, int centy)
{ 
	int x;
	int y;

	x = 0;
	y = PRAY;
	if (centx < 0 || centx >= WIDTH - PRAY || 
	centy < 0 - PRAY || centy >= HEIGHT - PRAY)
		return ;
	while (y >= x)
	{
		coloris_axe_1(f, centx, centy, x, y);
		coloris_axe_2(f, centx, centy, x, y);
		x++;
		if (x * x  + y * y > PRAY * PRAY)
			y--;
	}
}
