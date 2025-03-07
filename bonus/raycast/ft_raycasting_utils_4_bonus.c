/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils_4_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:43:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 18:09:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/raycasting_bonus.h"

/**
 * @brief Gère la collision avec une porte sur l'axe X.
 * 
 * Cette fonction met à jour les distances et les coordonnées 
 * de la carte lorsque le rayon traverse une porte sur l'axe X. 
 * Elle assigne également la texture correspondante.
 * 
 * @param info Structure contenant les informations du jeu.
 * @param ray Structure contenant les données du raycasting.
 */
static void	ft_hit_door_x(t_info *info, t_raycast *ray)
{
	ray->side_dist_x += ray->delta_dist_x;
	ray->map_x += ray->step_x;
	ray->texture = info->door;
	ray->door = 1;
	return ;
}

/**
 * @brief Gère la détection d'une porte lors du raycasting.
 * 
 * Cette fonction appelle ft_hit_door_x pour traiter la 
 * collision avec une porte sur l'axe X.
 * 
 * @param info Structure contenant les informations du jeu.
 * @param ray Structure contenant les données du raycasting.
 */
void	ft_hit_door(t_info *info, t_raycast *ray)
{
	ft_hit_door_x(info, ray);
	return ;
}

/**
 * @brief Dessine le ciel dans la fenêtre de jeu.
 * 
 * Cette fonction remplit la moitié supérieure de l'écran 
 * avec une texture de ciel si elle est activée, sinon 
 * avec une couleur unie.
 * 
 * @param info Structure contenant les informations du jeu.
 * @param x Coordonnée en x (non utilisée directement ici).
 * @param y Coordonnée en y, point de départ du dessin.
 */
void	ft_put_sky(t_info *info, int x, int y)
{
	int		pixel;

	while (y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if ((y < HEIGHT / 2) && info->use_s_img)
			{
				pixel = ft_get_pixel_color(info->s_img, (x % info->s_img->w), \
					(y % info->s_img->h));
				ft_put_pixel_color(info->game, x, y, pixel);
			}
			else
				ft_put_pixel_color(info->game, x, y, info->sky_color->color);
		}
		y++;
	}
	return ;
}

/**
 * @brief Dessine le sol dans la fenêtre de jeu.
 * 
 * Cette fonction remplit la moitié inférieure de l'écran 
 * avec une texture de sol si elle est activée, sinon 
 * avec une couleur unie.
 * 
 * @param info Structure contenant les informations du jeu.
 * @param x Coordonnée en x (non utilisée directement ici).
 * @param y Coordonnée en y, point de départ du dessin.
 */
void	ft_put_floor(t_info *info, int x, int y)
{
	int		pixel;

	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if ((y > HEIGHT / 2) && info->use_f_img)
			{
				pixel = ft_get_pixel_color(info->f_img, (x % info->f_img->w), \
					(y % info->f_img->h));
				ft_put_pixel_color(info->game, x, y, pixel);
			}
			else
				ft_put_pixel_color(info->game, x, y, info->floor_color->color);
		}
		y++;
	}
	return ;
}
