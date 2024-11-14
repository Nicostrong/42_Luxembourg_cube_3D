/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:46:23 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:12:13 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Écrit un entier dans un descripteur de fichier.
 *
 * Cette fonction écrit l'entier `n` dans le descripteur de fichier spécifié 
 * par `fd`.
 *
 * @param n L'entier à écrire.
 * @param fd Le descripteur de fichier dans lequel écrire.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd((n / 10), fd);
		}
		ft_putchar_fd((n % 10 + '0'), fd);
	}
}
