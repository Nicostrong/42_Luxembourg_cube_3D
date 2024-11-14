/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:11 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/18 12:50:37 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 *
 * Cette fonction calcule la longueur de la chaîne de caractères `str`, 
 * c'est-à-dire le nombre de caractères avant le caractère nul de fin de chaîne.
 *
 * @param str La chaîne de caractères dont calculer la longueur.
 * @return Le nombre de caractères dans la chaîne de caractères, excluant le 
 * caractère nul de fin de chaîne.
 */
size_t	ft_strlen(const char *str)
{
	size_t	nb;

	nb = 0;
	while (*str != '\0')
	{
		str++;
		nb++;
	}
	return (nb);
}
