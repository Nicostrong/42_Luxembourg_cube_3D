/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:46:14 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/10 10:48:43 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define E_USAGE	"\033[1;31mUsage\n\t./cub3d <map.cub>\033[0m\n"
# define E_MLX		"\033[1;31mError\n\tMlx error.\033[0m\n"
# define E_CUB		"\033[1;31mError\n\tNot a .cub file\033[0m\n"
# define E_HIDDEN	"\033[1;31mError\n\tHidden file .cub not .cub file\033[0m\n"
# define E_EXIST	"\033[1;31mError\n\tFile not exist.\033[0m\n"
# define E_OPEN		"\033[1;31mError\n\tFile not readable.\033[0m\n"
# define E_READ		"\033[1;31mError\n\tReading error.\033[0m\n"
# define E_PARAM	"\033[1;31mError\n\tFile .cub not valid\033[0m\n"
# define E_MAP		"\033[1;31mError\n\tMissing or bad map.\033[0m\n"
# define E_SKY		"\033[1;31mError\n\tMissing sky.\033[0m\n"
# define E_FLOOR	"\033[1;31mError\n\tMissing floor.\033[0m\n"
# define E_NO		"\033[1;31mError\n\tMissing NO.\033[0m\n"
# define E_SO		"\033[1;31mError\n\tMissing SO.\033[0m\n"
# define E_EA		"\033[1;31mError\n\tMissing EA.\033[0m\n"
# define E_WE		"\033[1;31mError\n\tMissing WE.\033[0m\n"
# define E_C		"\033[1;31mError\n\tMissing C.\033[0m\n"
# define E_F		"\033[1;31mError\n\tMissing F.\033[0m\n"
# define E_TEXTURE	"\033[1;31mError\n\tFile texture.\033[0m\n"
# define E_CT		"\033[1;31mError\n\tFile texture sky.\033[0m\n"
# define E_FT		"\033[1;31mError\n\tFile texture floor.\033[0m\n"
# define E_NOT		"\033[1;31mError\n\tFile texture wall north.\033[0m\n"
# define E_SOT		"\033[1;31mError\n\tFile texture wall south.\033[0m\n"
# define E_EAT		"\033[1;31mError\n\tFile texture wall east.\033[0m\n"
# define E_WET		"\033[1;31mError\n\tFile texture wall weast.\033[0m\n"
# define E_COLOR	"\033[1;31mError\n\tValue color not available.\033[0m\n"
# define E_XPM		"\033[1;31mError\n\tXPM error.\033[0m\n"
# define E_CLOSE	"\033[1;31mError\n\tMap not closed.\033[0m\n"
# define E_SPAWN	"\033[1;31mError\n\tMissing player on map.\033[0m\n"
# define E_EXIT		"\033[1;31mError\n\tMissing exit on map.\033[0m\n"
# define E_MALLOC	"\033[1;31mError\n\tMalloc.\033[0m\n"
# define E_WIN		"\033[1;31mError\n\tmlx new window.\033[0m\n"
# define E_IMG		"\033[1;31mError\n\tmlx new image.\033[0m\n"
# define E_ADR		"\033[1;31mError\n\tmlx get data addr.\033[0m\n"
# define E_M_WIN	"\033[1;31mError\n\tmlx new window for minimap.\033[0m\n"
# define E_M_IMG	"\033[1;31mError\n\tmlx new image for minimap.\033[0m\n"
# define E_M_ADR	"\033[1;31mError\n\tmlx get data addr for minimap.\033[0m\n"

#define W_N_IMG_E	1 << 0
#define W_S_IMG_E	1 << 1
#define W_E_IMG_E	1 << 2
#define W_W_IMG_E	1 << 3
#define F_IMG_E		1 << 4
#define S_IMG_E		1 << 5

/*
 *	Fonction error
 */

int		ft_perror_exit(char *str_error, t_info *info);

void	ft_error_msg(int value, int exit, t_info *info);

#endif
