/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:33:53 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/02 18:42:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 * 	void	ft_free(void *ptr)
 * <\summary>
 * 
 * <description>
 * 	ft_free set all bit to zero, free the ptr and set to null.
 * </description>
 *
 * <param type="void *" name="ptr">pointer to free</param>
 *
 * <return>
 * 	void
 * </return>
 *
 */

void	ft_free(void *ptr)
{
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, ft_strlen(ptr));
		free(ptr);
		ptr = NULL;
	}
}
