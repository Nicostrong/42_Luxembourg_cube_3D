/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:43:32 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:09:03 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copie une zone mémoire vers une autre, même en cas de chevauchement.
 *
 * Cette fonction copie les `n` premiers octets de la zone mémoire pointée par 
 * `src` vers la zone mémoire pointée par `dest`. La copie est effectuée de
 * manière sûre, même si les deux zones mémoire se chevauchent partiellement 
 * ou totalement.
 *
 * @param dest Un pointeur vers la destination de la copie.
 * @param src Un pointeur vers la source de la copie.
 * @param n Le nombre d'octets à copier.
 * @return Un pointeur vers la destination de la copie.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dstr;
	const char	*sstr;
	size_t		i;

	dstr = (char *)dest;
	sstr = (const char *)src;
	if (dstr < sstr)
	{
		i = 0;
		while (i < n)
		{
			dstr[i] = sstr[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dstr[n] = sstr[n];
	}
	return (dest);
}
