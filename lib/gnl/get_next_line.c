/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:13:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/14 09:10:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	size_t	ft_find_newline(char *str)
 * </summary>
 *
 * <description>
 *	ft_find_newline shearch the first occurence of '\n' on the string str.
 * </description>
 *
 * <param type="char *" name="str">string to parse</param>
 *
 * <return>
 *	the index position more one of '\n' in str.
 *  or
 *  len of str if '\n' not in str.
 * </return>
 *
 */

static size_t	ft_find_newline(char *str)
{
	char	*ptr;
	size_t	index;

	ptr = str;
	index = 0;
	while (ptr && ptr[index] != 0 && ptr[index] != '\n')
		index++;
	if (ptr && ptr[index] == '\n')
		index++;
	return (index);
}

/*
 * gnl_substr retourne la string apres le '\n'
 */

static char	*gnl_substr(char *str)
{
	char	*substr;
	size_t	i_start;
	size_t	i_new;

	i_new = 0;
	if (str && !*str)
		return (free(str), NULL);
	i_start = ft_find_newline(str);
	substr = (char *)malloc((gnl_strlen(str) - i_start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (str && *(str + i_start))
		*(substr + i_new++) = *(str + i_start++);
	*(substr + i_new) = 0;
	if (!substr)
		return (free(substr), free(str), NULL);
	free(str);
	return (substr);
}

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	char	*ft_free_gnl(char *s1, char *s2)
 * </summary>
 *
 * <description>
 *	ft_free free the pointer s1 and s2 and return the value NULL
 * </description>
 *
 * <param type="char *" name="s1">pointer 1</param>
 * <param type="char *" name="s2">pointer 2</param>
 *
 * <return>
 *	NULL
 * </return>
 *
 */

static char	*ft_free_gnl(char *s1, char *s2)
{
	return (free(s1), free(s2), NULL);
}

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_get_line(char *str)
 * </summary>
 *
 * <description>
 *	ft_get_line create a new line from the string buff, from the start to the
 *	first '\n' char.
 * </description>
 *
 * <param type="char *" name="str">string multiline</param>
 *
 * <return>
 *	a pointer containing just the first line.
 * </return>
 *
 */

static char	*ft_get_line(char *str)
{
	size_t	index;
	char	*line;

	if (!str || *str == 0)
		return (NULL);
	index = ft_find_newline(str);
	line = (char *)malloc((index + 1) * sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (*(str + index) && *(str + index) != '\n')
	{
		*(line + index) = *(str + index);
		index++;
	}
	if (*(str + index) == '\n')
	{
		*(line + index) = '\n';
		index++;
	}
	*(line + index) = 0;
	return (line);
}

/*
 * <cat>print</cat>
 *
 * <summary>
 * 	char	*get_next_line(int fd)
 * </summary>
 *
 * <description>
 * 	get_next_line Return a pointer to a string read in a file descriptor.
 * </description>
 *
 * <param type="int" name="fd">file descriptor</param>
 *
 * <return>
 * 	a pointer to a ligne reading on the file descriptor.
 * 	or
 * 	NULL if EOF or ERROR.
 * </return>
 *
 */

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*line;
	static char	*buff = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147183647)
		return (free(buff), buff = NULL, NULL);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	byte_read = 1;
	while (!(gnl_strchr(buff, '\n')) && byte_read > 0)
	{
		byte_read = read(fd, line, BUFFER_SIZE);
		if (byte_read <= 0 && buff == NULL)
		{
			buff = ft_free_gnl(buff, line);
			return (NULL);
		}
		*(line + byte_read) = 0;
		buff = gnl_strjoin(buff, line);
	}
	free(line);
	line = ft_get_line(buff);
	buff = gnl_substr(buff);
	return (line);
}
