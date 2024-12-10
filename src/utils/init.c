/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:57:19 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/10 11:07:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"
#include "../../includes/error.h"

/*void	ft_init(t_data *f)
{
    f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, TITLE);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	ft_rendermap(f);
}*/

/*void	ft_init_mlx(t_data *f)
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
}*/

void	ft_init_mlx(t_info *info)
{
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, TITLE);
	if (!info->win)
		ft_perror_exit(E_WIN, info);
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img)
		ft_perror_exit(E_IMG, info);
	info->addr = mlx_get_data_addr(info->mlx, &info->bpp, &info->w, &info->endian);
	if (!info->addr)
		ft_perror_exit(E_ADR, info);
	info->mini_win = mlx_new_window(info->mlx, MINI_W, MINI_H, MINI_TITRE);
	if (!info->mini_win)
		ft_perror_exit(E_M_WIN, info);
	info->mini_img = mlx_new_image(info->mlx, MINI_W, MINI_H);
	if (!info->mini_img)
		ft_perror_exit(E_M_IMG, info);
	info->mini_addr = mlx_get_data_addr(info->mlx, &info->bpp, &info->w, &info->endian);
	if (!info->mini_addr)
		ft_perror_exit(E_M_ADR, info);
}