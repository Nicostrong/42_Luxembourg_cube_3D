/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:03:36 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/12/11 09:03:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d.h"
#include "../../includes/structures.h"
#include "../../includes/setting_game.h"
#include "../../includes/error.h"

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