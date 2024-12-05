/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:46:14 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/05 08:56:15 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define E_USAGE	"\033[1;31mUsage\n - ./cub3d <map.cub>\033[0m\n"
# define E_CUB		"\033[1;31mError\n - Not a .cub file\033[0m\n"
# define E_HIDDEN	"\033[1;31mError\n - Hidden file .cub not a map\033[0m\n"
# define E_MAP		"\033[1;31mError\n - Bad map.\033[0m\n"
# define E_XPM		"\033[1;31mError\n - XPM error.\033[0m\n"
# define E_TEXTURE	"\033[1;31mError\n - File texture.\033[0m\n"
# define E_SKY		"\033[1;31mError\n - Missing sky.\033[0m\n"
# define E_FLOOR	"\033[1;31mError\n - Missing floor.\033[0m\n"
# define E_NO		"\033[1;31mError\n - Missing NO.\033[0m\n"
# define E_SO		"\033[1;31mError\n - Missing SO.\033[0m\n"
# define E_EA		"\033[1;31mError\n - Missing EA.\033[0m\n"
# define E_WE		"\033[1;31mError\n - Missing WE.\033[0m\n"
# define E_C		"\033[1;31mError\n - Missing C.\033[0m\n"
# define E_F		"\033[1;31mError\n - Missing F.\033[0m\n"
# define E_CT		"\033[1;31mError\n - File texture sky.\033[0m\n"
# define E_FT		"\033[1;31mError\n - File texture floor.\033[0m\n"
# define E_CLOSE	"\033[1;31mError\n - Map not closed.\033[0m\n"
# define E_SPAWN	"\033[1;31mError\n - Missing player on map.\033[0m\n"
# define E_EXIT		"\033[1;31mError\n - Missing exit on map.\033[0m\n"
# define E_MALLOC	"\033[1;31mError\n - Malloc.\033[0m\n"
# define E_OPEN		"\033[1;31mError\n - File not readable.\033[0m\n"

/*
 *	Fonction error
 */


#endif
