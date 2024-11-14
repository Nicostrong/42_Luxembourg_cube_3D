/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:02:22 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:20:43 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatène deux chaînes de caractères.
 *
 * Cette fonction concatène les chaînes de caractères `s1` et `s2` pour former 
 * une nouvelle chaîne.
 * La nouvelle chaîne est allouée dynamiquement et terminée par un caractère 
 * nul.
 *
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne de caractères concaténée, ou 
 * NULL en cas d'erreur d'allocation.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
