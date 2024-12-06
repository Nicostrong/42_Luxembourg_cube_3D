/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:20:55 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:30:03 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

/**
 * @brief Initialise la position et la direction de l'utilisateur.
 * 
 * Cette fonction configure les coordonnées de l'utilisateur ainsi que sa
 * direction initiale en fonction du caractère d'orientation fourni :
 * - 'N' pour 0° (Nord)
 * - 'S' pour 90° (Sud)
 * - 'E' pour 180° (Est)
 * - 'W' pour 270° (Ouest)
 * 
 * @param f Structure des données contenant les informations de l'utilisateur.
 * @param x Coordonnée x de l'utilisateur.
 * @param y Coordonnée y de l'utilisateur.
 * @param c Caractère indiquant l'orientation initiale (N, S, E, ou W).
 */
static void ft_inituser(t_data *f, int x, int y, int c)
{
	f->userd.coox = x;
	f->userd.cooy = y;
	if (c == 'N')
		f->userd.dir += 0;
	if (c == 'E')
		f->userd.dir += 90;
	if (c == 'S')
		f->userd.dir += 180;
	if (c == 'W')
		f->userd.dir += 270;
}

/**
 * @brief Vérifie la présence d'un point de spawn dans la carte.
 *
 * Cette fonction parcourt la carte pour identifier la position du point de
 * spawn du joueur (indiqué par 'N', 'S', 'E', ou 'W'). Si un point de
 * spawn est trouvé, elle met à jour les coordonnées dans la structure t_data
 * et active le drapeau isspawn. Une seule position de spawn est attendue.
 *
 * @param map Le tableau 2D représentant la carte du jeu.
 * @param f Pointeur vers la structure t_data contenant les informations 
 *          du jeu, telles que les coordonnées du spawn.
 */
static void	is_spawn(char **map, t_data *f)
{
	int x;
	int y;

	x = 0;
	while(map[x] != NULL)
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] ==/**
 * @brief Convertit une chaîne de caractères en tableau de couleurs RGB.
 * 
 * Cette fonction divise la chaîne `str` en trois sous-chaînes séparées par des
 * virgules, puis les convertit en valeurs entières, représentant les
 * composantes rouge, verte et bleue (RGB).
 * 
 * @param str La chaîne de caractères à analyser (format "R,G,B").
 * @return Un tableau de trois entiers représentant les valeurs RGB, ou `NULL`
 *         en cas d'erreur d'allocation.
 */'N' || map[x][y] == 'S' || map[x][y] == 'E' 
			|| map[x][y] == 'W')
			{
				f->isspawn = 1;
				f->spposx = x;
				f->spposy = y;
				ft_inituser(f, x, y, map[x][y]);
				return  ;
			}
			y++;
		}
		x++;
	}
}

/**
 * @brief Exécute un algorithme de flood fill pour valider les espaces de la 
 * map.
 *
 * Cette fonction parcourt la carte de manière récursive à partir des
 * coordonnées (x, y). Elle marque les espaces comme invalides s'ils sont 
 * entourés de caractères non valides ou s'ils ne sont pas fermés par des
 * murs ('1'). Si une condition de carte invalide est trouvée, le drapeau 
 * ismapvalid dans la structure t_data est mis à 0.
 *
 * @param map Le tableau 2D représentant la carte du jeu.
 * @param x La coordonnée x de la cellule actuelle dans la carte.
 * @param y La coordonnée y de la cellule actuelle dans la carte.
 * @param f Pointeur vers la structure t_data contenant les dimensions de la 
 *          carte et le drapeau de validité.
 */
static void	ft_flood_fill(char **map, int x, int y, t_data *f)
{
	if (x == 0 || x == f->xmap - 1 || y == 0 || y == f->ymap - 1)
	{
		if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S' || 
			map[x][y] == 'E' || map[x][y] == 'W')
		{
			f->ismapvalid = 0;
			return  ;
		} 
	}
	if (x < 1 || y < 1 || x >= f->xmap || y >= f->ymap)
		return  ; 
	char current_char = map[x][y];
	if (current_char == '1' || current_char == '2')
		return  ;
	if (current_char == '0') {
		if (map[x - 1][y] == ' ' || map[x - 1][y] == '\n' || 
			map[x - 1][y] == '\0' || map[x + 1][y] == ' ' || 
			map[x + 1][y] == '\n' || map[x + 1][y] == '\0' || 
			map[x][y - 1] == ' ' || map[x][y - 1] == '\n' || 
			map[x][y - 1] == '\0' || map[x][y + 1] == ' ' || 
			map[x][y + 1] == '\n' || map[x][y + 1] == '\0') {
			f->ismapvalid = 0;
			return  ;
		}
	}
	if (current_char != '0' && current_char != ' ' && current_char != 'N' &&
		current_char != 'S' && current_char != 'E' && current_char != 'W') {
		f->ismapvalid = 0;
		return  ;
	}
	map[x][y] = '2';
	ft_flood_fill(map, x, y - 1, f);
	ft_flood_fill(map, x + 1, y, f);
	ft_flood_fill(map, x, y + 1, f);
	ft_flood_fill(map, x - 1, y, f); 
}

/**
 * @brief Valide la carte et gère les erreurs associées.
 *
 * Cette fonction crée une copie de la carte, exécute l'algorithme de flood 
 * fill pour vérifier l'accessibilité et la présence d'un spawn. Si la carte 
 * n'est pas valide ou si un spawn n'est pas trouvé, un message d'erreur est 
 * affiché et le programme se termine.
 *
 * @param f Pointeur vers la structure t_data contenant les informations de
 *          la carte à valider.
 */
void    ft_validate_map(t_data *f)
{
	char	**copy_map;

	copy_map = ft_copy_strarray(f->map);
	is_spawn(copy_map, f);
	if (f->isspawn)
	{
		ft_flood_fill(copy_map, f->spposx, f->spposy, f);
	}
	ft_free_array(copy_map);
	if (!f->isspawn || !f->ismapvalid) 
	{
		if (!f->isspawn) 
			ft_printf_error("\033[1;31mError\n- Map error: Spawn\033[0m\n");
		else if (!f->ismapvalid) 
			ft_printf_error("\033[1;31mError\n- Map error: Invalide\033[0m\n");
		ft_errclose(f);
	}
}
