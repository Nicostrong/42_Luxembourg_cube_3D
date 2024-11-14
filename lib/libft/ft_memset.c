/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:13:04 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:09:46 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Remplit une zone mémoire avec une valeur spécifique.
 *
 * Cette fonction remplit les `n` premiers octets de la zone mémoire pointée 
 * par `s` avec la valeur `c`.
 *
 * @param s Un pointeur vers la zone mémoire à remplir.
 * @param c La valeur à utiliser pour remplir la zone mémoire.
 * @param n Le nombre d'octets à remplir.
 * @return Un pointeur vers la zone mémoire remplie.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
