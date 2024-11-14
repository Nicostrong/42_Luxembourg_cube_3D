/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:56 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:44:00 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Vérifie si un caractère est une lettre.
 *
 * Cette fonction vérifie si le caractère passé en argument est une lettre
 * majuscule ou minuscule.
 *
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est une lettre, 0 sinon.
 */
int	ft_isalpha(int c)
{
	return (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')));
}
