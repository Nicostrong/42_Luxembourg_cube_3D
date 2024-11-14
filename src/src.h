/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:17:18 by phkevin           #+#    #+#             */
/*   Updated: 2024/11/14 13:00:14 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../lib/libft/libft.h"
# include "../lib/ftprintf/libftprintf.h"
# include "../lib/getnextline/libgetnextline.h"
# include "fcntl.h"
# include "stdio.h"
# include "../lib/minilibx/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <sys/time.h>

/* DEBUG */
# define DEBUG 1

/* Color reset*/
# define NOCOLORS "\033[0m"

/* Color MSG GRAS*/
# define REDG "\033[1;31m"
# define GREENG "\033[1;32m"
# define YELLOWG "\033[1;93m"
# define GOLDG "\033[1;33m"
# define BLUEG "\033[1;34m"
# define MAGENTAG "\033[1;35m"
# define CYANG "\033[1;36m"

/* Color MSG CLIGNOTANTE*/
# define REDC "\033[5;31m"
# define GREENC "\033[5;32m"
# define YELLOWC "\033[5;93m"
# define GOLDC "\033[5;33m"
# define BLUEC "\033[5;34m"
# define MAGENTAC "\033[5;35m"
# define CYANC "\033[5;36m"

/* Project name */
# define TITLE "Cube3D"

/*Path maps*/
# define PMAP "./maps/"

/* Windows size */
# define WIDTH 800 //1920
# define HEIGHT 600 //1080

/*Nombre de texture*/
# define NBTEXTURES 6

/*Configurarion clavier azerty = 1*/
# define ISAZERTY 0

/* Para Mini Map */
# define PRAY 5				// Taille du player
# define LENRAY 500			// Longeur des ray
# define NBRAY 10			// Nombre de rayon
# define RAYECART 10.0		// Angle d'ecart
# define WSCALE 4			// Taille des mures
# define CBLACK "0,0,0"
# define CWHITE "255,255,255"
# define CGREEN "0,255,0"
# define CGREY "112,128,144"

/* Mouse */
# define LEFT_CLIC 1
# define MIDDLE_CLIC 2
# define RIGHT_CLIC 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* FPS */
# define FPS 30
# define FRAMT (1000 / FPS)

/* MOUSE SENS */
# define SENSMOU 1

/* CONSTENTE MATH */
# define PI 3.14

/* DATA */

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
} t_texture_type;

/**
 * Struct: Texture data
 */
typedef struct s_texture
{
	char			*addr;
	int				h;
	int				w;
	t_texture_type 	type;
} t_texture;

/**
 * Struct: Keyboard data
 */
typedef struct s_keyb
{
	int	up;
	int	dow;
	int	lf;
	int	lr;
	int is_azerty;
	int is_press;
} t_keyb;

/**
 * Struct: User
 */
typedef struct s_user
{
	int	coox;							// Position user en X
	int	cooy;							// Position user en Y
	int	dir;							// Orientation user
	int cooxm;							// Coo de la sourie en x
	int cooym;							// Coo de la sourie en y
} t_user;


/**
 * Struct: data
 */
typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*win;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	char		*fic;
	long		lastfram;					// Timer de la derniere frame
	int			gfxno;						// 1 si NO trouvé, 0 sinon
	int			gfxso;						// 1 si SO trouvé, 0 sinon
	int			gfxwe;						// 1 si WE trouvé, 0 sinon
	int			gfxea;						// 1 si EA trouvé, 0 sinon
	int			gfxfloor;					// 1 si FT trouvé, 0 sinon
	int			gfxsky;						// 1 si CT trouvé, 0 sinon
	int			gfxf;						// 1 si F trouvé, 0 sinon
	int			gfxc;						// 1 si C trouvé, 0 sinon
	int			readmap;					// Confirme la lecture de la map
	char		**map;						// Stockage de la map
	int			ymap;						// Heigt map
	int			xmap;						// Weight map
    int			ismapvalid; 				// 1 si valide, 0 sinon
    int			isspawn;      				// 1 si spawn trouvé, 0 sinon
	int			spposx;						// Position spawn en x
	int			spposy;						// Position spawn en y
	t_texture	gfx[NBTEXTURES];
	t_keyb		keyb;
	t_user		userd;
}	t_data;

/*Uniquement utiliser dans render*/
typedef struct	s_pixel
{
	int x;
	int y;
}	t_pixel;


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
int		mouse_move(int x, int y, t_data *f);

 /*
  *	Fonction close app
  */
int	ft_close(t_data *f);
void	ft_errclose(t_data *f);

 /*
  *	Fonction file
  */
void	fic_init(t_data *f, char *str);
int		is_ficexiste(char *fic);

 /*
  * Fonction init mlx
  */
void	ft_init_mlx(t_data *f);

 /*
  * Fonction init
  */
void	init_struct(t_data *f);

 /*
  * Fonction render
  */
void	ft_render(t_data *f);

/*
 * Fonction load texture
 */
void    ft_load_skfl(t_data *f);
void    ft_load_wall(t_data *f);

/*
 * Fonction validate
 */
void    ft_vali(char *fic, t_data *f);
void 	ft_val_para(char *str, t_data *f);

/*
 * Fonction draw
 */
void	ft_pixel_put(t_data *data, int x, int y, int color);
int		ft_get_color(int r, int g, int b);
void	ft_put_circle(t_data *f, int centx, int centy);

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



void    ft_rendermap(t_data *f);




void	aff_map_ctr(t_data *f);
int		*ft_parse_col(char *str);

#endif
