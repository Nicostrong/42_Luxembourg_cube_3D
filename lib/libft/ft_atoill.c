/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:08:01 by phkevin           #+#    #+#             */
/*   Updated: 2024/04/17 10:09:28 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convertit une chaîne de caractères en entier long long.
 *
 * Cette fonction convertit une chaîne de caractères représentant un nombre
 * en un entier long long (long long). Elle gère les espaces initiaux, les
 * signes '+' et '-', et retourne le résultat en conséquence.
 *
 * @param str La chaîne de caractères à convertir.
 * @return L'entier long long converti de la chaîne de caractères.
 */
long long	ft_atoill(const char *str)
{
	long long	result;
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
	return (result);
}
