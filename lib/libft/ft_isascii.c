/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:04:55 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:44:25 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est un caractère ASCII.
 *
 * Cette fonction vérifie si le caractère passé en argument appartient
 * à l'ensemble des caractères ASCII (valeurs entre 0 et 127).
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est un caractère ASCII, 0 sinon.
 */
int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}
