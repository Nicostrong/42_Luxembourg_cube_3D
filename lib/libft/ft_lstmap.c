/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:07:52 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:51:20 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applique une fonction à chaque élément d'une liste et crée une 
 * nouvelle liste.
 *
 * Cette fonction applique la fonction `f` à chaque élément de la liste `lst` 
 * et crée une nouvelle liste avec les éléments modifiés. La fonction `del` est
 * utilisée pour supprimer le contenu des éléments de la nouvelle liste en cas 
 * d'erreur. Si `lst` est NULL ou si `f` ou `del` sont NULL, la fonction 
 * retourne NULL.
 *
 * @param lst Un pointeur vers le premier élément de la liste d'origine.
 * @param f Le pointeur vers la fonction à appliquer à chaque élément de la 
 * liste.
 * @param del Le pointeur vers la fonction utilisée pour supprimer le contenu 
 * des éléments de la nouvelle liste en cas d'erreur.
 * @return Un pointeur vers le premier élément de la nouvelle liste, ou NULL en
 * cas d'erreur.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lstmp = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		ft_lstadd_back(&lstmp, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	if (lstmp == NULL)
	{
		del(lstmp);
		return (NULL);
	}
	return (lstmp);
}
