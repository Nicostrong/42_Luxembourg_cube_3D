/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:01:52 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:06:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_lstdelone(t_list *lst, void (*del)(void *))
 * </summary>
 *
 * <description>
 * 	ft_lstdelone remove of the linked list the element lst in calling the
 * 	function del. this function free corectely the list.
 * </description>
 *
 * <param type="t_list *" name="lst">list of linked list to del</param>
 * <param type="void *" name="del">dellist function with param (void *)</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	ft_free((void **)&lst);
}
