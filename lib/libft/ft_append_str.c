/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:51:26 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/06 12:43:55 by nfordoxc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	**ft_append_str(char **array, char *str)
 * </summary>
 *
 * <description>
 *	ft_append_str add a new field to array.
 * </description>
 *
 * <param type="char **" name="array">array where we want to extend</param>
 * <param type="char *" name="str">str we want to add</param>
 *
 * <return>
 *	a new array with the new str append.
 * </return>
 *
 */

char	**ft_append_str(char **array, char *str)
{
	char	**new_array;
	int		i;
	int		j;

	if (!str)
		return (array);
	i = 0;
	if (array)
		while (array[i])
			i++;
	new_array = (char **)ft_calloc((i + 2), sizeof(char *));
	if (!new_array)
		return (array);
	j = -1;
	while (++j < i && array[j])
		new_array[j] = ft_strdup(array[j]);
	new_array[j] = ft_strdup(str);
	if (!new_array[j])
	{
		ft_free_array(new_array);
		return (array);
	}
	new_array[++j] = NULL;
	ft_free_array(array);
	return (new_array);
}
