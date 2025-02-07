/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:10:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/07 14:02:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_GAME_H
# define SETTING_GAME_H

# define TITLE			"Cube3D"				//	project name
# define WIDTH			1500					//	1920
# define HEIGHT			1000					//	1080
# define NBTEXTURES		6						//	number of textures
# define ROTATE			0.02					//	speed rotating
# define STEP			0.05					//	speed moving
# define D_WALL			0.2						//	distance min near wall

/*
 *	Functions game
 */

int				ft_press_key(int keysym, t_info *info);
int				ft_get_color(int t, int r, int g, int b);
int				ft_press_key_mac(int keysym, t_info *info);

unsigned int	ft_get_pixel_color(t_img *img, int x, int y);

void			ft_rotate(t_info *info, double angle_rotation);
void			ft_get_size_xpm(t_info *info, char *path, int i);
void			ft_move(t_info *info, double angle_offset, int dir);
void			ft_put_pixel_color(t_win *win, int x, int y, int color);
void			ft_put_imgalpha(t_win *img_d, t_img *img_s, int x, int y);
void			ft_check_wall(t_info *info, double *new_x, double *new_y);

#endif