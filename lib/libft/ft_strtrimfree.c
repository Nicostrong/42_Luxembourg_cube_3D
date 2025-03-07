/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:39:32 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/19 07:49:15 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	*ft_strtrimfree(char *s1, char const *set)
 * </summary>
 *
 * <description>
 * 	ft_strtrimfree creat a new malloc string and remove all char in set at the 
 *  start and at the end of the original string and free the original string.
 * </description>
 *
 * <param type="char *" name="s1">string to trim</param>
 * <param type="char const *" name="set">set of char to remove</param>
 *
 * <return>
 * 	a pointer allocated with the new string without the set char.
 * </return>
 *
 */
char	*ft_strtrimfree(char *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	if (!s1 || ft_strlen(s1) == 0)
		return (free(s1), NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	new = ft_substr(s1, start, (end - start));
    free(s1);
	return (new);
}
