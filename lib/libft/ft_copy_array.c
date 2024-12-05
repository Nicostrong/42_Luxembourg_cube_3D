/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:30:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/19 09:17:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	**ft_copy_strarray(char **array)
 * </summary>
 *
 * <description>
 *	ft_copystrarray copy an array of str.
 * </description>
 *
 * <param type="char **" name="array">array to copy</param>
 *
 * <return>
 *	a pointer to new array str.
 * </return>
 *
 */

char	**ft_copy_strarray(char **array)
{
	char	**cpy;
	int		nb_row;
	int		index;

	nb_row = 0;
	while (array[nb_row++])
		;
	nb_row++;
	cpy = (char **)ft_calloc(nb_row, sizeof(char *));
	if (!cpy)
		return (NULL);
	index = 0;
	while (array[index])
	{
		cpy[index] = ft_strdup(array[index]);
		if (!cpy[index])
		{
			ft_free_array(cpy);
			return (NULL);
		}
		index++;
	}
	cpy[index] = NULL;
	return (cpy);
}
