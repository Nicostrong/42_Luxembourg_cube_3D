/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraycpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:30:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:08:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	**ft_strarraycpy(char **array)
 * </summary>
 *
 * <description>
 *	ft_strarraycpy copy an array of str.
 * </description>
 *
 * <param type="char **" name="array">array to copy</param>
 *
 * <return>
 *	a pointer to new array str.
 * </return>
 *
 */
char	**ft_strarraycpy(char **array)
{
	char	**cpy;
	int		nb_row;
	int		index;

	if (!array)
		return (NULL);
	nb_row = 0;
	while (array[nb_row++])
		;
	cpy = (char **)ft_calloc(nb_row, sizeof(char *));
	if (!cpy)
		return (NULL);
	index = -1;
	while (array[++index])
	{
		cpy[index] = ft_strdup(array[index]);
		if (!cpy[index])
			return (ft_free_array(cpy));
	}
	cpy[index] = NULL;
	return (cpy);
}
