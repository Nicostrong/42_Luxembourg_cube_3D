/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:04:31 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/10 11:04:32 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/**
 * Enum: Texture type
 */
typedef enum e_texture_type
{
	FLOOR,								//	0
	SKY,								//	1
	WALL_N,								//	2 => position player
	WALL_E,								//	3 => position player
	WALL_S,								//	4 => position player
	WALL_W								//	5 => position player
}	t_type_image;

/**
 * Struct: Texture data
 */
typedef struct s_texture
{
	char			*img_path;			//	Path to the image
	int				h;					//	Height of the image
	int				w;					//	Width of the image
	void			*img;				//	Image
	void			*addr;				//	Address of image
	t_type_image 	type;				//	Type of the texture
}					t_img;

/**
 * Struct: Keyboard data
 */
typedef struct s_keyb
{
	int				up;
	int				dow;
	int				lf;
	int				lr;
	int				is_azerty;
	int				is_press;
}					t_keyb;

/**
 * Struct: User
 */
typedef struct s_user
{
	int				coox;				// Position user en X
	int				cooy;				// Position user en Y
	int				dir;				// Orientation user
	int				cooxm;				// Coo de la sourie en x
	int				cooym;				// Coo de la sourie en y
}					t_user;


/**
 * Struct: data
 */
typedef struct s_data
{
	void			*img;
	void			*mlx;
	void			*win;
	void			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	char			*fic;				// path .cub
	long			lastfram;			// Timer de la derniere frame
	int				gfxno;				// 1 si NO trouvé, 0 sinon
	int				gfxso;				// 1 si SO trouvé, 0 sinon
	int				gfxwe;				// 1 si WE trouvé, 0 sinon
	int				gfxea;				// 1 si EA trouvé, 0 sinon
	int				gfxfloor;			// 1 si FT trouvé, 0 sinon
	int				gfxsky;				// 1 si CT trouvé, 0 sinon
	int				gfxf;				// 1 si F trouvé, 0 sinon
	int				gfxc;				// 1 si C trouvé, 0 sinon
	int				readmap;			// Confirme la lecture de la map
	char			**map;				// Stockage de la map
	int				ymap;				// Heigt map
	int				xmap;				// Weight map
    int				ismapvalid; 		// 1 si valide, 0 sinon
    int				isspawn;      		// 1 si spawn trouvé, 0 sinon
	int				spposx;				// Position spawn en x
	int				spposy;				// Position spawn en y
	int				sprot;				// Orientation player E = 0, N = 270, S = 90
	//t_texture		gfx[NBTEXTURES];
	t_keyb			keyb;
	t_user			userd;
}					t_data;

/*Uniquement utiliser dans render*/
typedef struct	s_pixel
{
	int				x;
	int				y;
}					t_pixel;

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
 *	Nico structure for setting game
 */

/*
 *	Color RGB
 */

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
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
  *	Main structure
  */

typedef struct s_info
{
	int			fd;				//	fd file .cub
	int			h;				//	height of map
	int			w;				//	width of map
	int			user_y;			//	position y of player
	int			user_x;			//	position x of player
	int			user_deg;		//	orientation of player
	int			p_nbr;			//	number of player
	int			padding;		//	from -5 to 5 for the player change the position
	int			bpp;			//	bits by pixell
	int			endian;			//	endian
	char		*map_path;		//	path of the map
	char		*line;			//	line read>
	char		**map;			//	map array
	void		*mlx;			//	mlx api
	void		*win;			//	windows
	void		*img;			//	img to print
	void		*addr;			//	address of image game
	void		*mini_win;		//	windows minimap
	void		*mini_img;		//	miniap img
	void		*mini_addr;		//	address of minimap image
	t_img		*s_img;			//	sky image
	t_img		*f_img;			//	floor image
	t_img		*w_n_img;		//	wall north image
	t_img		*w_e_img;		//	wall east image
	t_img		*w_s_img;		//	wall south image
	t_img		*w_w_img;		//	wall weast image
	t_color		*floor_color;	//	floor color
	t_color		*sky_color;		//	sky color
	//t_anim		*c_anim;		//	animation of collectable
	t_info_map	*info_map;		//	Link between char and variable in structure
}				t_info;

/*
 *	Strucuture fonctions
 */

//	DEBUG

void	ft_print_map(t_info *info);
void	ft_print_info(t_info *info);

void	ft_init_img(t_info **info);
void	ft_free_info(t_info *info);
void	ft_free_window(t_info *info);

t_info	*ft_init_info(char *path);
t_info	*ft_get_all_info(char *path);

#endif