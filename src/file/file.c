/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:53:15 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:28:37 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Initialise le chemin du fichier dans la structure t_data.
 *
 * Cette fonction alloue de la mémoire pour le chemin d'un fichier dans la 
 * structure `t_data` en concaténant la constante `PMAP` avec la chaîne 
 * `str`. Si l'allocation échoue, la fonction retourne sans effectuer 
 * d'autres actions.
 *
 * @param f Pointeur vers la structure t_data à initialiser.
 * @param str Chaîne de caractères à concaténer à PMAP pour former le 
 * chemin du fichier.
 */
void	fic_init(t_data *f, char *str)
{
	if (f == NULL || str == NULL)
		return	;
	f->fic = malloc((ft_strlen(PMAP) + ft_strlen(str) + 1) * sizeof(char));
	if (!f->fic)
		ft_errclose(f);
	ft_strcpy(f->fic, PMAP);
	ft_strcat(f->fic, str);
}

/**
 * @brief Vérifie si un fichier existe.
 *
 * Cette fonction utilise la fonction `access` pour déterminer si le fichier
 * spécifié par le chemin `fic` existe. Si le fichier existe, la fonction
 * retourne 1, sinon elle retourne 0.
 *
 * @param fic Chemin du fichier à vérifier.
 * @return 1 si le fichier existe, 0 sinon.
 */
int is_ficexiste(char *fic)
{
	if (access(fic, F_OK) == 0)
        return 1;
	else
        return 0;
}