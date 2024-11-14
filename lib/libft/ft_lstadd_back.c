/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:19:00 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:47:06 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Ajoute un élément à la fin d'une liste chaînée.
 *
 * Cette fonction ajoute un élément `new` à la fin de la liste chaînée `lst`.
 * Si `lst` est NULL, `lst` pointera vers `new` après l'ajout. Si `new` est 
 * NULL, la fonction ne fait rien.
 *
 * @param lst Un pointeur vers un pointeur vers la première structure de la 
 * liste.
 * @param new Un pointeur vers la structure à ajouter à la fin de la liste.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lsladd;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lsladd = *lst;
	while (lsladd->next != NULL)
		lsladd = lsladd->next;
	lsladd->next = new;
}
