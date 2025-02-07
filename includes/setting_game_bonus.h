/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:10:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/07 08:32:39 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_GAME_BONUS_H
# define SETTING_GAME_BONUS_H

# define TITLE			"Cube3D++"				//	project name
# define WIDTH			1500					//	1920
# define HEIGHT			1000					//	1080
# define NBTEXTURES		6						//	number of textures
# define ROTATE			0.02					//	in radian
# define STEP			0.05					//	size of step
# define D_WALL			0.3						//	distance min near wall
# define D_DOOR			0.2						//	distance min near door

/*
 *	Collectable
 */

# define N_COL			4						//	number of image
# define S_COL			64						//	size of collectable
# define CUR_COL		0						//	current image
# define SPEED_COL		50000

/*
 *	FPS
 */

# define FPS 			30
# define FRAMT 			33.3333333				//	(1000 / FPS)

/*
 *	Functions game
 */

int				ft_press_key(int keysym, t_info *info);
int				ft_get_color(int t, int r, int g, int b);
int				ft_mouse_move(int x, int y, t_info *info);
int				ft_press_key_mac(int keysym, t_info *info);

unsigned int	ft_get_pixel_color(t_img *img, int x, int y);

void			ft_open_door(t_info *info);
void			ft_close_door(t_info *info);
void			ft_rotate(t_info *info, double angle_rotation);
void			ft_move(t_info *info, double angle_offset, int dir);
void			ft_put_pixel_color(t_win *win, int x, int y, int color);
void			ft_check_wall(t_info *info, double *new_x, double *new_y);
void			ft_check_door(t_info *info, double *new_x, double *new_y);
void			ft_put_imgalpha(t_win *img_d, t_img *img_s, int x, int y);

#endif