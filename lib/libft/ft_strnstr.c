/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:56 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:27:13 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Recherche une sous-chaîne de caractères dans une chaîne de manière 
 * sécurisée avec une limite de taille.
 *
 * Cette fonction recherche la première occurrence de la sous-chaîne `little` 
 * dans la chaîne `big`, jusqu'à une taille maximale `len`. Si `little` est une 
 * chaîne vide, un pointeur vers `big` est renvoyé.
 * Sinon, la recherche se fait jusqu'à une longueur maximale de `len` 
 * caractères. 
 * Si `little` est trouvé dans `big`, un pointeur vers le premier caractère de 
 * la première occurrence de `little` dans `big` est renvoyé.
 * Sinon, un pointeur NULL est renvoyé.
 *
 * @param big La chaîne dans laquelle rechercher.
 * @param little La sous-chaîne à rechercher.
 * @param len La taille maximale de la recherche.
 * @return Un pointeur vers la première occurrence de `little` dans `big`, ou 
 * NULL si non trouvé ou si `len` est atteint.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	litlen;
	size_t	i_b;

	litlen = ft_strlen((char *) little);
	if (little[0] == '\0')
	{
		return ((char *) big);
	}
	i_b = 0;
	while (big[i_b] && i_b < len)
	{
		if (big[i_b] == little[0] && (len - i_b >= litlen))
			if (!ft_strncmp((char *)&big[i_b], (char *)little, litlen))
				return ((char *)&big[i_b]);
		i_b++;
	}
	return (0);
}
