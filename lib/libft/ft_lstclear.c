/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:09:06 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:48:05 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Supprime et libère la mémoire de tous les éléments d'une liste.
 *
 * Cette fonction supprime et libère la mémoire de tous les éléments de la
 * liste chaînée `lst`, en appliquant la fonction `del` à chaque élément.
 * Ensuite, elle met à NULL le pointeur de tête de liste `lst`.
 *
 * @param lst Un pointeur vers un pointeur vers la première structure de la 
 * liste.
 * @param del Le pointeur vers la fonction utilisée pour supprimer le contenu 
 * d'un élément.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lsttmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		lsttmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = lsttmp;
	}
}
