/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:17:18 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/08 15:33:03 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_BONUS_H
# define CUBE_3D_BONUS_H

/*
 *	Standart library
 */

# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <math.h>
# include <sys/time.h>

# if defined(__linux__)

	# include "../lib/mlx_linux/mlx.h"
	# include <X11/keysym.h>
	# define LINUX			1
	# define MACOS			0
	# define LOOP_END		mlx_loop_end
	# define DESTROY		mlx_destroy_display

# elif defined(__APPLE__) && defined(__MACH__)

	# include "../lib/mlx_mac/mlx.h"
	# define MACOS			1
	# define LINUX			0
	# define KA				0
	# define KE				14
	# define KZ				6
	# define KQ				12
	# define KS				1
	# define KD				2
	# define UP				126
	# define DOWN			125
	# define LEFT			123
	# define RIGHT			124
	# define ESCAP			53
	# define SPACE			49
	# define LOOP_END		(void)
	# define DESTROY		(void)

# endif

/*
 *	Personal Library
 */

# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "./structures_bonus.h"
# include "./color_bonus.h"
# include "./error_bonus.h"

/*
 *	DEBUG
 */

void	ft_print_img(t_img *img);
void	ft_print_map(t_info *info);
void	ft_print_info(t_info *info);
void	ft_print_anim(t_info *info);
void	ft_print_thread(t_info *info);
void	ft_print_color(t_color *color);
void	ft_print_sky_floor(t_info *info);
void	ft_print_user_data(t_info *info);
void	ft_print_minimap(t_info *info, char **map);
void	ft_print_ray(t_info *info, t_raycast *ray);

/*
 * Fonctions to start the programm
 */

int		ft_exit(t_info *info);
int		ft_perror_exit(char *str_error, t_info *info);

void	ft_init_mlx(t_info *info);
void	ft_read_file(t_info *info);
void	ft_check_map(t_info *info);
void	ft_check_arg(int argc, char **argv);

t_color	*ft_set_color_struct(t_info *info, char **a_color);

#endif
