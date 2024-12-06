/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:47:03 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:29:28 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Libère les ressources allouées par la bibliothèque MLX.
 *
 * Cette fonction parcourt les textures et les libère, détruit la fenêtre,
 * termine la boucle MLX, et libère la mémoire associée à l'instance MLX.
 *
 * @param f Pointeur vers la structure de données contenant les informations
 *          sur MLX, les textures et la fenêtre.
 */
static void	ft_freemlx(t_data *f)
{
	int	i;

	i = 1;
	if (f->img && f->mlx)
	{
		while (i < NBTEXTURES)
		{
			if (f->gfx[i].addr)
				mlx_destroy_image(f->mlx, f->gfx[i].addr);
			i++;
		}
	}
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}

/**
 * @brief Ferme l'application et libère les ressources allouées.
 *
 * Cette fonction libère les ressources de la structure `t_data`, telles que
 * le fichier de configuration (fic), la carte (map), ainsi que les ressources 
 * liées à MLX (images, fenêtre, etc.). Elle affiche un message de fermeture 
 * et force la sortie du programme.
 *
 * @param f Pointeur vers la structure t_data contenant les ressources à 
 * libérer.
 * @return Cette fonction ne retourne jamais car elle appelle exit(0).
 */
int	ft_close(t_data *f)
{
	if (f)
	{
		if (f->fic)
		{
			free(f->fic);
			f->fic = NULL;
		}
		if (f->map)
		{
			f->map = ft_free_array(f->map);
		}
		ft_freemlx(f);
	}
	printf("close %s\n", TITLE);
	exit(0);
}

/**
 * @brief Ferme le programme en cas d'erreur et libère les ressources.
 *
 * Cette fonction est appelée en cas d'erreur pour libérer les ressources
 * allouées avant de fermer le programme. Elle vérifie si des éléments
 * de la structure t_data ont été alloués, puis les libère (comme le fichier 
 * de configuration et la carte). Enfin, elle affiche un message indiquant la
 * fermeture du programme avant de forcer l'arrêt avec exit(1).
 *
 * @param f Pointeur vers la structure t_data contenant les données à libérer.
 */
void	ft_errclose(t_data *f)
{
	if (f)
	{
		if (f->fic != NULL)
			free(f->fic);
		if (f->map != NULL)
			f->map = ft_free_array(f->map);
	}
	printf("close %s\n", TITLE);
	exit (1);
}
