/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:57:19 by phkevin           #+#    #+#             */
/*   Updated: 2024/10/30 10:55:04 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "src.h" 

/*void	ft_init(t_data *f)
{
    f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, TITLE);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	ft_rendermap(f);
}*/

void	ft_init_mlx(t_data *f)
{
    (void) f;

    f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, TITLE);
	ft_load_wall(f);
	if (f->gfxfloor == 1 && f->gfxsky == 1)
		ft_load_skfl(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	//ft_render(f);
	ft_rendermap(f);
}