/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:44 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:49:39 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Supprime et libère la mémoire d'un élément d'une liste.
 *
 * Cette fonction supprime et libère la mémoire de l'élément `lst` de la liste
 * chaînée en appliquant la fonction `del` à son contenu. Ensuite, elle libère
 * la mémoire de la structure elle-même.
 *
 * @param lst Un pointeur vers la structure à supprimer.
 * @param del Le pointeur vers la fonction utilisée pour supprimer le contenu 
 * de l'élément.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || (*f) == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
