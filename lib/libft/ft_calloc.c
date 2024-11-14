/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:51:07 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:43:16 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Alloue et initialise la mémoire pour un tableau.
 *
 * Cette fonction alloue la mémoire pour un tableau de `nmemb` éléments de 
 * `size` octets chacun et initialise tous les octets à zéro. Si `nmemb` ou 
 * `size` est 0, elle alloue 1 octet. Si la taille totale demandée dépasse la 
 * capacité maximale d'un entier signé, elle retourne NULL.
 *
 * @param nmemb Le nombre d'éléments à allouer.
 * @param size La taille de chaque élément.
 * @return Un pointeur vers la mémoire allouée ou NULL en cas d'erreur.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pts;

	if (nmemb == 0 || size == 0)
	{
		pts = malloc(1);
		return (pts);
	}
	if ((nmemb * size) > 2147483647 || nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	else
	{
		pts = (char *)malloc((nmemb * size) * sizeof(*pts));
		if (!pts)
			return (NULL);
		ft_bzero(pts, (nmemb * size));
		return (pts);
	}
}
