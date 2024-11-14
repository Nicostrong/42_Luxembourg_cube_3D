/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:37:20 by phkevin           #+#    #+#             */
/*   Updated: 2024/07/26 17:41:27 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare les caractères de deux chaînes de caractères.
 *
 * Cette fonction compare les caractères des chaînes de caractères 
 * `s1` et `s2`.
 * Elle retourne un entier négatif, nul ou positif si `s1` est respectivement 
 * inférieure, égale ou supérieure à `s2`. La comparaison s'arrête si un 
 * caractère nul est atteint dans l'une ou l'autre des chaînes ou si n 
 * caractères ont été comparés.
 *
 * @param s1 La première chaîne de caractères à comparer.
 * @param s2 La deuxième chaîne de caractères à comparer.
 * @return Un entier négatif si la première chaîne est inférieure, 0 si elles 
 * sont égales, ou un entier positif si la première chaîne est supérieure.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int lens;

	i = 0;
	lens = ft_strlen(s1);
	while (i < lens && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < lens && ((s1[i] == 0 && s2[i] != 0) || (s1[i] != 0 && s2[i] == 0)))
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}