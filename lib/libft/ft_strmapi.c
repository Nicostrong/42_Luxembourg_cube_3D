/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:05:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:11:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>convert</cat>
 *
 * <summary>
 *	char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
 * </summary>
 *
 * <description>
 *	ft_strmapi call for eatch char of the string s a function who make some
 *	modification a the char. it creat a new string and allocate memory for this
 *	string.
 * </description>
 *
 * <param type="char const *" name="s">string to evaluate</param>
 * <param type="char *" name="f">function with param type (u_int, char)</param>
 *
 * <return>
 *	a pointer allocated with the new string.
 * </return>
 *
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;

	index = 0;
	ret = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!ret)
		return (NULL);
	while (s[index])
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	ret[index] = 0;
	return (ret);
}
