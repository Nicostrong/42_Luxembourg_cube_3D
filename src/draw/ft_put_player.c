/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:28:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/13 09:47:03 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/setting_game.h"
#include "../../includes/minimap.h"
#include "../../includes/structures.h"

static void	ft_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->mini->addr + (y * info->mini->size + x * (info->mini->bpp / 8));
	*(unsigned int*)dst = color;
}

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
static int	ft_get_color(int t,int r, int g, int b)
{
	return (trgb(t, r, g, b));
}

/*
 * Fonction pour dessiner un joueur
 */
static void coloris_axe_2(t_info *info, int centx, int centy, int x, int y)
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
			ft_pixel_put(info, i, py, ft_get_color(0, 0, 0, 255));
		if (ny >= 0 && (ny <= HEIGHT || ny <= WIDTH))
			ft_pixel_put(info, i, ny, ft_get_color(0, 0, 0, 255));
		i++;
	}
}

/*
 *	Fonction pour dessiner un cercle
 */
static void coloris_axe_1(t_info *info, int centx, int centy, int x, int y)
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
			ft_pixel_put(info, i, py, ft_get_color(0, 0, 0, 255));
		if (ny >= 0 && (ny <= HEIGHT || ny <= WIDTH))
			ft_pixel_put(info, i, ny, ft_get_color(0, 0, 0, 255));
		i++;
	}
}

/*
 * Fonction pour dessiner un cercle
 */
void	ft_put_circle(t_info *info, int centx, int centy)
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
		coloris_axe_1(info, centx, centy, x, y);
		coloris_axe_2(info, centx, centy, x, y);
		x++;
		if (x * x  + y * y > PRAY * PRAY)
			y--;
	}
}