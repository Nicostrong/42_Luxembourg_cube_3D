/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:21:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/24 14:37:12 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "color_bonus.h"

/*
 *	Setting Mini Map
 */

# define MINI_TITRE		"Mini map"
# define MINI_W			280
# define MINI_H			200
# define MINI_I_PL		"./gfx/m_player.xpm"	//	image player
# define MINI_S_PL		10						//	size image player
# define MINI_S_BLOC	40						//	size bloc
# define PRAY 			5						//	size player on minimap
# define WALL			SILVER
# define FLOOR			GOLD
# define EMPTY			PINK
# define DOOR			BLACK
# define ITEM			BLUE

/*
 *	Functions minimap
 */

char			**ft_get_minimap(t_info *info);

int				ft_minimap(t_info *info);
int				ft_put_door(t_info *info, t_mini *mini);
int				ft_put_item(t_info *info, t_mini *mini);
int				ft_get_map_case(int coord, int *sizes, int max_value);

void			ft_get_widths(t_info *info);
void			ft_get_heights(t_info *info);
void			ft_put_circle(t_info *info, int centx, int centy);
void			ft_put_player(t_info *info, t_img *player, int x, int y);

void			ft_d_rmi(t_info *info, double x, double y, char **map);
void			ft_d_rma(t_info *info, double x, double y, char **map);
void			ft_d_r(t_info *info, double x, double y, char **map);

#endif