/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:16:18 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:21:21 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatène deux chaînes de caractères avec une limite de taille.
 *
 * Cette fonction concatène les chaînes de caractères `src` à la fin de la 
 * chaîne `dest`, en prenant en compte la taille maximale `size`. La chaîne 
 * `dest` est garantie d'être terminée par un caractère nul.
 *
 * @param dest La chaîne de destination dans laquelle concaténer.
 * @param src La chaîne à concaténer.
 * @param size La taille maximale de la chaîne de destination.
 * @return La longueur totale de la chaîne résultante, qui aurait été obtenue 
 * si aucun tronquage n'avait eu lieu. Cette valeur est limitée à la taille 
 * `size` fournie.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendest;

	lensrc = ft_strlen((char *) src);
	lendest = ft_strlen((char *) dest);
	if (size >= lendest + 1)
	{
		i = 0;
		while (src[i] != '\0' && lendest + i < size - 1)
		{
			dest[lendest + i] = src[i];
			i++;
		}
		dest[lendest + i] = '\0';
		return (lendest + lensrc);
	}
	else
		return (size + lensrc);
}
