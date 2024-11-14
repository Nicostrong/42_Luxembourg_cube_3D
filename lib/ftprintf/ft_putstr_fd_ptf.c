/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_ptf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:34:20 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/10 17:29:33 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Écrit une chaîne de caractères dans un descripteur de fichier.
 *
 * Cette fonction prend une chaîne de caractères et l'écrit dans le descripteur
 * de fichier donné. Si la chaîne est NULL, elle écrit "(null)" à la place.
 * Elle retourne la longueur totale des caractères écrits.
 *
 * @param s La chaîne de caractères à écrire.
 * @param fd Le descripteur de fichier où écrire.
 * @param len La longueur actuelle des caractères écrits.
 * @return La longueur totale des caractères écrits.
 */
int	ft_putstr_fd_ptf(char *s, int fd, int len)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		len += ft_putchar_fd_ptf(*s++, fd);
	return (len);
}
