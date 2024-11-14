/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_para.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:45:34 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/21 14:48:56 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

/**
 * @brief Définit les drapeaux de texture pour le ciel et le sol.
 *
 * Cette fonction vérifie la chaîne d'entrée et définit les drapeaux dans
 * la structure t_data pour différents types de textures : sol, plafond,
 * texture graphique du sol et du ciel.
 * 
 * @param str La chaîne d'entrée pour vérifier les identifiants de texture 
 * ('F ', 'C ', 'FT', 'CT').
 * @param f La structure t_data où les drapeaux pour les textures graphiques 
 * seront définis.
 */
static void	is_text_skyfloor(char *str, t_data *f)
{
	int i;

	i = 0;
	if (str[i] == 'F' && str[i + 1] == ' ')
	f->gfxf = 1;
	if (str[i] == 'C' && str[i + 1] == ' ')
	f->gfxc = 1;
	if (str[i] == 'F' && str[i + 1] == 'T')
		f->gfxfloor = 1;
	if (str[i] == 'C' && str[i + 1] == 'T')
		f->gfxsky = 1;
}

/**
 * @brief Valide et définit les paramètres de texture pour les murs et autres.
 *
 * Cette fonction analyse la chaîne d'entrée pour identifier les paramètres
 * de texture associés aux murs (Nord, Sud, Ouest, Est) ou appelle 
 * is_text_skyfloor pour les autres types de textures comme le sol et le ciel.
 * 
 * @param str La chaîne d'entrée pour vérifier les identifiants de texture
 * (ex: 'NO', 'SO', 'WE', 'EA').
 * @param f La structure t_data où les drapeaux pour les textures seront 
 * définis.
 */
void	ft_val_para(char *str, t_data *f)
{
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O')
		f->gfxno = 1;
	else if (str[i] == 'S' && str[i + 1] == 'O')
		f->gfxso = 1;
	else if (str[i] == 'W' && str[i + 1] == 'E')
		f->gfxwe = 1;
	else if (str[i] == 'E' && str[i + 1] == 'A')
		f->gfxea = 1;
	else if (str[i] == 'M' && str[i + 1] == 'A' && str[i + 2] == 'P')
		f->readmap = 1;
	else
		is_text_skyfloor(str, f);
}