/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:08:18 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/04 14:12:12 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgetnextline.h"

/**
 * @brief Libère la mémoire allouée pour une chaîne de caractères.
 *
 * Cette fonction libère la mémoire allouée pour la chaîne de caractères `ptr`
 * en utilisant la fonction `free()` et attribue NULL à `ptr`.
 *
 * @param ptr Le pointeur vers la chaîne de caractères à libérer.
 */
void	ft_free_gnl(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

/**
 * @brief Récupère la première ligne de la chaîne de caractères.
 *
 * Cette fonction extrait la première ligne de la chaîne de caractères `str`,
 * c'est-à-dire tous les caractères jusqu'au premier retour à la ligne inclus.
 *
 * @param str La chaîne de caractères à traiter.
 * @return Un pointeur vers une nouvelle chaîne contenant la première ligne de
 * `str`.
 * @return NULL si `str` est NULL ou une chaîne vide.
 */
static char	*ft_line_left(char *str)
{
	char	*res;
	size_t	i;

	if (!str || *str == '\0')
		return (NULL);
	i = ft_end_line_gnl(str);
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/**
 * @brief Récupère la partie de la chaîne de caractères après la première ligne.
 *
 * Cette fonction extrait la partie de la chaîne de caractères `str` qui se
 * trouve après la première ligne, c'est-à-dire tous les caractères après le
 * premier retour à la ligne.
 *
 * @param str La chaîne de caractères à traiter.
 * @return Un pointeur vers une nouvelle chaîne contenant la partie de `str`
 * après la première ligne.
 * @return NULL si `str` est NULL ou une chaîne vide.
 */
static char	*ft_line_right(char *str)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!str || str[0] == '\0')
		return (ft_free_gnl(str), NULL);
	i = ft_end_line_gnl(str);
	res = (char *)malloc((ft_strlen_gnl(str) - i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	if (res[0] == '\0')
		return (ft_free_gnl(res), ft_free_gnl(str), NULL);
	ft_free_gnl(str);
	return (res);
}

/**
 * @brief Lit une ligne depuis un descripteur de fichier.
 *
 * Cette fonction lit une ligne depuis le descripteur de fichier spécifié `fd`.
 * Elle retourne cette ligne lue sans le caractère de fin de ligne '\n'.
 *
 * @param fd Le descripteur de fichier à partir duquel lire.
 * @return Un pointeur vers la ligne lue, sans le caractère de fin de ligne
 * '\n'.
 * @return NULL si une erreur se produit lors de la lecture ou si la lecture
 * est terminée.
 */
char	*get_next_line(int fd)
{
	int			b_read;
	char		*buffer;
	static char	*read_buffer = NULL;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (ft_free_gnl(buffer), NULL);
	b_read = BUFFER_SIZE;
	while (!(ft_strchr_gnl(read_buffer, '\n')) && b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
			return (ft_free_gnl(buffer), ft_free_gnl(read_buffer), NULL);
		buffer[b_read] = '\0';
		read_buffer = ft_strjoin_gnl(read_buffer, buffer);
	}
	ft_free_gnl(buffer);
	buffer = ft_line_left(read_buffer);
	read_buffer = ft_line_right(read_buffer);
	return (buffer);
}
