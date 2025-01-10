/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:20:57 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/10 13:23:37 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3d.h"
#include "../includes/structures.h"
#include "../includes/setting_game.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 *	cube_3D
 * </summary>
 *
 * <description>
 *	cube_3D is a 3D game playing with a map. The programm need to be lauching 
 *	with a path to the map. The map need to be *.cub.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">list of integer to sort</param>
 *
 * <return>
 *	0 in success or 1 in error.
 * </return>
 *
 */
int main(int argc, char *argv[])
{
	t_info	*info;

	ft_check_arg(argc, argv);
	info = ft_get_all_info(argv[1]);
	//ft_print_info(info);
	mlx_hook(info->game->win, 17, 0, &ft_exit, info);
	mlx_hook(info->mini->win, 17, 0, &ft_exit, info);
	/*if (DEBUG)
		ft_print_user_data(info);*/
	ft_minimap(info);
	if (LINUX)
		mlx_hook(info->game->win, 2, 1L << 0, &ft_press_key, info);
	else if (MACOS)
		mlx_hook(info->game->win, 2, 1L << 0, &ft_press_key_mac, info);
	mlx_hook(info->game->win, 6, 1L << 6, &ft_mouse_move, info);
	//mlx_loop_hook(info->mlx, (void *)ft_raycasting, info);
	mlx_loop(info->mlx);
	/*
	mlx_mouse_hook(f.win, &mouse_click, &f);
	mlx_hook(f.win, 2, 1L << 0, &pr_key, &f);
	mlx_hook(f.win, 3, 1L << 1, &rl_key, &f);
	mlx_hook(f.win, 6, 1L << 6, &mouse_move, &f);
	mlx_loop_hook(f.mlx, update_key, &f);
	mlx_loop(f.mlx);*/
	return (0);
}
