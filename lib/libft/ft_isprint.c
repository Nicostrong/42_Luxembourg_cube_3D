/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:28:04 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:45:09 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est imprimable.
 *
 * Cette fonction vérifie si le caractère passé en argument est un caractère
 * imprimable, y compris l'espace (valeurs comprises entre 32 et 126).
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est imprimable, 0 sinon.
 */
int	ft_isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}
