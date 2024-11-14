/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:43:50 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:23:46 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applique une fonction à chaque caractère d'une chaîne avec son indice 
 * et crée une nouvelle chaîne.
 *
 * Cette fonction applique la fonction `f` à chaque caractère de la chaîne de 
 * caractères `s`, en lui passant l'indice de chaque caractère en premier 
 * argument. Elle crée une nouvelle chaîne avec les résultats de l'application 
 * de `f` à chaque caractère.
 *
 * @param s La chaîne de caractères à parcourir.
 * @param f La fonction à appliquer à chaque caractère avec son indice.
 * @return Un pointeur vers la nouvelle chaîne de caractères créée, ou NULL en 
 * cas d'erreur d'allocation.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	res = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
