/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:35:39 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/04 14:07:37 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgetnextline.h"

/**
 * @brief Calcule la longueur d'une chaîne de caractères, excluant le caractère
 * nul de fin de chaîne.
 *
 * Cette fonction calcule la longueur de la chaîne de caractères spécifiée
 * `str`,
 * excluant le caractère nul de fin de chaîne '\0'.
 *
 * @param str La chaîne de caractères dont calculer la longueur.
 * @return La longueur de la chaîne de caractères, excluant le caractère nul de
 * fin de chaîne.
 */
size_t	ft_strlen_gnl(char *str)
{
	size_t	nb;

	nb = 0;
	while (str && str[nb] != '\0')
		nb++;
	return (nb);
}

/**
 * @brief Concatène deux chaînes de caractères.
 *
 * Cette fonction concatène les chaînes de caractères spécifiées `s1` et `s2`.
 *
 * @param s1 La première chaîne de caractères à concaténer.
 * @param s2 La deuxième chaîne de caractères à concaténer.
 * @return Un pointeur vers la nouvelle chaîne de caractères résultante, ou
 * NULL en cas d'échec.
 * @warning Il est de la responsabilité de l'appelant de libérer la mémoire
 * allouée pour la nouvelle chaîne de caractères.
 */
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		size1;
	int		size2;

	size1 = ft_strlen_gnl(s1);
	size2 = ft_strlen_gnl(s2);
	new = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2 && s2[++j])
		new[i++] = s2[j];
	new[i] = '\0';
	return (ft_free_gnl(s1), new);
}

/**
 * @brief Localise la première occurrence d'un caractère dans une chaîne de
 * caractères.
 *
 * Cette fonction recherche le caractère spécifié `c` dans la chaîne de
 * caractères `s`.
 *
 * @param s La chaîne de caractères dans laquelle chercher.
 * @param c Le caractère à chercher.
 * @return Un pointeur vers l'emplacement de la première occurrence de `c`
 * dans `s`, ou NULL si `c` n'est pas trouvé.
 */
char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

/**
 * @brief Calcule la longueur de la ligne actuelle ou le nombre de caractères
 * avant le prochain '\n'.
 *
 * Cette fonction retourne la longueur de la ligne actuelle dans la chaîne de
 * caractères `str`.
 * Si la ligne contient un '\n', la fonction retourne le nombre de caractères
 * jusqu'à cet '\n' inclus.
 *
 * @param str La chaîne de caractères dans laquelle chercher la ligne.
 * @return La longueur de la ligne actuelle ou le nombre de caractères avant
 * le prochain '\n'.
 */
size_t	ft_end_line_gnl(char *str)
{
	size_t	nb;

	nb = 0;
	while (str[nb] != '\0' && str[nb] != '\n')
		nb++;
	if (str[nb] == '\n')
		nb++;
	return (nb);
}
