/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_strarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:35:45 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/18 14:04:26 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copie un tableau de chaînes de caractères.
 *
 * Cette fonction alloue un nouvel espace mémoire et copie chaque chaîne de
 * caractères du tableau `array` dans un nouveau tableau. Si une erreur
 * survient lors de la duplication, toute la mémoire allouée est libérée et
 * la fonction renvoie `NULL`.
 * 
 * @param array Le tableau de chaînes de caractères à copier.
 * @return Un nouveau tableau de chaînes de caractères copié, ou `NULL` en cas
 * d'échec.
 */
char	**ft_copy_strarray(char **str)
{
	char	**cpy;
	int		nb_row;
	int		index;

	nb_row = 0;
	while (str[nb_row] != NULL)
		nb_row++;
	cpy = (char **)ft_calloc(nb_row + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	index = 0;
	while (str[index])
	{
		cpy[index] = ft_strdup(str[index]);
		if (!cpy[index])
		{
			ft_free_array(cpy);
			return (NULL);
		}
		index++;
	}
	cpy[index] = NULL;
	return (cpy);
}