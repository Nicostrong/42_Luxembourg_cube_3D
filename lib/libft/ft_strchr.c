/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:23:31 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:17:58 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Cherche la première occurrence d'un caractère dans une chaîne de 
 * caractères.
 *
 * Cette fonction recherche la première occurrence du caractère `c` dans la 
 * chaîne de caractères `s`.
 *
 * @param s La chaîne de caractères à rechercher.
 * @param c Le caractère à trouver.
 * @return Un pointeur vers la première occurrence du caractère dans la chaîne, 
 * ou NULL si le caractère n'est pas trouvé.
 */
char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
		return ((char *) s);
	while (*s)
	{
		if (*s == c)
		{
			return ((char *) s);
		}
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (0);
}
