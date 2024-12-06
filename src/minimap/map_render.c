/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:20 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/06 09:29:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"

void	print_fond(t_data *f, int sx, int sy)
{
	t_pixel		pix;
	int			y_stop;
	int			x_stop;

	x_stop = WIDTH - sx;
	y_stop = HEIGHT - sy;
	pix.y = HEIGHT - 1;
	while (pix.y > y_stop)
	{
		pix.x = WIDTH - 1;
		while (pix.x > x_stop)
		{
			ft_pixel_put(f, pix.x , pix.y, ft_get_color(255, 255, 255));
			pix.x--;
		}
		pix.y--;
	}
}


/**
 * reste faire:
 *  - fair defiler la map
 * 	- Save les couleur mini ma dans le header
 *  - Print sawn a finir
 */

void	ft_rendermap(t_data *f)
{
	int sx; 
	int sy;

	sx = (WIDTH / 100 * 20);
	sy = (HEIGHT / 100 * 20);
	//20% de la surface d'affichage
	print_fond(f, WIDTH, HEIGHT);
	ft_print_fond(f, sx, sy);
	//ft_print_wall(f, sx, sy); 
	//ft_print_spawn(f, sx, sy);
	fr_print_ray(f, sx, sy);
	ft_print_player(f, sx, sy);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}