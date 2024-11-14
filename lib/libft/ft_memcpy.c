/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:36:41 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:08:24 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copie une zone mémoire vers une autre.
 *
 * Cette fonction copie les `n` premiers octets de la zone mémoire pointée par 
 * `src` vers la zone mémoire pointée par `dest`. Les deux zones mémoire ne 
 * doivent pas se chevaucher.
 *
 * @param dest Un pointeur vers la destination de la copie.
 * @param src Un pointeur vers la source de la copie.
 * @param n Le nombre d'octets à copier.
 * @return Un pointeur vers la destination de la copie.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dstr;
	const char	*sstr;

	sstr = (char *) src;
	dstr = (char *) dest;
	if (!dest && !src)
		return (0);
	while (n--)
		dstr[n] = sstr[n];
	return (dest);
}
