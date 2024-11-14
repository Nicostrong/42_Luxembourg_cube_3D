/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:42:14 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:11:28 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Écrit une chaîne de caractères suivie d'un saut de ligne dans un 
 * descripteur de fichier.
 *
 * Cette fonction écrit la chaîne de caractères `s` dans le descripteur de 
 * fichier spécifié par `fd`, suivie d'un saut de ligne.
 *
 * @param s La chaîne de caractères à écrire.
 * @param fd Le descripteur de fichier dans lequel écrire.
 */
void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s++, 1);
	}
	write(fd, "\n", 1);
}
