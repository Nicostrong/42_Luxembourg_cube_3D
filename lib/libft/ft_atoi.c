/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:49:35 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:40:01 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convertit une chaîne de caractères en entier.
 *
 * Cette fonction convertit une chaîne de caractères représentant un nombre
 * en un entier (int). Elle gère les espaces initiaux, les signes '+' et '-',
 * et les dépassements de capacité. Si le nombre dépasse la plage des entiers
 * signés, la fonction retourne 0.
 *
 * @param str La chaîne de caractères à convertir.
 * @return L'entier converti de la chaîne de caractères.
 */
int	ft_atoi(const char *str)
{
	long int	result;
	int			op;

	op = 0;
	result = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			op++;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((op % 2) == 1)
		result *= -1;
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return ((int)result);
}
