/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_fd_ptf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:46:36 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/31 01:50:09 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Écrit un entier non signé dans un descripteur de fichier.
 *
 * Cette fonction prend un entier non signé et écrit sa représentation
 * décimale dans le descripteur de fichier donné. Elle retourne la longueur
 * totale des caractères écrits.
 *
 * @param n L'entier non signé à écrire.
 * @param fd Le descripteur de fichier où écrire.
 * @param len La longueur actuelle des caractères écrits.
 * @return La longueur totale des caractères écrits.
 */
int	ft_putunsnbr_fd_ptf(unsigned int n, int fd, int len)
{
	if (n >= 10)
		len = ft_putunsnbr_fd_ptf(n / 10, fd, len);
	len += ft_putchar_fd_ptf(n % 10 + '0', fd);
	return (len);
}
