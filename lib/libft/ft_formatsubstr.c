/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatsubstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:55:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:14:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_create_string(size_t len, char c)
 * </summary>
 *
 * <description>
 *	ft_create_string create a new string of size len and fill it with the char 
 *	c.
 * </description>
 *
 * <param type="size_t" name="len">len of new string</param>
 * <param type="char" name="c">char of fill</param>
 *
 * <return>
 *	a pointer to the new string or NULL if allocation faill.
 * </return>
 *
 */
static char	*ft_create_string(size_t len, char c)
{
	char	*new;
	size_t	i;

	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
		new[i++] = c;
	return (new);
}

/*
 * <cat>str</cat>
 *
 * <summary>
 *	static char	*ft_get_substring(char const *s, int start, size_t len)
 * </summary>
 *
 * <description>
 *	ft_get_substring create a new string from the string s at the index start if
 *	start is positive or at the index start + len if start is negative. The new
 *	string is of size len.
 * </description>
 *
 * <param type="char const *" name="s">string to substring</param>
 * <param type="int" name="start">start index of new string</param>
 * <param type="size_t" name="len">len of new string</param>
 *
 * <return>
 *	a pointer to the new string or NULL if allocation faill.
 * </return>
 *
 */
static char	*ft_get_substring(char const *s, int start, size_t len)
{
	if (start < 0)
		return (ft_substr(s, 0, (size_t)(len + start)));
	return (ft_substr(s, start, len));
}

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_copy_str(char *sub, char c, size_t len, size_t prefix_len)
 * </summary>
 *
 * <description>
 *	ft_copy_str create a new string from the string sub. The new string is of
 *	size len and is filled with the char c. The new string is filled with the
 *	char c at the bigining or at the end of the string.
 * </description>
 *
 * <param type="char *" name="sub">substring to copy</param>
 * <param type="char" name="c">char of fill</param>
 * <param type="size_t" name="len">len of new string</param>
 * <param type="size_t" name="prefix_len">len of prefix char</param>
 *
 * <return>
 *	a pointer to the new string or NULL if allocation faill.
 * </return>
 *
 */
static char	*ft_copy_str(char *sub, char c, size_t len, size_t prefix_len)
{
	char	*new;
	size_t	i;
	size_t	index;

	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	index = 0;
	while (index < prefix_len)
		new[index++] = c;
	i = 0;
	while (i < ft_strlen(sub) && sub[i])
		new[index++] = sub[i++];
	while (index < len)
		new[index++] = c;
	return (new);
}

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
char	*ft_formatsubstr(char const *s, int start, size_t len, char c)
{
	char	*new;
	char	*sub;
	size_t	prefix_len;

	if (!s)
		return (ft_create_string(len, c));
	if (len == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	prefix_len = 0;
	if (start < 0)
		prefix_len = (size_t)(-start);
	sub = ft_get_substring(s, start, len);
	if (ft_strlen(sub) == len)
		return (sub);
	new = ft_copy_str(sub, c, len, prefix_len);
	ft_free((void **)&sub);
	return (new);
}
