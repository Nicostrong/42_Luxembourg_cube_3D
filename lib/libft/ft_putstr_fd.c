/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:34:20 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:13:19 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Écrit une chaîne de caractères dans un descripteur de fichier.
 *
 * Cette fonction écrit la chaîne de caractères `s` dans le descripteur de 
 * fichier spécifié par `fd`.
 *
 * @param s La chaîne de caractères à écrire.
 * @param fd Le descripteur de fichier dans lequel écrire.
 */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s++, 1);
	}
}
