/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:06:02 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/21 09:50:05 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h" 

/**
 * @brief Définit la largeur et la hauteur d'une texture.
 *
 * Cette fonction met à jour les dimensions (largeur et hauteur) d'une 
 * texture spécifiée dans la structure de données t_data.
 *
 * @param f Pointeur vers la structure de données contenant les textures.
 * @param i Index de la texture dont les dimensions doivent être définies.
 * @param w Largeur à définir pour la texture.
 * @param h Hauteur à définir pour la texture.
 */
static void SetHW(t_data *f, int i, int w, int h)
{
    f->gfx[i].w = w;
    f->gfx[i].h = h;
}

/**
 * @brief Charge les textures des murs à partir des fichiers XPM.
 *
 * Cette fonction charge les textures des murs orientés Est, Nord, Sud
 * et Ouest depuis des fichiers XPM et met à jour les adresses et 
 * dimensions des textures dans la structure de données t_data.
 *
 * @param f Pointeur vers la structure de données contenant les textures.
 */
void    ft_load_wall(t_data *f)
{
    int i;
    int w;
    int h;

    i = 0;
    while (i < 4)
    {
        if (i == WALL_E)
        {
            f->gfx[i].addr = mlx_xpm_file_to_image(f->mlx, "./gfx/ewall.xpm", &w, &h);
            f->gfx[i].type = WALL_E;
            SetHW(f, i, w, h);
        }
        if (i == WALL_N)
        {
            f->gfx[i].addr = mlx_xpm_file_to_image(f->mlx, "./gfx/nwall.xpm", &w, &h);
            f->gfx[i].type = WALL_N;
            SetHW(f, i, w, h);
        }
        if (i == WALL_S)
        {
            f->gfx[i].addr = mlx_xpm_file_to_image(f->mlx, "./gfx/swall.xpm", &w, &h);
            f->gfx[i].type = WALL_S;
            SetHW(f, i, w, h);
        }
        if (i == WALL_W)
        {
            f->gfx[i].addr = mlx_xpm_file_to_image(f->mlx, "./gfx/wwall.xpm", &w, &h);
            f->gfx[i].type = WALL_W;
            SetHW(f, i, w, h);
        }
        i++;
    }
}

void    ft_load_skfl(t_data *f)
{
    int i;
    int w;
    int h;

    i = 0;
    while (i < NBTEXTURES)
    {
        if (i == SKY)
        {
            f->gfx[i].addr = mlx_xpm_file_to_image(f->mlx, "./gfx/sky.xpm", &w, &h);
            f->gfx[i].type = SKY;
            SetHW(f, i, w, h);
        }
        if (i == FLOOR)
        {
            f->gfx[i].addr = mlx_xpm_file_to_image(f->mlx, "./gfx/floor.xpm", &w, &h);
            f->gfx[i].type = FLOOR;
            SetHW(f, i, w, h);
        }
        if (!f->gfx[i].addr)
        return ;
        i++;
    }
}
