/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:10:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/13 09:37:47 by nfordoxc         ###   Luxembourg.lu     */
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
 *	Setting raycasting
 */

# define FOV		M_PI / 3					//	Field of view 60°
# define D_SCREAN	(WIDTH / 2) / tan(FOV / 2)	//	distance to screan
# define STEP_RAY	0.1							//	step ray

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

void	ft_raycasting(t_info *info);
void	ft_move(t_info *info, double angle_offset, int dir);

#endif