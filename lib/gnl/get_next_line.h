/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:12:48 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/10/29 13:52:00 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
 * Define BUFFER_SIZE
 */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  100
# endif

/*
 * Include Libc
 */

# include <unistd.h>
# include <stdlib.h>

/*
 * get_next_line.c
 */

char	*get_next_line(int fd);
/*
 * get_next_line_utils.c
 */

char	*gnl_strjoin(char *buff, char *lu);
char	*gnl_strchr(char const *str, int c);

size_t	gnl_strlen(char *str);

#endif
