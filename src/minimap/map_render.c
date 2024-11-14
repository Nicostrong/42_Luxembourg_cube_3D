/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:20 by phkevin           #+#    #+#             */
/*   Updated: 2024/11/13 10:32:13 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

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
	ft_print_fond(f, sx, sy);
	ft_print_wall(f, sx, sy);
	//ft_print_spawn(f, sx, sy);
	fr_print_ray(f, sx, sy);
	ft_print_player(f, sx, sy);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	//print_fond(f, WIDTH, HEIGHT);
}