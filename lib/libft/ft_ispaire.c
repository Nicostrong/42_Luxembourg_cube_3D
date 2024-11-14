/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:27:50 by phkevin           #+#    #+#             */
/*   Updated: 2024/08/22 11:36:49 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Vérifie si un nombre est pair.
 *
 * Cette fonction prend un entier en argument et détermine s'il est pair.
 *
 * @param i L'entier à vérifier.
 * @return int Retourne 1 si l'entier est pair, 0 sinon.
 */
int	ft_ispaire(int i)
{
	if (i % 2 == 0)
		return (1);
	return (0);
}
