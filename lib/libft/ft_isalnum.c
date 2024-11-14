/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:42:48 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:43:41 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Vérifie si un caractère est alphanumérique.
 *
 * Cette fonction vérifie si le caractère passé en argument est une lettre 
 * (majuscule ou minuscule) ou un chiffre.
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est alphanumérique, 0 sinon.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
