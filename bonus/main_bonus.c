/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:20:57 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/24 13:37:23 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3d_bonus.h"
#include "../includes/title_bonus.h"
#include "../includes/setting_game_bonus.h"
#include "../includes/minimap_bonus.h"
#include "../includes/raycasting_bonus.h"

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
	printf(BBLUE B1 RESET);
	printf(BBLUE"⸭"BYELLOW B2 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW B3 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW B4 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW B5 BBLUE"⸭\n"RESET);
	printf(BBLUE"⸭"BYELLOW B6 BBLUE"⸭\n"RESET);
	printf(BBLUE B1 "\n" RESET);
	return ;
}

/**
 * @brief Met à jour les rayons et la minimap.
 * 
 * Cette fonction met à jour l'affichage de la minimap 
 * et exécute le raycasting pour le rendu.
 * 
 * @param info Structure contenant les informations du jeu.
 * @return Retourne toujours 0.
 */
static int	ft_update_ray(t_info *info)
{
	ft_minimap(info);
	ft_raycasting(info);
	return (0);
}

/*
 * <cat>cube_3D</cat>
 *
 * <summary>
 *	cube_3D
 * </summary>
 *&ft_raycastingg with a map. The programm need to be lauching 
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
	ft_minimap(info);
	ft_raycasting(info);
	mlx_hook(info->game->win, 17, 0, &ft_exit, info);
	mlx_hook(info->mini->win, 17, 0, &ft_exit, info);
	mlx_hook(info->game->win, 6, 1L << 6, &ft_mouse_move, info);
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
	mlx_loop_hook(info->mlx, &ft_update_ray, info);
	mlx_loop(info->mlx);
	return (0);
}
