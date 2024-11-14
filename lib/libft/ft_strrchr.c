/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:58:32 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:27:51 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Recherche le dernier caractère donné dans une chaîne de caractères.
 *
 * Cette fonction recherche la dernière occurrence du caractère `c` dans la 
 * chaîne de caractères `s`.
 * Elle retourne un pointeur vers la dernière occurrence de `c` dans `s`, ou 
 * NULL si `c` n'est pas trouvé.
 *
 * @param s La chaîne de caractères dans laquelle rechercher.
 * @param c Le caractère à rechercher.
 * @return Un pointeur vers la dernière occurrence de `c` dans `s`, ou NULL 
 * si non trouvé.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (c > 127)
		return ((char *) s);
	while (*s)
	{
		if (*s == c)
			last = (char *) s;
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (last);
}
