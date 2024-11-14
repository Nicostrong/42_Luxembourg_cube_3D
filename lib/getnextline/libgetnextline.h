/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgetnextline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:28:48 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/04 14:12:38 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGETNEXTLINE_H
# define LIBGETNEXTLINE_H

# include <unistd.h>
# include <stdlib.h>

/*
 * Definition de la taille par defaut du buffer
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

/*
 * Fonction get next line
 */
char	*get_next_line(int fd);
void	ft_free_gnl(char *ptr);

/*
 * Fonction utils
 */
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char *str);
size_t	ft_end_line_gnl(char *str);

#endif
