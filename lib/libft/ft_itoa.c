/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:23:08 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:46:30 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compte le nombre de chiffres d'un entier.
 *
 * Cette fonction compte le nombre de chiffres présents dans un entier, y 
 * compris le signe s'il est négatif.
 *
 * @param n L'entier dont on veut compter le nombre de chiffres.
 * @return Le nombre de chiffres dans l'entier.
 */
static int	ft_count_char(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/**
 * @brief Convertit un entier en une chaîne de caractères.
 *
 * Cette fonction convertit un entier en une chaîne de caractères. Elle alloue
 * dynamiquement la mémoire nécessaire pour la chaîne résultante et la retourne.
 * Si l'allocation de mémoire échoue, elle retourne NULL.
 *
 * @param n L'entier à convertir en chaîne de caractères.
 * @return Un pointeur vers la chaîne de caractères résultante, ou NULL en cas 
 * d'erreur.
 */
char	*ft_itoa(int n)
{
	char		*str;
	long long	nbr;
	int			nb_len;

	nbr = (long long)n;
	nb_len = ft_count_char(nbr);
	str = (char *)malloc((nb_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	str[nb_len--] = '\0';
	while (nb_len >= 0)
	{
		str[nb_len] = nbr % 10 + '0';
		nbr = nbr / 10;
		nb_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
