/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:13:33 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:51:28 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	gnl_strchr chearch the first occurence of the char c.
 */

char	*gnl_strchr(char const *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

/*
 *	gnl_strlen calculate the lenght of the string
 */

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (*str++)
		len++;
	return (len);
}

/*
 *	gnl_strjoin two string in one
 */

char	*gnl_strjoin(char *buff, char *lu)
{
	size_t	len_buff;
	size_t	len_lu;
	size_t	index;
	char	*joinstr;
	char	*src;

	if (!buff && !lu)
		return (free(buff), NULL);
	len_buff = gnl_strlen(buff);
	len_lu = gnl_strlen(lu);
	joinstr = (char *)malloc((len_buff + len_lu + 1) * sizeof(char));
	if (!joinstr)
		return (free(buff), NULL);
	src = buff;
	index = 0;
	while (src && *src)
		joinstr[index++] = *src++;
	src = lu;
	while (src && *src)
		joinstr[index++] = *src++;
	joinstr[index] = 0;
	free(buff);
	buff = NULL;
	return (joinstr);
}
