/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:09:45 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:19:06 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applique une fonction à chaque caractère d'une chaîne avec son indice.
 *
 * Cette fonction applique la fonction `f` à chaque caractère de la chaîne de 
 * caractères `s`, en lui passant l'indice de chaque caractère en premier 
 * argument.
 *
 * @param s La chaîne de caractères à parcourir.
 * @param f La fonction à appliquer à chaque caractère.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
		f(i++, s++);
}
