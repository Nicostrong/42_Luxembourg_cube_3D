/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:16:33 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/03 17:04:26 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calcule la taille d'une liste chaînée.
 *
 * Cette fonction calcule le nombre d'éléments présents dans la liste chaînée 
 * `lst` et retourne ce nombre.
 *
 * @param lst Un pointeur vers le premier élément de la liste.
 * @return Le nombre d'éléments présents dans la liste.
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
