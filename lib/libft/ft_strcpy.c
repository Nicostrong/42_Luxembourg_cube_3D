/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:59:59 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:21:57 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copie une chaîne de caractères de `src` vers `dest`.
 *
 * La fonction copie les caractères de la chaîne source `src` vers la chaîne
 * de destination `dest` jusqu'à ce qu'elle rencontre le caractère nul (`\0`).
 * La chaîne de destination est terminée par un caractère nul. Si `dest` ou
 * `src` est un pointeur nul, la fonction retourne 0.
 *
 * @param dest Pointeur vers la chaîne de destination où la chaîne source
 *             sera copiée.
 * @param src Pointeur vers la chaîne source à copier.
 * @return La longueur de la chaîne copiée (nombre de caractères).
 */
size_t	ft_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	if (!dest || !src)
		return 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return i;
}
	/*size_t	i;
	size_t size;

	size = ft_strlen((char *)dest) + ft_strlen((char *)src) + 1;
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
	return (ft_strlen((char *)src));
}*/
