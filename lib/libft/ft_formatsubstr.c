/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatsubstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:55:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/18 13:51:20 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_formatsubstr(char const *s,int start, size_t len, char c)
 * </summary>
 *
 * <description>
 *	ft_formatsubstr creat a new string from the string s at the index start for 
 *	len char. Like a substring but in case of substring not equal to len, the
 *	new string is filled with the char c at the bigining or at the end of the 
 *	string. The string return is of size len.
 * </description>
 *
 * <param type="char const *" name="s">string to substring</param>
 * <param type="int" name="start">start index of new string</param>
 * <param type="size_t" name="len">len of new string</param>
 * <param type="char" name="c">char of fill</param>
 *
 * <return>
 *	a pointer to the new string or NULL if allocation faill.
 * </return>
 *
 */
char		*ft_formatsubstr(char const *s, int start, size_t len, char c)
{
	char	*new;
	char	*sub;
	size_t	i;
	size_t	index;
	size_t	len_sub;
	size_t	prefix_len;

	if (len == 0)
		return (ft_calloc(1, sizeof(char)));
	prefix_len = 0;
	if (start < 0)
	{
		prefix_len = (size_t)(-start);
		sub = ft_substr(s, 0, len + start);
	}
	else
		sub = ft_substr(s, start, len);
	len_sub = ft_strlen(sub);
	if (len_sub == len)
		return (sub);
	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (ft_free(sub), NULL);
	index = -1;
	while (++index < prefix_len)
		new[index] = c;
	i = -1;
	while (++i < len_sub)
		new[++index] = sub[i];
	while (++index < len)
		new[index] = c;
	ft_free(sub);
	return (new);
}
