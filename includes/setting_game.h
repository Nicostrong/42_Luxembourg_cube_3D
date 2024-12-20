/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:10:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/20 11:16:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_GAME_H
# define SETTING_GAME_H

# define TITLE			"Cube3D"				//	Project name
# define WIDTH			1500					//	1920
# define HEIGHT			1000					//	1080
# define NBTEXTURES		6						//	Number of textures

# define ISAZERTY		0						//	bool keyboard azerty

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


/*
 *	Mouse setting
 */

# define LEFT_CLIC		1
# define MIDDLE_CLIC	2
# define RIGHT_CLIC		3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

/*
 *	FPS
 */

# define FPS 			30
# define FRAMT 			(1000 / FPS)
# define SPEED_COL		50000

/*
 *	Mouse sens
 */

# define SENSMOU 		1

/*
 *	Event game
 */

int		ft_press_key(int keysym, t_info *info);
int		ft_press_key_mac(int keysym, t_info *info);

void	ft_up(t_info *info);
void	ft_down(t_info *info);
void	ft_left(t_info *info);
void	ft_right(t_info *info);
//void	ft_render(t_info *info);
void	ft_minimap(t_info *info);
void	ft_put_circle(t_info *info, int centx, int centy);

#endif