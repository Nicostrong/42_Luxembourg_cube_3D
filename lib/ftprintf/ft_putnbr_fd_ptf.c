/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ptf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:46:23 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/31 01:32:39 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Écrit un entier dans un descripteur de fichier.
 *
 * Cette fonction prend un entier et écrit sa représentation décimale
 * dans le descripteur de fichier donné. Si l'entier est la plus petite
 * valeur possible (-2147483648), elle écrit cette valeur littéralement
 * car elle ne peut pas être convertie en positif. Sinon, elle écrit un
 * signe '-' avant de traiter la valeur absolue du nombre. Elle utilise
 * la récursion pour traiter chaque chiffre du nombre et retourne la
 * longueur totale des caractères écrits.
 *
 * @param n L'entier à écrire.
 * @param fd Le descripteur de fichier où écrire.
 * @param len La longueur actuelle des caractères écrits.
 * @return La longueur totale des caractères écrits.
 */
int	ft_putnbr_fd_ptf(int n, int fd, int len)
{
	if (n == -2147483648)
		len += ft_putstr_fd_ptf("-2147483648", fd, len);
	else
	{
		if (n < 0)
		{
			len += ft_putchar_fd_ptf('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			len = ft_putnbr_fd_ptf((n / 10), fd, len);
		}
		len += ft_putchar_fd_ptf((n % 10 + '0'), fd);
	}
	return (len);
}
