/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:06:45 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 17:59:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "./color_bonus.h"

# define FOV		M_PI / 3					//	Field of view 60°
# define T_HALF_FOV	tan(FOV / 2)				//	tan of half FOV
# define D_SCREAN	(WIDTH / 2) / tan(FOV / 2)	//	distance to screan
# define N_WALL		YELLOW
# define S_WALL		BLUE
# define E_WALL		GREEN
# define W_WALL		RED

/*
 *	Functions raycasting
 */

int		ft_raycasting(t_info *info);

void	ft_free_ray_list(t_lst_ray *lst_ray);
void	ft_put_sky(t_info *info, int x, int y);
void	ft_put_floor(t_info *info, int x, int y);
void	ft_hit_door(t_info *info, t_raycast *ray);
void	ft_hit_wall(t_info *info, t_raycast *ray);
void	ft_set_pixel(t_info *info, t_raycast *ray);
void	ft_hit_collect(t_info *info, t_raycast *ray);
void	ft_draw_image(t_info *info, t_lst_ray *list);
void	ft_set_limit_wall(t_info *info, t_raycast *ray);
void	add_ray_to_list(t_lst_ray **list, t_raycast ray);
void	ft_draw_door(t_info *info, t_img *door, double *z_buffer);

#endif