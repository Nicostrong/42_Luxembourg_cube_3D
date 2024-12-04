/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:51:07 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/04 13:42:18 by phkevin          ###   Luxembourg.lu     */
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
	size_t	size_total;
	void	*ptr;

	size_total = nmemb * size;
	if (size_total / nmemb != size)
		return (NULL);
	ptr = malloc(size_total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size_total);
	return (ptr);
}
