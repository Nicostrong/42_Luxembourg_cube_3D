/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:41:39 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:30:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Vérifie si toutes les textures graphiques nécessaires sont 
 * configurées.
 *
 * Cette fonction vérifie si les textures pour les murs (Nord, Sud, Ouest, Est)
 * sont bien configurées ainsi que les textures ou les couleurs pour le sol
 * et le ciel. Si toutes les textures ou couleurs sont correctement définies,
 * la fonction renvoie 1, sinon elle renvoie 0.
 * 
 * @param f La structure t_data contenant les indicateurs de configuration
 * des textures et couleurs.
 * 
 * @return 1 si toutes les textures nécessaires sont configurées, 0 sinon.
 */
static int	confgfx(t_data *f)
{
	if (f->gfxno == 1 && f->gfxso == 1 && f->gfxwe == 1 && f->gfxea == 1 
	&& f->readmap == 1)
	{
		if ((f->gfxfloor == 1 || f->gfxf == 1) 
		&& (f->gfxsky == 1 || f->gfxc == 1))
			return (1);
	
	}
	return (0);
}

/**
 * @brief Initialise les paramètres de la structure t_data.
 *
 * Cette fonction initialise les membres de la structure `t_data` à leurs
 * valeurs par défaut. Elle prépare la structure pour une utilisation ultérieure
 * dans le programme.
 *
 * @param f Pointeur vers la structure t_data à initialiser.
 */
static void	init_data(t_data *f)
{
	f->gfxno = 0;
	f->gfxso = 0;
	f->gfxwe = 0;
	f->gfxea = 0;
	f->isspawn = 0;
	f->gfxfloor = 0;
	f->gfxf = 0;
	f->gfxsky = 0;
	f->gfxc = 0;
	f->readmap = 0;
	f->ymap = 0;
	f->xmap = 0;
	f->ismapvalid = 1;
	f->isspawn = 0;
	f->spposx = 0;
	f->spposy = 0;
}

/**
 * @brief Valide et analyse le fichier de configuration pour les paramètres
 * graphiques.
 *
 * Cette fonction ouvre un fichier de configuration en lecture et lit chaque
 * ligne pour vérifier et valider les paramètres de configuration graphiques.
 * Si un paramètre est manquant ou incorrect, une erreur est affichée et la
 * fonction se termine en fermant les ressources.
 * 
 * @param fic Le chemin du fichier de configuration.
 * @param f   La structure t_data contenant les paramètres graphiques à 
 * valider.
 */
void    ft_vali(char *fic, t_data *f)
{
    int		fd;
    char	*buffer;

    fd = open(fic, O_RDONLY);
	init_data(f);
    while(1)
    {
        buffer = get_next_line(fd);
        if (buffer == NULL)
            break;
		if (f->readmap == 0)
			ft_val_para(buffer, f);
		else
			ft_size_map(buffer, f);
        free(buffer);
        buffer = NULL;
    }
	if(confgfx(f) == 0)
	{
		ft_printf_error("\033[1;31m Error\n - Missing parameter \033[0m\n");
		ft_errclose(f);
	}
	ft_write_map(fic, f);
}