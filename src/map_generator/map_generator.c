/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:18:18 by phkevin           #+#    #+#             */
/*   Updated: 2024/11/11 16:31:11 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

/**
 * @brief Alloue de la mémoire pour une carte 2D.
 *
 * Cette fonction alloue de la mémoire pour une carte sous forme de tableau 
 * de chaînes de caractères. La carte est de taille xmap x ymap, où xmap 
 * représente le nombre de lignes et ymap le nombre de colonnes. La 
 * dernière ligne du tableau est définie sur NULL.
 *
 * @param f Pointeur vers la structure de données contenant les dimensions 
 * de la carte.
 * @return Pointeur vers le tableau de caractères alloué, ou NULL en cas 
 * d'échec de l'allocation.
 */
static char	**allocmap(t_data *f)
{
	int	i;
	char **map;

	i = 0;
	map = (char **)malloc((f->xmap + 1)  * sizeof(char *));
	if (!map)
		return NULL;
	while (i < f->xmap)
	{
		map[i] = (char *)malloc((f->ymap) * sizeof(char));
		if (!map[i])
		{
			while(i > 0)
			{
				i--;
				free(map[i]);
			}
			free(map);
			return NULL;
		}   
		i++;
	}
	map[i] = NULL;
	return (map);
}

/**
 * @brief Écrit une ligne de la carte dans la structure de données.
 *
 * Cette fonction copie une chaîne de caractères représentant une ligne 
 * de la carte dans le tableau de carte de la structure de données. 
 * Elle s'assure de ne pas dépasser la longueur maximale définie par 
 * ymap, et elle ajoute un caractère nul à la fin de la chaîne.
 *
 * @param str La chaîne de caractères à copier dans la carte.
 * @param f Pointeur vers la structure de données contenant la carte.
 * @param l L'index de la ligne dans laquelle écrire la chaîne.
 */
static void	writemap(char *str, t_data *f, int l)
{
	int	i;

	i = 0;
	while (i < f->ymap - 1 && str[i] != '\0')
	{
		f->map[l][i] = str[i];
		i++; 
	}
	f->map[l][i] = '\0';
}

/**
 * @brief Met à jour les dimensions de la carte à partir d'une ligne donnée.
 *
 * Cette fonction analyse une ligne de la carte pour mettre à jour le 
 * nombre de lignes (xmap) et la longueur maximale de la ligne (ymap).
 * Elle incrémente d'abord le compteur de lignes, puis vérifie si la 
 * longueur de la ligne actuelle dépasse la longueur maximale précédente.
 *
 * @param str La chaîne de caractères représentant une ligne de la carte.
 * @param f Pointeur vers la structure de données contenant les dimensions de 
 * la carte.
 */
void	ft_size_map(char *str, t_data *f)
{
	int x;

	x = 0;
	f->xmap++;
	while (str[x] != '\0')
		x++;
	if (x > f->ymap)
		f->ymap = x;
}

/**
 * @brief Écrit la carte à partir d'un fichier dans la structure de données.
 *
 * Cette fonction ouvre un fichier en lecture, alloue de la mémoire pour la
 * carte, puis lit chaque ligne du fichier. Si la ligne "MAP" est rencontrée,
 * la fonction commence à écrire les lignes suivantes dans la structure de 
 * données de la carte. Une fois la lecture terminée, la fonction valide la
 * carte.
 *
 * @param fic Le nom du fichier contenant la définition de la carte.
 * @param f Pointeur vers la structure de données contenant la carte.
 */
void	ft_write_map(char *fic, t_data *f)
{
	int		fd;
	char	*buffer;
	int		map;
	int		line;

	fd = open(fic, O_RDONLY);
	f->map = allocmap(f);
	map = 0;
	line = 0;
	while(1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break;
		if (map == 1)
		{
			writemap(buffer, f, line);
			line++;
		}
		if (ft_strequal(buffer , "MAP\n"))
			map = 1;
		free(buffer);
		buffer = NULL;
	}
	ft_validate_map(f);
}