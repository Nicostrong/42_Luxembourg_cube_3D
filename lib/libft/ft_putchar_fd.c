/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:32:52 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:10:55 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Écrit un caractère dans un descripteur de fichier.
 *
 * Cette fonction écrit le caractère `c` dans le descripteur de fichier spécifié
 * par `fd`.
 *
 * @param c Le caractère à écrire.
 * @param fd Le descripteur de fichier dans lequel écrire.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
