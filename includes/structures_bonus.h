/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:04:31 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/23 14:59:14 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

# include <pthread.h>

typedef struct s_thread
{
	pthread_t		t_mini;
	pthread_t		t_game;
	pthread_mutex_t	m_map;			// protection of access map
	pthread_mutex_t	m_user_x;		// protection for position user in x
	pthread_mutex_t	m_user_y;		// protection for position user in y
	pthread_mutex_t	m_user_d;		// protection for rotation user
	pthread_mutex_t	m_stop;		// protection for stop thread
}	t_thread;

/*
 *	Texture struct
 */

typedef struct s_texture
{
	char			*img_path;			//	Path to the image
	int				h;					//	Height of the image
	int				w;					//	Width of the image
	int				bpp;				//	Bits per pixel
	int				size;				//	Size line
	int				endian;				//	Endian
	void			*img;				//	Image
	void			*addr;				//	Address of image
}					t_img;

/*
 *	Animation struct
 */

typedef struct s_anim
{
	int				speed;
	int				chrono;
	int				cur_img;
	int				nb_img;
	void			**array_img;
}					t_anim;

/*
 *	Color struct
 */

typedef struct s_color
{
	int				t;
	int				r;
	int				g;
	int				b;
	int				color;
}					t_color;

/*
 *	Link between char and variable in structure
 */

typedef struct s_info_map
{
	char		*key;			//	Key to select the variable
	t_img		**t_img;		//	Pointer for path of the image
	t_color		**color;		//	Pointer for the color of the image
}				t_info_map;

/*
 *	Structure for windows
 */

typedef struct s_info_windows
{
	int			bpp;			//	bits by pixell
	int			size;			//	size line
	int			endian;			//	endian
	char		*addr;			//	address of image game
	void		*win;			//	windows
	void		*img;			//	img to print
}				t_win;

 /*
  *	Main structure
  */

typedef struct s_info
{
	int			fd;				//	fd file .cub
	int			h;				//	height of map
	int			w;				//	width of map
	int			x;				//	position x of player
	int			y;				//	position y of player
	int			mouse_rot;		//	rotation with mouse mouse
	int			p_nbr;			//	number of player
	int			use_f_img;		//	1 if use floor image, 0 if use color
	int			use_s_img;		//	1 if use sky image, 0 if use color
	int			mini_h;			//	height of the minimap array
	int			mini_w;			//	width of the minimap array
	int			move;			//	bool for changing view
	int			stop;			//	to stop the thread
	int			*colors;		//	all color for a line of minimap
	int			*widths;		//	all widths of minimap
	int			*heights;		//	all heights of minimap
	double		user_deg;		//	orientation of player in radian
	double		user_y;			//	position y of player on map
	double		user_x;			//	position x of player on map.
	char		*map_path;		//	path of the map
	char		*line;			//	line read>
	char		**map;			//	map array
	void		*mlx;			//	mlx api
	t_win		*game;			//	structure window for game
	t_win		*mini;			//	structure window for minimap	
	t_img		*s_img;			//	sky image
	t_img		*f_img;			//	floor image
	t_img		*w_n_img;		//	wall north image
	t_img		*w_e_img;		//	wall east image
	t_img		*w_s_img;		//	wall south image
	t_img		*w_w_img;		//	wall weast image
	t_img		*player;		//	player image
	t_color		*floor_color;	//	floor color
	t_color		*sky_color;		//	sky color
	t_anim		*c_anim;		//	animation of collectable
	t_anim		*d_anim;		//	animation of door
	t_thread	*thread;		//	thread structure
	t_info_map	*info_map;		//	Link between char and variable in structure
}				t_info;

/*
 *	Raycasting struct
 */

typedef struct s_raycasting
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		wall;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		prev_draw_end;
	int		text_x;
	int		color;
	t_img	*texture;
}			t_raycast;

/*
 *	Strucuture fonctions
 */

//	DEBUG

void	ft_print_map(t_info *info);
void	ft_print_info(t_info *info);
void	ft_print_user_data(t_info *info);
void	ft_print_minimap(t_info *info, char **map);

void	ft_init_img(t_info **info);
void	ft_free_info(t_info *info);
void	ft_free_window(t_info *info);

t_info	*ft_init_info(char *path);
t_info	*ft_get_all_info(char *path);

#endif