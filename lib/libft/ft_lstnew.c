/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:21:02 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:15:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 *	t_list	*ft_lstnew(void *content)
 * </summary>
 *
 * <description>
 * 	ft_lstnew creat and allocate memory for a new list and set the variable
 * 	content with the value of content and the variable next at NULL.
 * </description>
 *
 * <param type="void *" name="content">value to save in content</param>
 *
 * <return>
 *	a pointer to a new list.
 * </return>
 *
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
