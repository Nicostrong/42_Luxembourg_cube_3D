/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:17:18 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/15 11:24:43 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

/*
*	Standart library
*/

# include "fcntl.h"
# include "stdio.h"
# include <math.h>
# include <sys/time.h>

# if defined(__linux__)

	# include "../lib/mlx_linux/mlx.h"
	# include <X11/keysym.h>
	# define LINUX			1
	# define MACOS			0
	# define LOOP_END(arg)	mlx_loop_end(arg)
	# define DESTROY(arg)	mlx_destroy_display(arg)

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
	# define LOOP_END(arg)
	# define DESTROY(arg)

# endif

# if defined(DEBUG)
	# define DEBUG 1
# else
	# define DEBUG 0
# endif

/*
*	Personal Library
*/

# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "./structures.h"
# include "./color.h"

/* DEBUG */
#ifndef DEBUG
# define DEBUG 0
#endif

/*
*Fonctions
*/

/*
*	Fonction event
*/
int		pr_key(int keysym, t_data *f);
int		rl_key(int keysym, t_data *f);
int		update_key(t_data *f);
int		mouse_click(int mocde);
//int		mouse_click(int mocde, int x, int y, t_data *f);
//int		mouse_move(int x, int y, t_data *f);

/*
*	Fonction close app
*/
int		ft_close(t_data *f);
void	ft_errclose(t_data *f);

/*
*	Fonction file
*/
void	fic_init(t_data *f, char *str);
int		is_ficexiste(char *fic);

/*
* Fonction init mlx
*/

//void	ft_init_mlx(t_data *f);
void	ft_init_mlx(t_info *info);

/*
* Fonction init
*/
//t_data	*init_struct(void);
void	init_struct(t_data *data);

/*
* Fonction render
*/
//void	ft_render(t_data *f);

/*
* Fonction load texture
*/
void	ft_load_skfl(t_data *f);
void	ft_load_wall(t_data *f);

/*
* Fonction validate
*/
void	ft_vali(char *fic, t_data *f);
void	ft_val_para(char *str, t_data *f);
int 	ft_exit_error(char *str, t_data *data);

/*
* Fonction draw
*/
//void	ft_pixel_put(t_data *data, int x, int y, int color);
//int		ft_get_color(int r, int g, int b);
//void	ft_put_circle(t_data *f, int centx, int centy);

/*
* Fonction key_wasd
*/
int		pr_key_wasd(int keysym, t_data *f);
int		rl_key_wasd(int keysym, t_data *f);

/*
* Fonction key_zqsd
*/
int		pr_key_zqsd(int keysym, t_data *f);
int		rl_key_zqsd(int keysym, t_data *f);

/*
* Fonction time
*/
long	ft_get_time_ms(void);

/*
* Fonction print minimap
*/
void	ft_print_fond(t_data *f, int sx, int sy);
void	ft_print_wall(t_data *f, int sx, int sy);
void	ft_print_spawn(t_data *f, int sx, int sy);
void	ft_print_player(t_data *f, int sx, int sy);
void	fr_print_ray(t_data *f, int sx, int sy);



void	ft_size_map(char *str, t_data *f);
void	ft_write_map(char *fic, t_data *f);
void	ft_validate_map(t_data *f);



void	ft_rendermap(t_data *f);




void	aff_map_ctr(t_data *f);
int		*ft_parse_col(char *str);

/*
*  Nico
*/

int		ft_exit(t_info *info);
int		ft_check_arg(int argc, char **argv);
int		ft_perror_exit(char *str_error, t_info *info);

void	ft_read_file(t_info *info);
void	ft_check_map(t_info *info);

#endif
