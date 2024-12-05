/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd_ptf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:20:22 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/31 01:52:50 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Écrit un pointeur dans un descripteur de fichier.
 *
 * Cette fonction prend un pointeur et écrit son adresse mémoire en format 
 * hexadécimal précédée de "0x" dans le descripteur de fichier donné. 
 * Si le pointeur est NULL, elle écrit "(nil)" à la place. 
 * Elle retourne la longueur totale des caractères écrits.
 *
 * @param ptr Le pointeur dont l'adresse doit être écrite.
 * @param fd Le descripteur de fichier où écrire.
 * @param len La longueur actuelle des caractères écrits.
 * @return La longueur totale des caractères écrits.
 */
int	ft_putptr_fd_ptf(void *ptr, int fd, int len)
{
	if (ptr)
	{
		len += ft_putstr_fd_ptf("0x", fd, len);
		len = ft_puthexaptr_fd_ptf((unsigned long) ptr, fd, len);
	}
	else
		len += ft_putstr_fd_ptf("(nil)", fd, len);
	return (len);
}
