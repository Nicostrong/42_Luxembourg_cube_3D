/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd_ptf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:28:15 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/31 01:48:11 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Écrit une adresse mémoire en hexadécimal dans un descripteur de 
 * fichier.
 *
 * Cette fonction prend une adresse mémoire et écrit sa représentation
 * hexadécimale en minuscules dans le descripteur de fichier donné.
 * Elle utilise la récursion pour traiter chaque chiffre hexadécimal
 * et retourne la longueur totale des caractères écrits.
 *
 * @param hex L'adresse mémoire à écrire.
 * @param fd Le descripteur de fichier où écrire.
 * @param len La longueur actuelle des caractères écrits.
 * @return La longueur totale des caractères écrits.
 */
int	ft_puthexaptr_fd_ptf(unsigned long hex, int fd, int len)
{
	char	*basehex;

	basehex = "0123456789abcdef";
	if (hex >= 16)
		len = ft_puthexaptr_fd_ptf(hex / 16, fd, len);
	len += ft_putchar_fd_ptf(basehex[hex % 16], fd);
	return (len);
}

/**
 * @brief Écrit un entier non signé en hexadécimal dans un descripteur de 
 * fichier.
 *
 * Cette fonction prend un entier non signé et écrit sa représentation 
 * hexadécimale (en minuscules ou majuscules) dans le descripteur de fichier 
 * donné. Elle utilise la récursion pour traiter chaque chiffre hexadécimal et 
 * retourne la longueur totale des caractères écrits.
 *
 * @param hex L'entier non signé à écrire en hexadécimal.
 * @param x Spécifie si la représentation hexadécimale doit être en majuscules 
 * ('X') ou minuscules ('x').
 * @param fd Le descripteur de fichier où écrire.
 * @param len La longueur actuelle des caractères écrits.
 * @return La longueur totale des caractères écrits.
 */
int	ft_puthexa_fd_ptf(unsigned int hex, char x, int fd, int len)
{
	char	*basehex;

	if (hex == 0)
		len += ft_putchar_fd_ptf('0', fd);
	else
	{
		if (x == 'X')
			basehex = "0123456789ABCDEF";
		else
			basehex = "0123456789abcdef";
		if ((unsigned int)hex >= 16)
			len = ft_puthexa_fd_ptf(hex / 16, x, 1, len);
		len += ft_putchar_fd_ptf(*(basehex + ((unsigned int)hex % 16)), 1);
	}
	return (len);
}
