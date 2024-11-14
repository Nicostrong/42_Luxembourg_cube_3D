/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_ptf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:32:52 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/31 01:48:10 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Écrit un caractère dans un descripteur de fichier.
 *
 * Cette fonction prend un caractère et l'écrit dans le descripteur de fichier
 * donné. Elle retourne le nombre de caractères écrits, généralement 1.
 *
 * @param c Le caractère à écrire.
 * @param fd Le descripteur de fichier où écrire.
 * @return Le nombre de caractères écrits, généralement 1.
 */
int	ft_putchar_fd_ptf(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
