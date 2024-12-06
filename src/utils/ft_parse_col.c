/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:15:09 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:29:39 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Convertit une chaîne de caractères en tableau de couleurs RGB.
 * 
 * Cette fonction divise la chaîne `str` en trois sous-chaînes séparées par des
 * virgules, puis les convertit en valeurs entières, représentant les
 * composantes rouge, verte et bleue (RGB).
 * 
 * @param str La chaîne de caractères à analyser (format "R,G,B").
 * @return Un tableau de trois entiers représentant les valeurs RGB, ou `NULL`
 *         en cas d'erreur d'allocation.
 */
int	*ft_parse_col(char *str)
{
	char	**strsplit;
	int		*col;

	strsplit = ft_split(str, ',');
	col = (int *)malloc(3 * sizeof(int));
	if (!col)
		return (NULL);
	col[0] = ft_atoi(strsplit[0]);
	col[1] = ft_atoi(strsplit[1]);
	col[2] = ft_atoi(strsplit[2]);
	return (col);
}
