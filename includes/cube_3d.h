/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:17:18 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/22 12:58:10 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

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

# if defined(DEBUG)
	# define DEBUG	1
# else
	# define DEBUG	0
# endif

# if defined(BONUS)
	# define BONUS	1
# else
	# define BONUS	0
# endif

/*
*	Personal Library
*/

# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "./structures.h"
# include "./color.h"

/*
* Fonction init mlx
*/

int		ft_exit(t_info *info);
int		ft_check_arg(int argc, char **argv);
int		ft_perror_exit(char *str_error, t_info *info);

void	ft_init_mlx(t_info *info);
void	ft_read_file(t_info *info);
void	ft_check_map(t_info *info);

#endif
