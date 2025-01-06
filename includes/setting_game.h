/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:10:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/06 11:32:31 by nfordoxc         ###   Luxembourg.lu     */
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
# define STEP			2.0						//	size of step
# define D_WALL			5.0						//	distance min near wall
//# define ROTATE			M_PI / 8				//	rotation value for 16 step
//# define ROTATE			M_PI / 10				//	rotation value for 20 step
# define ROTATE			0.01


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
int		ft_mouse_move(int x, int y, t_info *info);
int		ft_press_key_mac(int keysym, t_info *info);

//void	ft_render(t_info *info);
void	ft_minimap(t_info *info);
void	ft_put_circle(t_info *info, int centx, int centy);
void	ft_move(t_info *info, double new_padx, double new_pady);

#endif