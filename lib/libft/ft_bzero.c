/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:59:41 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:42:25 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Remplit une zone mémoire de zéros.
 *
 * Cette fonction remplit les `n` premiers octets de la zone mémoire pointée
 * par `s` avec des zéros (valeurs nulles).
 *
 * @param s Le pointeur vers la zone mémoire à remplir.
 * @param n Le nombre d'octets à remplir avec des zéros.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
