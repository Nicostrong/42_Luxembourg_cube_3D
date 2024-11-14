/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:23:59 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:48:49 by phkevin          ###   ########.fr       */
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
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
