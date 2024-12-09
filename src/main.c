/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:20:57 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/09 13:20:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3d.h"
#include "../includes/structures.h"

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
	ft_print_info(info);
	ft_exit(info);
	/*ft_init_mlx(&f);
	mlx_hook(f.win, 17, 0, &ft_close, &f);
	mlx_mouse_hook(f.win, &mouse_click, &f);
	mlx_hook(f.win, 2, 1L << 0, &pr_key, &f);
	mlx_hook(f.win, 3, 1L << 1, &rl_key, &f);
	mlx_hook(f.win, 6, 1L << 6, &mouse_move, &f);
	mlx_loop_hook(f.mlx, update_key, &f);
	mlx_loop(f.mlx);*/
	return (0);
}