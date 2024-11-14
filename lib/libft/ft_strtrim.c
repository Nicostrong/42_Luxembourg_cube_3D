/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:39:48 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:29:06 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Supprime les caractères spécifiés en début et en fin de chaîne.
 *
 * Cette fonction crée une nouvelle chaîne en supprimant les caractères 
 * spécifiés dans `set` en début et en fin de la chaîne `s1`. La nouvelle 
 * chaîne est allouée dynamiquement.
 *
 * @param s1 La chaîne à trimmer.
 * @param set Les caractères à supprimer en début et en fin de chaîne.
 * @return Une nouvelle chaîne, résultat du trim, ou NULL en cas d'échec 
 * d'allocation mémoire.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	new = ft_substr(s1, start, (end - start));
	return (new);
}
