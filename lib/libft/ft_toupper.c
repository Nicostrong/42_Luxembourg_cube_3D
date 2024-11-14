/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:58:24 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:30:35 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convertit un caractère en majuscule s'il est alphabétique et en 
 * minuscule.
 *
 * Cette fonction convertit le caractère `c` en majuscule s'il est alphabétique 
 * et en minuscule.
 *
 * @param c Le caractère à convertir.
 * @return Le caractère converti en majuscule s'il est alphabétique, sinon le 
 * même caractère.
 */
int	ft_toupper(int c)
{
	if (ft_isalpha(c))
	{
		if ((c >= 97) && (c <= 122))
			c = c - 32;
	}
	return (c);
}
