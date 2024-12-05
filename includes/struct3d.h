/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:04:31 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/05 09:04:33 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT3D_H
# define STRUCT3D_H

/**
 * Enum: Texture type
 */
typedef enum e_texture_type
{
	WALL_N,
	WALL_S,
	WALL_E,
	WALL_W,
	SKY,
	FLOOR
}	t_texture_type;

/**
 * Struct: Texture data
 */
typedef struct s_texture
{
	char			*addr;
	int				h;
	int				w;
	t_texture_type 	type;
}					t_texture;

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
	t_texture		gfx[NBTEXTURES];
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

typedef struct s_info
{
	int			h;				//	height of map
	int			w;				//	width of map
	int			user_y;			//	position y of player
	int			user_x;			//	position x of player
	int			user_deg;		//	orientation of player
	int			c_fund;			//	nbr of collectables fund
	int			move_nbr;		//	number of move
	int			p_nbr;			//	number of player
	int			c_nbr;			//	number of collectable
	int			img_len;		//	dim of the image (64 x 64)
	char		*map_path;		//	path of the map
	char		**map;			//	map array
	void		*mlx;			//	mlx api
	void		*win;			//	windows
	void		*s_img;			//	sky image
	void		*f_img;			//	floor image
	void		*w_n_img;		//	wall north image
	void		*w_e_img;		//	wall east image
	void		*w_s_img;		//	wall south image
	void		*w_w_img;		//	wall weast image
	t_anim		*c_anim;		//	animation of collectable
}				t_info;

#endif