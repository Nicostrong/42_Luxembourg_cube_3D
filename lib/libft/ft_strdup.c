/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:50:58 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/18 14:06:54 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplique une chaîne de caractères.
 *
 * Cette fonction duplique la chaîne de caractères `s` et renvoie un pointeur 
 * vers la nouvelle chaîne allouée dynamiquement. La mémoire pour la nouvelle 
 * chaîne est allouée à l'aide de malloc.
 *
 * @param s La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne dupliquée, ou NULL en cas 
 * d'erreur d'allocation.
 */
char	*ft_strdup(const char *s)
{
	int		index;
	char	*dest;

	if (s == NULL)
		return NULL;
	dest = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		dest[index] = s[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
