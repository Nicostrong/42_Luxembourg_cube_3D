/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:16:18 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/17 10:35:45 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatène la chaîne source à la fin de la chaîne de destination.
 *
 * Cette fonction ajoute la chaîne `src` à la fin de la chaîne `dest`. Elle
 * met à jour la chaîne `dest` avec les caractères de `src`, tout en respectant
 * la limite de taille imposée par `size`.
 *
 * @param dest Chaîne de destination dans laquelle `src` sera ajoutée.
 * @param src Chaîne source à ajouter à la fin de `dest`.
 * @return La longueur totale des chaînes combinées.
 */
size_t	ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendest;
	size_t	size;

	lensrc = ft_strlen((char *) src);
	lendest = ft_strlen((char *) dest);
	size = lendest + lensrc + 1;
	if ( size >= lendest + 1)
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
