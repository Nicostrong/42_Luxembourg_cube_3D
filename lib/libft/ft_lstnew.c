/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:38:21 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 16:51:44 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Crée un nouvel élément de liste avec le contenu spécifié.
 *
 * Cette fonction crée un nouvel élément de liste avec le contenu spécifié et le
 * retourne. Si l'allocation de mémoire échoue, la fonction retourne NULL.
 *
 * @param content Le contenu à placer dans le nouvel élément de liste.
 * @return Un pointeur vers le nouvel élément de liste créé, ou NULL en cas 
 * d'erreur d'allocation.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc (sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
