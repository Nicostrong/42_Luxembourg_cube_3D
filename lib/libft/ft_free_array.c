/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:43:19 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/16 10:44:19 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Libère un tableau de chaînes de caractères.
 *
 * Cette fonction libère chaque chaîne de caractères dans le tableau `array`,
 * puis libère le tableau lui-même. Elle renvoie toujours `NULL`.
 *
 * @param array Le tableau de chaînes de caractères à libérer.
 * @return Toujours `NULL`.
 */
char	**ft_free_array(char **array)
{
	int	index;

	if (!array)
		return (NULL);
	index = -1;
	while (array[++index])
		free(array[index]);
	free(array);
	return (NULL);
}