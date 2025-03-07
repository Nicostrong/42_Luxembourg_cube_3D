/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:04:31 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/03/07 17:59:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

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
	void			*addr;				//	Array of image pixel
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
	int				len;
	char			*path;
	void			**array_img;
}					t_anim;

/*
 *	Color struct
 */

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				t;
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
	int			is_valid;		//	bool valid map
	int			fd;				//	fd file .cub
	int			h;				//	height of map
	int			w;				//	width of map
	int			x;				//	position x of player
	int			y;				//	position y of player
	int			mouse_rot;		//	rotation with mouse mouse
	int			mouse_diff;		//	interval refresh mouse
	int			mouse_lc;		//	last x
	int			p_nbr;			//	number of player
	int			i_nbr;			//	number of item
	int			i_col;			//	number of item collected
	int			use_f_img;		//	1 if use floor image, 0 if use color
	int			use_s_img;		//	1 if use sky image, 0 if use color
	int			mini_h;			//	height of the minimap array
	int			mini_w;			//	width of the minimap array
	int			move;			//	bool for changing view
	int			stop;			//	to stop the thread
	int			*colors;		//	all color for a line of minimap
	int			*widths;		//	all widths of minimap
	int			*heights;		//	all heights of minimap
	int			centx;
	int			centy;
	double		user_deg;		//	orientation of player in radian
	double		user_y;			//	position y of player on map
	double		user_x;			//	position x of player on map.
	char		*map_path;		//	path of the map
	char		*line;			//	line read
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
	t_img		*door;			//	door image
	t_color		*floor_color;	//	floor color
	t_color		*sky_color;		//	sky color
	t_anim		*c_anim;		//	animation of collectable
	t_info_map	*info_map;		//	Link between char and variable in structure
}				t_info;

/*
 *	Raycasting struct
 */

typedef struct s_raycast
{
	double	ray_dir_x;			//	Direction du rayon en X
	double	ray_dir_y;			//	Direction du rayon en Y
	double	dir_x;				//	Direction du joueur en X
	double	dir_y;				//	Direction du joueur en Y
	double	plane_x;			//	Plan de la caméra en X
	double	plane_y;			//	Plan de la caméra en Y
	double	delta_dist_x;		//	Distance entre les intersections en X
	double	delta_dist_y;		//	Distance entre les intersections en Y
	double	side_dist_x;		//	Distance avant la première intersection en X
	double	side_dist_y;		//	Distance avant la première intersection en Y
	double	perp_wall_dist;		//	Distance perpendiculaire à la paroi
	double	step;				//	step of texture maping
	double	tex_pos;			//	position of texture
	int		x;					//	Index de la colonne actuelle
	int		map_x;				//	Position actuelle sur la carte en X
	int		map_y;				//	Position actuelle sur la carte en Y
	int		prev_map_x;			//	Pour détecter un changement de cellule en X
	int		prev_map_y;			//	Pour détecter un changement de cellule en Y
	int		step_x;				//	Direction du pas en X
	int		step_y;				//	Direction du pas en Y
	int		side;				//	Côté de la paroi touché (0 = X, 1 = Y)
	int		wall;				//	Type de mur touché (Nord, Sud, Est, Ouest)
	int		door;				//	Confirme la porte toucher
	int		line_height;		//	Hauteur du mur affiché sur l’écran
	int		draw_start;			//	Point de départ du tracé vertical
	int		draw_end;			//	Point de fin du tracé vertical
	int		prev_draw_end;		//	Pour gérer les interpolations entre rayons
	int		text_x;				//	Coordonnée X sur la texture
	int		text_y_offset;		//	Decalage de Y dans la texture
	int		color;				//	Couleur du mur (si pas de texture)
	char	*base_pixel;		//	pixel de depart
	t_img	*texture;			//	Pointeur vers la texture appliquée
}			t_raycast;

/*
 *	Linkedlist of ray
 */

typedef struct s_ray_list
{
	t_raycast			ray;
	struct s_ray_list	*next;
}						t_lst_ray;

/*
 *	Minimap struct
 */

typedef struct s_minimap
{
	int		x;
	int		y;
	int		h;
	int		w;
	int		index_pxl;
	char	**map;
}			t_mini;

/*
 *	Strucuture functions
 */

void		ft_init_mlx(t_info *info);
void		ft_init_img(t_info *info);
void		ft_free_info(t_info *info);
void		ft_free_window(t_info *info);

t_info		*ft_init_info(char *path);
t_info		*ft_get_all_info(char *path);

t_anim		*ft_init_anim(t_info *info);

#endif