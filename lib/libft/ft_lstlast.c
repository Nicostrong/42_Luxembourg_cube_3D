/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:13:26 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:50:04 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Renvoie le dernier élément d'une liste.
 *
 * Cette fonction renvoie un pointeur vers le dernier élément de la liste 
 * chaînée `lst`.
 * Si `lst` est NULL, la fonction retourne NULL.
 *
 * @param lst Un pointeur vers la première structure de la liste.
 * @return Un pointeur vers le dernier élément de la liste, ou NULL si la 
 * liste est vide.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
