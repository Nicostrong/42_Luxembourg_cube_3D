/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:10:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/21 17:28:47 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_GAME_H
# define SETTING_GAME_H

# define TITLE			"Cube3D"				//	Project name
# define WIDTH			1500					//	1920
# define HEIGHT			1000					//	1080
# define NBTEXTURES		6						//	Number of textures

/*
 *	FPS
 */

# define FPS 			30
# define FRAMT 			(1000 / FPS)
# define SPEED_COL		50000

/*
 *	Functions game
 */

int		ft_press_key(int keysym, t_info *info);
int		ft_mouse_move(int x, int y, t_info *info);
int		ft_press_key_mac(int keysym, t_info *info);

void	ft_open_door(t_info *info);
void	ft_raycasting(t_info *info);
void	ft_move(t_info *info, double angle_offset, int dir);
void	ft_check_wall(t_info *info, double *new_x, double *new_y);

#endif