/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:18:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/24 10:23:27 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_3d_bonus.h"
#include "../../includes/error_bonus.h"
#include "../../includes/setting_game_bonus.h"
#include "../../includes/minimap_bonus.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	t_win	*ft_init_info_win(t_info *info, int w, int h, char *title)
 * </summary>
 *
 * <description>
 * 	ft_init_info_win create a windows structure
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
static t_win	*ft_init_info_win(t_info *info, int w, int h, char *title)
{
	t_win	*windows;

	windows = (t_win *)ft_calloc(1, sizeof(t_win));
	if (!windows)
		ft_perror_exit(E_MALLOC, info);
	windows->win = mlx_new_window(info->mlx, w, h, title);
	if (!windows->win)
		ft_perror_exit(E_WIN, info);
	windows->img = mlx_new_image(info->mlx, w, h);
	if (!windows->img)
		ft_perror_exit(E_IMG, info);
	windows->addr = mlx_get_data_addr(windows->img, &windows->bpp, \
		&windows->size, &windows->endian);
	if (!windows->addr)
		ft_perror_exit(E_ADR, info);
	return (windows);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 * 	void	ft_init_mlx(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_init_mlx initialise the mlx poionter and create the windows for the game 
 * 	and the minimap.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */
void	ft_init_mlx(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_perror_exit(E_MLX, info);
	info->game = ft_init_info_win(info, WIDTH, HEIGHT, TITLE);
	info->mini = ft_init_info_win(info, MINI_W, MINI_H, MINI_TITRE);
}
