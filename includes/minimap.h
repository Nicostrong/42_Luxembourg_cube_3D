/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:21:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/13 09:38:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

/*
 *	Setting Mini Map
 */

# define PRAY 			5						//	size player on minimap
# define LENRAY			500						//	lenght ray
# define NBRAY			10						//	number ray
# define RAYECART		10.0					//	scale ray
# define WSCALE			4						//	size wall
# define MINI_TITRE		"Mini map"
# define MINI_W			280
# define MINI_H			200
# define MINI_I_PL		"./gfx/m_player.xpm"	//	image player
# define MINI_S_PL		10						//	size image player
# define MINI_S_BLOC	40						//	size bloc
# define STEP			0.05					//	size of step
# define D_WALL			0.2						//	distance min near wall
# define ROTATE			0.05

/*
 *	Functions minimap
 */

char	**ft_get_minimap(t_info *info);

void	ft_minimap(t_info *info);
void	ft_get_widths(t_info *info);
void	ft_get_heights(t_info *info);
void	ft_put_circle(t_info *info, int centx, int centy);

#endif