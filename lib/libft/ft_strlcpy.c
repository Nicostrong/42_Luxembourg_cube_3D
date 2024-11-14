/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:59:59 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:21:57 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copie une chaîne de caractères en toute sécurité avec une limite de 
 * taille.
 *
 * Cette fonction copie la chaîne de caractères `src` dans la chaîne `dest` 
 * avec une limite de taille `size`. Elle garantit que la chaîne `dest` est 
 * toujours terminée par un caractère nul.
 * Si `size` est nul, la fonction ne fait rien et renvoie la longueur de `src`.
 *
 * @param dest La chaîne de destination dans laquelle copier.
 * @param src La chaîne à copier.
 * @param size La taille maximale de la chaîne de destination.
 * @return La longueur totale de la chaîne source.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size != 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
