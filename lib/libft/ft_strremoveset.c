/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremoveset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:53:12 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/13 11:56:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	char	*ft_strremoveset(char const *s1, char *charset)
 * </summary>
 *
 * <description>
 * 	ft_strremoveset remove all char in the set from the string.
 * </description>
 *
 * <param type="char const *" name="s1">string to trim</param>
 * <param type="char const *" name="set">set of char to remove</param>
 *
 * <return>
 * 	a pointer allocated with the new string without the set char.
 * </return>
 *
 */

char	*ft_strremoveset(char const *s1, char *charset)
{
	int		i;
	int		j;
	char	*tmp;
	char	*new;

	if (!s1)
		return (NULL);
	if (!charset)
		return (ft_strdup(s1));
	tmp = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	i = -1;
	j = 0;
	while (s1[++i])
		if (!ft_strchr(charset, s1[i]))
			tmp[j++] = s1[i];
	tmp[j] = '\0';
	new = ft_strdup(tmp);
	ft_free(tmp);
	return (new);
}
