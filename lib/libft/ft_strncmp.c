/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:25:44 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:25:27 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare les n premiers caractères de deux chaînes de caractères.
 *
 * Cette fonction compare les n premiers caractères des chaînes de caractères 
 * `s1` et `s2`.
 * Elle retourne un entier négatif, nul ou positif si `s1` est respectivement 
 * inférieure, égale ou supérieure à `s2`. La comparaison s'arrête si un 
 * caractère nul est atteint dans l'une ou l'autre des chaînes ou si n 
 * caractères ont été comparés.
 *
 * @param s1 La première chaîne de caractères à comparer.
 * @param s2 La deuxième chaîne de caractères à comparer.
 * @param n Le nombre de caractères à comparer.
 * @return Un entier négatif si la première chaîne est inférieure, 0 si elles 
 * sont égales, ou un entier positif si la première chaîne est supérieure.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n && ((s1[i] == 0 && s2[i] != 0) || (s1[i] != 0 && s2[i] == 0)))
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}
