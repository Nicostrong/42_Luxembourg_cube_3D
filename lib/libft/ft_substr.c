/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:00:02 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:29:41 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extrait une sous-chaîne de caractères à partir d'une position donnée.
 *
 * Cette fonction extrait une sous-chaîne de caractères de la chaîne `s` à 
 * partir de l'index `start` jusqu'à une longueur maximale de `len` caractères.
 * La sous-chaîne extraite est allouée dynamiquement.
 *
 * @param s La chaîne source à partir de laquelle extraire la sous-chaîne.
 * @param start L'index de départ à partir duquel extraire la sous-chaîne.
 * @param len La longueur maximale de la sous-chaîne à extraire.
 * @return Une nouvelle chaîne contenant la sous-chaîne extraite, ou NULL en 
 * cas d'échec d'allocation mémoire.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		len_n;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	len_n = ft_strlen(s) - start + 1;
	if (len_n > (int)len)
		len_n = len + 1;
	dest = (char *)malloc(len_n * sizeof(char));
	if (!dest || !s)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len--)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
