/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:53:26 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:05:14 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Recherche un caractère dans une zone mémoire.
 *
 * Cette fonction recherche le caractère `c` dans les `n` premiers octets de la
 * zone mémoire pointée par `s`. Si le caractère est trouvé, un pointeur vers 
 * la première occurrence du caractère est retourné. Sinon, la fonction 
 * retourne NULL.
 *
 * @param s Un pointeur vers la zone mémoire à analyser.
 * @param c Le caractère à rechercher.
 * @param n Le nombre d'octets à analyser.
 * @return Un pointeur vers la première occurrence de `c` dans la zone mémoire,
 * ou NULL si `c` n'est pas trouvé.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n-- > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
