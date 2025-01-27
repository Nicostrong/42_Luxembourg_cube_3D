/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:53:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 09:59:45 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	char **ft_free_array(char **array)
 * </summary>
 *
 * <description>
 *	ft_free_array free all element of the array and the array.
 * </description>
 *
 * <param type="char **" name="array">array of char* to free</param>
 *
 * <return>
 *	NULL.
 * </return>
 *
 */
char	**ft_free_array(char **array)
{
	int	index;

	if (!array)
		return (NULL);
	index = -1;
	while (array[++index])
		ft_free((void **)&array[index]);
	ft_free((void **)&array);
	return (NULL);
}
