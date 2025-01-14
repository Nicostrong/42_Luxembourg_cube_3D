/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:20:57 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/14 07:45:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3d.h"
#include "../includes/structures.h"
#include "../includes/setting_game.h"
#include "../includes/minimap.h"

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
	ft_minimap(info);
	/*if (DEBUG)
		ft_print_user_data(info);*/
	if (LINUX)
	{
		mlx_hook(info->game->win, 2, 1L << 0, &ft_press_key, info);
		mlx_hook(info->mini->win, 2, 1L << 0, &ft_press_key, info);
	}
	else if (MACOS)
	{
		mlx_hook(info->game->win, 2, 1L << 0, &ft_press_key_mac, info);
		mlx_hook(info->mini->win, 2, 1L << 0, &ft_press_key_mac, info);
	}
	mlx_hook(info->game->win, 6, 1L << 6, &ft_mouse_move, info);
	//mlx_loop_hook(info->mlx, (void *)ft_raycasting, info);
	mlx_loop(info->mlx);
	return (0);
}
