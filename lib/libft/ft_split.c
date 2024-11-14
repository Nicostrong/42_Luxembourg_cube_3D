/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:25:11 by phkevin           #+#    #+#             */
/*   Updated: 2024/02/26 11:25:12 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Libère la mémoire allouée pour un tableau de chaînes de caractères.
 *
 * Cette fonction libère la mémoire allouée pour un tableau de chaînes de 
 * caractères terminé par un pointeur NULL. Elle libère d'abord la mémoire de 
 * chaque chaîne de caractères, puis celle du tableau lui-même.
 *
 * @param str Le tableau de chaînes de caractères à libérer.
 */
void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

/**
 * @brief Compte le nombre de mots dans une chaîne de caractères en fonction 
 * d'un délimiteur.
 *
 * Cette fonction compte le nombre de mots dans la chaîne de caractères `s`, 
 * en considérant le caractère `c` comme délimiteur. Un mot est défini comme 
 * une séquence de caractères ne contenant pas le délimiteur `c`.
 *
 * @param s La chaîne de caractères à analyser.
 * @param c Le caractère délimiteur.
 * @return Le nombre de mots dans la chaîne de caractères.
 */
static int	ft_countword(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 1;
	i = 1;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			nb++;
		i++;
	}
	if (s[i - 1] == c)
		nb--;
	return (nb);
}

/**
 * @brief Extrait un mot d'une chaîne de caractères en fonction d'un délimiteur.
 *
 * Cette fonction extrait un mot de la chaîne de caractères `s`, en commençant à
 * l'indice `start` et en utilisant le caractère `c` comme délimiteur. Le mot 
 * extrait est alloué dynamiquement et renvoyé.
 *
 * @param s La chaîne de caractères à analyser.
 * @param c Le caractère délimiteur.
 * @param start L'indice à partir duquel commencer l'extraction.
 * @return Un pointeur vers le mot extrait, ou NULL en cas d'erreur 
 * d'allocation.
 */
static char	*get_word(char const *s, char c, int start)
{
	char	*res;
	int		i;
	int		si;

	i = 0;
	si = 0;
	while (s[start + si] != '\0' && s[start + si] != c)
		si++;
	res = (char *)malloc((si + 1) * sizeof(char *));
	while (i < si)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/**
 * @brief Divise une chaîne de caractères en mots en fonction d'un délimiteur.
 *
 * Cette fonction divise la chaîne de caractères `s` en mots en utilisant le 
 * caractère `c` comme délimiteur. Les mots extraits sont stockés dans un 
 * tableau de chaînes de caractères qui est alloué dynamiquement. Le tableau 
 * résultant est terminé par un pointeur NULL.
 *
 * @param s La chaîne de caractères à diviser.
 * @param c Le caractère délimiteur.
 * @return Un tableau de chaînes de caractères représentant les mots extraits, 
 * ou NULL en cas d'erreur d'allocation.
 */
char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*word;
	int		i;
	int		i_res;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	i = 0;
	i_res = 0;
	while (s[i] == c && *s)
		i++;
	while (i_res < ft_countword(s, c))
	{
		word = get_word(s, c, i);
		res[i_res++] = ft_strdup(word);
		i += ft_strlen(word);
		free(word);
		while (s[i] == c)
			i++;
	}
	res[i_res] = NULL;
	return (res);
}
