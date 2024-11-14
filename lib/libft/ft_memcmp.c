/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:24:39 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:07:31 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare deux zones mémoire.
 *
 * Cette fonction compare les `n` premiers octets des zones mémoire `s1` et 
 * `s2`.
 * Elle retourne un entier inférieur, égal ou supérieur à zéro si les `n` 
 * premiers octets de `s1` sont respectivement inférieurs, égaux ou supérieurs
 * aux `n` premiers octets de `s2`.
 *
 * @param s1 Un pointeur vers la première zone mémoire à comparer.
 * @param s2 Un pointeur vers la deuxième zone mémoire à comparer.
 * @param n Le nombre d'octets à comparer.
 * @return Un entier inférieur, égal ou supérieur à zéro selon que les `n` 
 * premiers octets de `s1` sont respectivement inférieurs, égaux ou supérieurs 
 * aux `n` premiers octets de `s2`.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;

	sa = s1;
	sb = s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*sa != *sb)
			return (*sa - *sb);
		sa++;
		sb++;
	}
	return (0);
}
