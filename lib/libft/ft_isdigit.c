/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:17:22 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:44:46 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est un chiffre.
 *
 * Cette fonction vérifie si le caractère passé en argument est un chiffre
 * (compris entre '0' et '9').
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est un chiffre, 0 sinon.
 */
int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}
