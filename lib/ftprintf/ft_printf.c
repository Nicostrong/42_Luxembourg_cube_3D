/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:03:36 by phkevin           #+#    #+#             */
/*   Updated: 2024/05/31 01:52:14 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * @brief Formate et écrit des arguments variadiques dans un descripteur.
 *
 * Cette fonction formate et écrit différents types d'arguments variadiques 
 * dans le descripteur de fichier donné, en fonction du caractère spécifié. 
 * Elle retourne la longueur totale des caractères écrits.
 *
 * @param args La liste des arguments variadiques.
 * @param c Le caractère spécifiant le type d'argument.
 * @param fd Le descripteur de fichier où écrire.
 * @return La longueur totale des caractères écrits.
 * 
 *  * Les caractères de format supportés sont :
 * - 'd' ou 'i' : entier signé
 * - 'c' : caractère
 * - 's' : chaîne de caractères
 * - 'p' : pointeur
 * - 'x' ou 'X' : entier non signé en hexadécimal (minuscule ou majuscule)
 * - 'u' : entier non signé
 * - '%' : caractère '%' littéral
 */
static int	ft_format_ptf(va_list args, const char c, int fd)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len = ft_putnbr_fd_ptf(va_arg(args, int), fd, len);
	else if (c == 'c')
		len = ft_putchar_fd_ptf(va_arg(args, int), fd);
	else if (c == 's')
		len = ft_putstr_fd_ptf(va_arg(args, char *), fd, len);
	else if (c == 'p')
		len = ft_putptr_fd_ptf(va_arg(args, void *), fd, len);
	else if (c == 'x' || c == 'X')
		len = ft_puthexa_fd_ptf(va_arg(args, long), c, fd, len);
	else if (c == 'u')
		len = ft_putunsnbr_fd_ptf(va_arg(args, unsigned int), fd, len);
	else if (c == '%')
		len = ft_putchar_fd_ptf('%', fd);
	return (len);
}

/**
 * @brief Écrit une chaîne de caractères sur le descripteur d'erreur standard.
 *
 * Cette fonction prend une chaîne de caractères et l'écrit sur le descripteur
 * d'erreur standard (stderr). Elle retourne la longueur totale des caractères 
 * écrits.
 *
 * @param str La chaîne de caractères à écrire.
 * @return La longueur totale des caractères écrits.
 */
int	ft_printf_error(char *str)
{
	int	len;

	len = 0;
	len += ft_putstr_fd_ptf(str, 2, 0);
	return (len);
}

/**
 * @brief Formate et écrit une chaîne de caractères sur le descripteur standard.
 *
 * Cette fonction formate et écrit une chaîne de caractères sur le descripteur
 * standard (stdout). Elle gère les caractères de format spécifiés par des 
 * arguments variadiques. Elle retourne la longueur totale des caractères 
 * écrits.
 *
 * @param str La chaîne de caractères de format.
 * @param ... Les arguments variadiques correspondant aux formats spécifiés.
 * @return La longueur totale des caractères écrits.
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_format_ptf(args, *(str + 1), 1);
			str++;
		}
		else
			len += ft_putchar_fd_ptf(*str, 1);
		str++;
	}
	va_end(args);
	return (len);
}
