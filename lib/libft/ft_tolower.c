/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:08:01 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:30:11 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convertit un caractère en minuscule s'il est alphabétique et en 
 * majuscule.
 *
 * Cette fonction convertit le caractère `c` en minuscule s'il est alphabétique 
 * et en majuscule.
 *
 * @param c Le caractère à convertir.
 * @return Le caractère converti en minuscule s'il est alphabétique, sinon le 
 * même caractère.
 */
int	ft_tolower(int c)
{
	if (ft_isalpha(c))
	{
		if ((c >= 65) && (c <= 90))
			c = c + 32;
	}
	return (c);
}
