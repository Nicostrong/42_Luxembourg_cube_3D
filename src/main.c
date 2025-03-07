/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:20:57 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/07 17:50:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3d.h"
#include "../includes/title.h"
#include "../includes/setting_game.h"
#include "../includes/raycasting.h"

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 *	void	ft_title(void)
 * </summary>
 *
 * <description>
 *	ft_title print the title of the game on the terminal.
 * </description>
 *
 * <param type="void" name=""></param>
 *
 * <return>
 *	void.
 * </return>
 *
 */
static void	ft_title(void)
{
	printf(BBLUE T1 RESET);
	printf(BBLUE"⸭"BYELLOW T2 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW T3 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW T4 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW T5 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW T6 BBLUE"⸭\n"RESET);
	printf(BBLUE T1 RESET);
	return ;
}

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
int	main(int argc, char *argv[])
{
	t_info	*info;

	ft_check_arg(argc, argv);
	info = ft_get_all_info(argv[1]);
	ft_title();
	ft_print_info(info);
	ft_print_user_data(info);
	if (LINUX)
		mlx_hook(info->game->win, 2, 1L << 0, &ft_press_key, info);
	else if (MACOS)
		mlx_hook(info->game->win, 2, 1L << 0, &ft_press_key_mac, info);
	mlx_loop_hook(info->mlx, &ft_raycasting, info);
	mlx_hook(info->game->win, 17, 0, &ft_exit, info);
	mlx_loop(info->mlx);
	return (0);
}
