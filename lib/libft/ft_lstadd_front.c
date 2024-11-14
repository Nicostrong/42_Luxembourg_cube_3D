/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:09:53 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:47:33 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Ajoute un élément au début d'une liste chaînée.
 *
 * Cette fonction ajoute un élément `new` au début de la liste chaînée `lst`.
 * Si `lst` est NULL, `lst` pointera vers `new` après l'ajout. Si `new` est 
 * NULL, la fonction ne fait rien.
 *
 * @param lst Un pointeur vers un pointeur vers la première structure de la 
 * liste.
 * @param new Un pointeur vers la structure à ajouter au début de la liste.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
