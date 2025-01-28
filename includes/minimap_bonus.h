/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:21:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/28 14:14:51 by nfordoxc         ###   Luxembourg.lu     */
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

/*
 *	Functions minimap
 */

char	**ft_get_minimap(t_info *info);

int		ft_minimap(t_info *info);

void	ft_get_widths(t_info *info);
void	ft_get_heights(t_info *info);
void	ft_put_circle(t_info *info, int centx, int centy);
void	ft_put_player(t_info *info, t_img *player, int x, int y);

#endif