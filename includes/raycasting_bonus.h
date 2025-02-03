/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:06:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/03 14:55:19 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "./color_bonus.h"

# define FOV		M_PI / 3					//	Field of view 60°
# define T_HALF_FOV	tan(FOV / 2)				//	tan of half FOV
# define D_SCREAN	(WIDTH / 2) / tan(FOV / 2)	//	distance to screan
# define NBRAY		1500						//	number of ray
# define RAY_STEP	WIDTH / NBRAY				//	pad of a ray
# define N_WALL		YELLOW
# define S_WALL		BLUE
# define E_WALL		GREEN
# define W_WALL		RED

/*
 *	Functions raycasting
 */

int		ft_raycasting(t_info *info);
int		ft_put_wall(t_img *wall, int y_start, int y_end, int y, int tex_x);

void	ft_set_limit_wall(t_info *info, t_raycast *ray);
void	ft_draw_door(t_info *info, t_img *door, double *z_buffer);
void	ft_set_pixel(t_info *info, int x, int y_start, int y_end, int color);

#endif